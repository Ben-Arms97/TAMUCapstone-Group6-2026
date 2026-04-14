import json
import threading
import time
from datetime import datetime

import paho.mqtt.client as mqtt

class PacketSniffer():
    def __init__(self, mqtt_host, mqtt_port, mqtt_topics, handle_incoming_message=None):
        super().__init__()

        self.packets = []
        self.lock = threading.Lock()

        self.MQTT_HOST = mqtt_host
        self.MQTT_PORT = mqtt_port
        self.MQTT_TOPICS = mqtt_topics

        self.handle_incoming_message = handle_incoming_message

    def _on_connect(self, client, userdata, flags, reason_code, properties=None):
        print(f"Connected to MQTT broker with code {reason_code}")
        for topic, qos in self.MQTT_TOPICS:
            client.subscribe(topic, qos=qos)
            print(f"Subscribed to {topic}")

    def _on_message(self, client, userdata, msg):
        if(self.handle_incoming_message):
            self.handle_incoming_message(msg)
        
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

        with self.lock:
            self.packets.append(packet_info)
            if len(self.packets) > 50:
                self.packets.pop(0)

    def _reset_packets(self):
        while True:
            time.sleep(30)
            with self.lock:
                self.packets.clear()

    def _start_mqtt_listener(self):
        client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
        client.on_connect = self._on_connect
        client.on_message = self._on_message

        client.connect(self.MQTT_HOST, self.MQTT_PORT, 60)
        client.loop_forever()

    def get_captured_packets(self):
        with self.lock:
            return list(self.packets)
        
    def sniff_packets(self):
        threading.Thread(target=self._start_mqtt_listener, daemon=True).start()
        threading.Thread(target=self._reset_packets, daemon=True).start()
