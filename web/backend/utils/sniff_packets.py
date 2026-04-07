import json
import threading
import time
from datetime import datetime

import paho.mqtt.client as mqtt

packets = []
lock = threading.Lock()

MQTT_HOST = "mqtt"
MQTT_PORT = 1883
MQTT_TOPICS = [("#", 0)]


def on_connect(client, userdata, flags, reason_code, properties=None):
    print(f"Connected to MQTT broker with code {reason_code}")
    for topic, qos in MQTT_TOPICS:
        client.subscribe(topic, qos=qos)
        print(f"Subscribed to {topic}")


def on_message(client, userdata, msg):
    payload_bytes = bytes(msg.payload)

    try:
        payload_text = payload_bytes.decode("utf-8", errors="replace")
    except Exception:
        payload_text = None

    packet_info = {
        "timestamp": datetime.utcnow().isoformat() + "Z",
        "topic": msg.topic,
        "qos": msg.qos,
        "retain": msg.retain,
        "payload_hex": payload_bytes.hex(),
        "payload_bytes": list(payload_bytes),
        "payload_text": payload_text,
    }

    if payload_text:
        stripped = payload_text.strip()
        if stripped.startswith("{") or stripped.startswith("["):
            try:
                packet_info["payload_json"] = json.loads(stripped)
            except Exception:
                pass

    with lock:
        packets.append(packet_info)
        if len(packets) > 50:
            packets.pop(0)


def reset_packets():
    while True:
        time.sleep(30)
        with lock:
            packets.clear()


def get_captured_packets():
    with lock:
        return list(packets)


def start_mqtt_listener():
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect(MQTT_HOST, MQTT_PORT, 60)
    client.loop_forever()


def sniff_packets():
    threading.Thread(target=start_mqtt_listener, daemon=True).start()
    threading.Thread(target=reset_packets, daemon=True).start()
