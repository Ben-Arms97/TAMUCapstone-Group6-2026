import React from "react";

interface ValveDisplayProps {
    angle: number;
    size?: number;
    isLive?: boolean;
}

export const ValveDisplay: React.FC<ValveDisplayProps> = ({
    angle,
    size = 280,
    isLive,
}) => {
    const safeAngle = Number.isFinite(angle) ? angle : 0;

    const displayAngle = Math.max(0, safeAngle);

    const normalizedAngle = ((displayAngle % 360) + 360) % 360;

    const center = size / 2;
    const radius = size * 0.34;

    const percentOpen = (normalizedAngle / 360) * 100;

    const turns = Math.floor(displayAngle / 360);

    return (
        <div className="flex h-full w-full flex-col p-6 pt-2">
            <div className="flex flex-1 items-center justify-center">
                <svg
                    width={size}
                    height={size}
                    viewBox={`0 0 ${size} ${size}`}
                    className="max-w-full"
                    aria-label={`Valve angle ${displayAngle.toFixed(
                        1
                    )} degrees, current position ${normalizedAngle.toFixed(
                        1
                    )} degrees, ${percentOpen.toFixed(1)} percent open`}
                    role="img"
                >
                    <circle
                        cx={center}
                        cy={center}
                        r={radius + 10}
                        fill="none"
                        stroke="#e2e8f0"
                        strokeWidth="10"
                    />

                    <circle
                        cx={center}
                        cy={center}
                        r={radius}
                        fill="none"
                        stroke="#cbd5e1"
                        strokeWidth="4"
                    />

                    <g
                        style={{
                            transform: `rotate(${-normalizedAngle}deg)`,
                            transformOrigin: `${center}px ${center}px`,
                            transition: "transform 0.5s ease",
                        }}
                    >
                        <line
                            x1={center}
                            y1={center}
                            x2={center + radius}
                            y2={center}
                            stroke="#f97316"
                            strokeWidth="6"
                            strokeLinecap="round"
                        />
                    </g>

                    <circle cx={center} cy={center} r={7} fill="#e2e8f0" />
                </svg>
            </div>

            <div
                className={`mt-2 grid ${displayAngle >= 360 ? "grid-cols-3" : "grid-cols-2"
                    } gap-2 rounded-xl bg-slate-50 px-3 py-2 ${isLive ? "text-emerald-500" : "text-amber-600"
                    }`}
            >
                <div className="text-center">
                    <p className="text-[10px] font-semibold uppercase tracking-wide text-slate-500">
                        Angle
                    </p>
                    <p className="mt-0.5 text-xl font-semibold">
                        {displayAngle.toFixed(1)}°
                    </p>
                </div>

                <div className="text-center">
                    <p className="text-[10px] font-semibold uppercase tracking-wide text-slate-500">
                        Position
                    </p>
                    <p className="mt-0.5 text-xl font-semibold">
                        {normalizedAngle.toFixed(1)}°
                    </p>
                </div>

                {displayAngle >= 360 && (
                    <div className="text-center">
                        <p className="text-[10px] font-semibold uppercase tracking-wide text-slate-500">
                            Turns
                        </p>
                        <p className="mt-0.5 text-xl font-semibold">{turns}</p>
                    </div>
                )}
            </div>
        </div>
    );
};