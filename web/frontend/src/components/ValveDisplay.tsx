import React from "react";

interface ValveDisplayProps {
    angle: number;
    size?: number;
}

export const ValveDisplay: React.FC<ValveDisplayProps> = ({
    angle,
    size = 280,
}) => {
    const clampedAngle = Math.max(0, Math.min(angle, 360));
    const center = size / 2;
    const radius = size * 0.34;

    const radians = (clampedAngle * Math.PI) / 180;
    const lineX = center + radius * Math.cos(radians);
    const lineY = center - radius * Math.sin(radians);

    const percentOpen = (clampedAngle / 360) * 100;

    return (
        <div className="flex h-full w-full flex-col rounded-3xl bg-white p-6 shadow-sm">
            <div className="flex flex-1 items-center justify-center">
                <svg
                    width={size}
                    height={size}
                    viewBox={`0 0 ${size} ${size}`}
                    className="max-w-full"
                    aria-label={`Valve angle ${clampedAngle.toFixed(1)} degrees, ${percentOpen.toFixed(1)} percent open`}
                    role="img"
                >
                    {/* soft outer ring */}
                    <circle
                        cx={center}
                        cy={center}
                        r={radius + 10}
                        fill="none"
                        stroke="#e2e8f0"
                        strokeWidth="10"
                    />

                    {/* main gauge ring */}
                    <circle
                        cx={center}
                        cy={center}
                        r={radius}
                        fill="none"
                        stroke="#cbd5e1"
                        strokeWidth="4"
                    />

                    {/* needle */}
                    <line
                        x1={center}
                        y1={center}
                        x2={lineX}
                        y2={lineY}
                        stroke="#f97316"
                        strokeWidth="6"
                        strokeLinecap="round"
                    />

                    {/* center hub */}
                    <circle cx={center} cy={center} r={7} fill="#e2e8f0" />
                </svg>
            </div>

            <div className="mt-2 grid grid-cols-2 gap-2 rounded-xl bg-slate-50 px-3 py-2">
                <div className="text-center">
                    <p className="text-[10px] font-semibold uppercase tracking-wide text-slate-500">
                        Angle
                    </p>
                    <p className="mt-0.5 text-xl font-semibold text-emerald-500">
                        {clampedAngle.toFixed(1)}°
                    </p>
                </div>

                <div className="text-center">
                    <p className="text-[10px] font-semibold uppercase tracking-wide text-slate-500">
                        % Open
                    </p>
                    <p className="mt-0.5 text-xl font-semibold text-emerald-500">
                        {percentOpen.toFixed(1)}%
                    </p>
                </div>
            </div>
        </div>
    );
};