from flask import Flask, request, jsonify
from flask_cors import CORS
import os
from dotenv import load_dotenv

from database import db, Event

load_dotenv()

def create_app():
    app = Flask(__name__)
    
    app.config['SQLALCHEMY_DATABASE_URI'] = os.getenv('POSTGRESQL_CONNECTION_STRING')

    CORS(app, supports_credentials=True)

    with app.app_context():
        db.init_app(app)
        db.create_all()

    return app

def register_routes(app):
    @app.route("/")
    def hello_world():
        return "Hello, World!"
    
    @app.route('/event', methods=['GET'])
    def get_events():
        data = []

        events = Event.query.all()
        for event in events:
            event_data = {
                'id': event.id,
                'angle': event.angle,
                'battery': event.battery,
                'timestamp': event.timestamp
            }
            data.append(event_data)

        return jsonify({'events': data}), 200
    
    @app.route("/event", methods=["POST"])
    def post_event():
        data = request.get_json(force=True)

        angle = data.get("angle")
        battery = data.get("battery")

        if angle is None or battery is None:
            return jsonify({"error": "angle and battery are required"}), 400

        new_event = Event(
            angle=angle,
            battery=battery,
        )

        db.session.add(new_event)
        db.session.commit()

        return jsonify({
            "id": str(new_event.id),
            "angle": new_event.angle,
            "battery": new_event.battery,
            "timestamp": new_event.timestamp
        }), 201
    
app = create_app()
register_routes(app)