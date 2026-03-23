import React from 'react';

const ValveDisplay = ({ cosVal = 1.0, sinVal = 0.0 }) => {
  const radius = 80;
  const center = 100;
  
  const radians = Math.atan2(sinVal, cosVal);
  let degrees = radians * (180 / Math.PI);
  if (degrees < 0) degrees += 360;

  const percentOpen = ((degrees / 360) * 100).toFixed(1);

  const targetX = center + radius * cosVal;
  const targetY = center - radius * sinVal;

  return (
    <div className="flex flex-col items-center justify-center p-8 bg-[#2c3e50] rounded-xl shadow-lg">
      <h2 className="text-white text-xl font-bold mb-4">Static Valve Monitor</h2>
      
      <svg width="200" height="200" viewBox="0 0 200 200">
        {/* Outer Circle */}
        <circle 
          cx={center} 
          cy={center} 
          r={radius} 
          fill="none" 
          stroke="#ecf0f1" 
          strokeWidth="5" 
        />
        
        {/* Indicator Line */}
        <line 
          x1={center} 
          y1={center} 
          x2={targetX} 
          y2={targetY} 
          stroke="#e74c3c" 
          strokeWidth="8" 
          strokeLinecap="round"
          className="transition-all duration-500 ease-in-out"
        />
        
        {/* Center Pivot Point */}
        <circle cx={center} cy={center} r={4} fill="#ecf0f1" />
      </svg>

      <div className="mt-6 text-center">
        <p className="text-[#ecf0f1] text-lg">Angle: {degrees.toFixed(1)}°</p>
        <p className="text-[#ecf0f1] text-xl font-bold mt-2">Valve Open: {percentOpen}%</p>
      </div>
    </div>
  );
};

export default ValveDisplay;