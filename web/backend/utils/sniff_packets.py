import time
from scapy.all import sniff
import threading

packets = []
lock = threading.Lock()

def packet_callback(pkt):
    if pkt.haslayer("TCP"):
        if pkt["TCP"].dport == 1883 or pkt["TCP"].sport == 1883:
            with lock:
                packets.append(pkt.summary())

                # keep last 50
                if len(packets) > 50:
                    packets.pop(0)

def start_sniffing():
    print("Starting sniffing on port 1883")
    sniff(filter="tcp port 1883", prn=packet_callback, store=False)

def reset_packets():
    while True:
        time.sleep(30)
        with lock:
            packets.clear()

def get_packets():
    return packets

def sniff_packets():

    threading.Thread(target=start_sniffing, daemon=True).start()
    threading.Thread(target=reset_packets, daemon=True).start()