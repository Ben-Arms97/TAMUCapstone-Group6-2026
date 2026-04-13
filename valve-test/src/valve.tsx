import React, { useState, useEffect } from 'react';
import mqtt from 'mqtt';

const MQTT_URL = 'ws://18.119.164.92:8083'; 
const TOPIC = 'sensors/39-32-30-31-79-30-6f-02/port/1';

interface ValveDisplayProps {
  cosVal: number;
  sinVal: number;
  size?: number;
}

const ValveDisplay: React.FC<ValveDisplayProps> = ({ cosVal, sinVal, size = 400 }) => {
  const center = size / 2;
  const radius = size * 0.4;

  const radians = Math.atan2(sinVal, cosVal);
  let degrees = radians * (180 / Math.PI);
  
  if (degrees < 0) degrees += 360;
  
  const percentOpen = (degrees / 360) * 100;

  const lineX = center + radius * cosVal;
  const lineY = center - radius * sinVal;

  return (
    <div className="flex flex-col items-center justify-center p-8 bg-[#2c3e50] rounded-xl shadow-2xl text-white font-sans">
      <h2 className="mb-4 text-xl font-bold">Static Valve Monitor</h2>
      
      <svg width={size} height={size} className="drop-shadow-lg">
        {}
        <circle
          cx={center}
          cy={center}
          r={radius}
          fill="none"
          stroke="#ecf0f1"
          strokeWidth="5"
        />
        
        {}
        <line
          x1={center}
          y1={center}
          x2={lineX}
          y2={lineY}
          stroke="#e74c3c"
          strokeWidth="8"
          strokeLinecap="round"
        />
        
        {}
        <circle cx={center} cy={center} r={6} fill="#ecf0f1" />
      </svg>

      <div className="mt-6 space-y-2 text-center">
        <p className="text-2xl font-mono">
          Angle: <span className="text-emerald-400">{degrees.toFixed(1)}°</span>
        </p>
        <p className="text-2xl font-mono">
          Valve Open: <span className="text-emerald-400">{percentOpen.toFixed(1)}%</span>
        </p>
      </div>
    </div>
  );
};


export default function App() {
  return (
    <div className="min-h-screen bg-gray-900 flex items-center justify-center">
      <ValveDisplay cosVal={1.0} sinVal={0.0} />
    </div>
  );
}

const ValveMonitor: React.FC = () => {
  const [angle, setAngle] = useState(0);

  useEffect(() => {
    const client = mqtt.connect(MQTT_URL);

    client.on('connect', () => {
      console.log('Connected to MQTT via WebSockets');
      client.subscribe(TOPIC);
    });

    client.on('message', (topic, payload) => {
      if (topic === TOPIC && payload.length >= 2) {
        // Convert 2 bytes to a 16-bit degree value (0-360)
        const receivedDegrees = (payload[0] << 8) | payload[1];
        setAngle(receivedDegrees % 360);
      }
    });

    return () => { client.end(); };
  }, []);

  // Convert degrees to cos/sin for the visualizer
  const radians = (angle * Math.PI) / 180;
  const cosVal = Math.cos(radians);
  const sinVal = Math.sin(radians);

  return (
    <div className="p-10 bg-slate-900 min-h-screen flex items-center justify-center">
        {/* Pass these to the ValveDisplay component from before */}
        <ValveDisplay cosVal={cosVal} sinVal={sinVal} />
    </div>
  );
};