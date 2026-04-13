import React, { useState } from 'react';

// --- VALVE COMPONENT ---
const ValveDisplay: React.FC<{ angle: number; size?: number }> = ({ angle, size = 400 }) => {
  const center = size / 2;
  const radius = size * 0.4;

  // Math logic for the needle position
  const radians = (angle * Math.PI) / 180;
  const lineX = center + radius * Math.cos(radians);
  const lineY = center - radius * Math.sin(radians);
  
  // Calculate percentage based on 360 degrees
  const percentOpen = (angle / 360) * 100;

  return (
    <div className="flex flex-col items-center justify-center p-8 bg-[#2c3e50] rounded-3xl shadow-2xl text-white">
      <h2 className="mb-6 text-2xl font-bold tracking-tight">Valve UI Test</h2>
      
      <svg width={size} height={size} className="drop-shadow-2xl">
        {/* Outer Housing */}
        <circle cx={center} cy={center} r={radius} fill="none" stroke="#34495e" strokeWidth="12" />
        <circle cx={center} cy={center} r={radius} fill="none" stroke="#ecf0f1" strokeWidth="4" />
        
        {/* The Needle */}
        <line
          x1={center}
          y1={center}
          x2={lineX}
          y2={lineY}
          stroke="#e74c3c"
          strokeWidth="8"
          strokeLinecap="round"
        />
        
        {/* Center Hub */}
        <circle cx={center} cy={center} r={8} fill="#ecf0f1" />
      </svg>

      <div className="mt-8 grid grid-cols-2 gap-8 text-center">
        <div>
          <p className="text-sm uppercase text-slate-400 font-bold">Angle</p>
          <p className="text-3xl font-mono text-emerald-400">{angle.toFixed(1)}°</p>
        </div>
        <div>
          {/* Changed "Capacity" to "% Open" below */}
          <p className="text-sm uppercase text-slate-400 font-bold">% Open</p>
          <p className="text-3xl font-mono text-emerald-400">{percentOpen.toFixed(1)}%</p>
        </div>
      </div>
    </div>
  );
};

// --- MAIN APP ---
export default function App() {
  const [angle, setAngle] = useState<number>(0);

  return (
    <div className="min-h-screen bg-slate-950 flex flex-col items-center justify-center p-4">
      {/* TEST CONTROLS */}
      <div className="mb-8 p-6 bg-slate-900 rounded-xl border border-slate-800 flex flex-col items-center gap-4">
        <label className="text-emerald-400 font-bold">Manual Test Slider:</label>
        <input 
          type="range" 
          min="0" 
          max="360" 
          value={angle} 
          onChange={(e) => setAngle(parseInt(e.target.value))}
          className="w-64 accent-emerald-500 cursor-pointer"
        />
        <div className="text-slate-500 text-xs italic">Moving this updates the % Open display</div>
      </div>
      
      <ValveDisplay angle={angle} />
    </div>
  );
}