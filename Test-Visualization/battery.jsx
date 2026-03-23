import React from 'react';

const BatteryDisplay = ({ percentage = 75 }) => {
  const level = Math.max(0, Math.min(100, percentage));
  
  const color = level <= 20 ? '#e74c3c' : '#2ecc71';

  return (
    <div className="flex flex-col items-center justify-center p-8 bg-[#2c3e50] rounded-xl shadow-lg">
      <h2 className="text-white text-xl font-bold mb-4">LoRaWAN Battery Monitor</h2>
      
      <div className="relative flex items-center">
        {/* Main Battery Body */}
        <div className="w-52 h-24 border-4 border-[#ecf0f1] rounded-md p-1 relative flex items-center">
          {/* Inner Fill */}
          <div 
            className="h-full transition-all duration-500 ease-out rounded-sm"
            style={{ 
              width: `${level}%`, 
              backgroundColor: color 
            }}
          />
        </div>

        <div className="w-3 h-12 bg-[#ecf0f1] rounded-r-md" />
      </div>

      <p className="mt-4 text-white text-lg font-semibold">
        Battery: {level}%
      </p>
    </div>
  );
};

export default BatteryDisplay;