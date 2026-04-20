from flask import Flask, request, jsonify
from flask_cors import CORS
import os
from datetime import datetime, timezone
import json
from dotenv import load_dotenv

from utils.PacketSniffer import PacketSniffer
from utils.ClearDatabase import start_truncate_job
from database import db, Event

load_dotenv()

MQTT_HOST = "mqtt"
MQTT_PORT = 1883
MQTT_TOPIC = os.getenv("MQTT_TOPIC")

MESSAGE_CLEAR_INTERVAL = float(os.getenv('MESSAGE_CLEAR_INTERVAL'))

test_packet_sniffer = None
packet_sniffer = None


def create_app():
    app = Flask(__name__)
    app.config["SQLALCHEMY_DATABASE_URI"] = os.getenv(
        "POSTGRESQL_CONNECTION_STRING")

    CORS(app, supports_credentials=True)

    with app.app_context():
        db.init_app(app)
        db.create_all()

    return app


def setup_packet_sniffer(app):
    global test_packet_sniffer, packet_sniffer

    def handle_packets(msg):
        payload_bytes = bytes(msg.payload)
        payload_bytes_list = list(payload_bytes)

        try:
            payload_text = payload_bytes.decode("utf-8", errors="replace")
        except Exception:
            payload_text = None

        packet_info = {
            "timestamp": datetime.now(timezone.utc).isoformat().replace("+00:00", "Z"),
            "topic": msg.topic,
            "qos": msg.qos,
            "retain": msg.retain,
            "payload_hex": payload_bytes.hex(),
            "payload_bytes": payload_bytes_list,
            "payload_text": payload_text,
        }

        if payload_text:
            stripped = payload_text.strip()
            if stripped.startswith("{") or stripped.startswith("["):
                try:
                    packet_info["payload_json"] = json.loads(stripped)
                except Exception:
                    pass

        try:
            angle = int.from_bytes(payload_bytes[:2], byteorder='big', signed=True) # big endian notation: byte[0] MSB and byte[1] LSB, two's complement for negative numbers

            with app.app_context():
                new_event = Event(angle=angle, battery=0)
                db.session.add(new_event)
                db.session.commit()

        except Exception as error:
            with app.app_context():
                db.session.rollback()
            print(f"Error processing data: {error}")

        return packet_info

    test_packet_sniffer = PacketSniffer(MQTT_HOST, MQTT_PORT, [("#", 0)])
    test_packet_sniffer.sniff_packets()

    packet_sniffer = PacketSniffer(
        MQTT_HOST,
        MQTT_PORT,
        [(MQTT_TOPIC, 0)],
        handle_packets,
    )
    packet_sniffer.sniff_packets()


def register_routes(app):
    @app.route("/")
    def hello_world():
        return "Hello, World!"

    @app.route("/event", methods=["GET"])
    def get_events():
        events = Event.query.all()
        data = [
            {
                "id": event.id,
                "angle": event.angle,
                "battery": event.battery,
                "timestamp": event.timestamp,
            }
            for event in events
        ]
        return jsonify({"events": data}), 200

    @app.route("/event", methods=["POST"])
    def post_event():
        data = request.get_json(force=True)

        angle = data.get("angle")
        battery = data.get("battery")

        if angle is None or battery is None:
            return jsonify({"error": "angle and battery are required"}), 400

        new_event = Event(angle=angle, battery=battery)
        db.session.add(new_event)
        db.session.commit()

        return jsonify({
            "id": str(new_event.id),
            "angle": new_event.angle,
            "battery": new_event.battery,
            "timestamp": new_event.timestamp
        }), 201

    @app.route("/packets")
    def log_packets():
        if test_packet_sniffer is None:
            return jsonify({"error": "test packet sniffer not initialized"}), 500
        return jsonify(list(test_packet_sniffer.get_captured_packets()))

    @app.route("/prodpackets")
    def log_prod_packets():
        if packet_sniffer is None:
            return jsonify({"error": "prod packet sniffer not initialized"}), 500
        return jsonify(list(packet_sniffer.get_captured_packets()))


app = create_app()
setup_packet_sniffer(app)
register_routes(app)
start_truncate_job(app, db, MESSAGE_CLEAR_INTERVAL)