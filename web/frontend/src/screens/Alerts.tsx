import React from "react";

export default function AlertsPage() {
    const alerts = [
        {
            id: 1,
            email: "operator@bray.com",
            minimum: "25°",
            maximum: "120°",
            specific: "-",
        },
        {
            id: 2,
            email: "qa@bray.com",
            minimum: "-",
            maximum: "150°",
            specific: "90°",
        },
        {
            id: 3,
            email: "maintenance@bray.com",
            minimum: "15°",
            maximum: "-",
            specific: "-",
        },
    ];

    return (
        <div className="mx-auto max-w-7xl space-y-6 px-6 py-8">
            <div>
                <h1 className="text-3xl font-bold text-gray-900">Alerts</h1>
                <p className="mt-1 text-sm text-gray-500">
                    Configure email notifications for valve angle thresholds.
                </p>
            </div>

            <div className="grid gap-6 lg:grid-cols-[1.1fr_0.9fr]">
                <div className="rounded-2xl border border-gray-200 bg-white p-6 shadow-sm">
                    <div className="mb-6">
                        <h2 className="text-xl font-semibold text-gray-900">
                            Create Alert
                        </h2>
                        <p className="mt-1 text-sm text-gray-500">
                            A user can enter any combination of minimum, maximum,
                            or specific angle thresholds.
                        </p>
                    </div>

                    <div className="space-y-5">
                        <div>
                            <label className="text-sm font-medium text-gray-700">
                                Email
                            </label>
                            <input
                                type="email"
                                value="alerts@bray.com"
                                readOnly
                                className="mt-2 w-full rounded-xl border border-gray-200 bg-gray-50 px-4 py-3 text-sm"
                            />
                        </div>

                        <div className="grid gap-4 md:grid-cols-3">
                            <div>
                                <label className="text-sm font-medium text-gray-700">
                                    Minimum Angle
                                </label>
                                <div className="relative mt-2">
                                    <input
                                        type="text"
                                        value="25"
                                        readOnly
                                        className="w-full rounded-xl border border-gray-200 bg-gray-50 px-4 py-3 pr-10 text-sm"
                                    />
                                    <span className="absolute right-4 top-1/2 -translate-y-1/2 font-semibold text-gray-400">
                                        °
                                    </span>
                                </div>
                            </div>

                            <div>
                                <label className="text-sm font-medium text-gray-700">
                                    Maximum Angle
                                </label>
                                <div className="relative mt-2">
                                    <input
                                        type="text"
                                        value="120"
                                        readOnly
                                        className="w-full rounded-xl border border-gray-200 bg-gray-50 px-4 py-3 pr-10 text-sm"
                                    />
                                    <span className="absolute right-4 top-1/2 -translate-y-1/2 font-semibold text-gray-400">
                                        °
                                    </span>
                                </div>
                            </div>

                            <div>
                                <label className="text-sm font-medium text-gray-700">
                                    Specific Angle
                                </label>
                                <div className="relative mt-2">
                                    <input
                                        type="text"
                                        value="90"
                                        readOnly
                                        className="w-full rounded-xl border border-gray-200 bg-gray-50 px-4 py-3 pr-10 text-sm"
                                    />
                                    <span className="absolute right-4 top-1/2 -translate-y-1/2 font-semibold text-gray-400">
                                        °
                                    </span>
                                </div>
                            </div>
                        </div>

                        <div className="rounded-xl border border-gray-200 bg-gray-50 p-4">
                            <p className="text-sm font-medium text-gray-700">
                                Trigger Preview
                            </p>
                            <p className="mt-1 text-sm text-gray-500">
                                Email will be sent if the valve angle goes below{" "}
                                <span className="font-semibold text-gray-800">
                                    25°
                                </span>
                                , above{" "}
                                <span className="font-semibold text-gray-800">
                                    120°
                                </span>
                                , or exactly matches{" "}
                                <span className="font-semibold text-gray-800">
                                    90°
                                </span>
                                .
                            </p>
                        </div>

                        <div className="flex justify-end">
                            <button className="rounded-xl bg-red-600 px-5 py-2.5 text-sm font-semibold text-white hover:bg-red-700">
                                + Add Alert
                            </button>
                        </div>
                    </div>
                </div>

                <div className="rounded-2xl border border-gray-200 bg-white p-6 shadow-sm">
                    <div className="flex items-center justify-between">
                        <h2 className="text-lg font-semibold text-gray-900">
                            Active Alerts
                        </h2>
                        <span className="rounded-full bg-gray-100 px-3 py-1 text-sm text-gray-600">
                            3 total
                        </span>
                    </div>

                    <div className="mt-5 space-y-4">
                        {alerts.map((alert) => (
                            <div
                                key={alert.id}
                                className="rounded-xl border border-gray-200 bg-gray-50 p-4"
                            >
                                <p className="text-sm font-medium text-gray-800">
                                    {alert.email}
                                </p>

                                <div className="mt-3 grid grid-cols-3 gap-3 text-sm">
                                    <div className="rounded-lg border bg-white px-3 py-2">
                                        <p className="text-xs text-gray-500">
                                            Minimum
                                        </p>
                                        <p className="font-semibold text-gray-900">
                                            {alert.minimum}
                                        </p>
                                    </div>

                                    <div className="rounded-lg border bg-white px-3 py-2">
                                        <p className="text-xs text-gray-500">
                                            Maximum
                                        </p>
                                        <p className="font-semibold text-gray-900">
                                            {alert.maximum}
                                        </p>
                                    </div>

                                    <div className="rounded-lg border bg-white px-3 py-2">
                                        <p className="text-xs text-gray-500">
                                            Specific
                                        </p>
                                        <p className="font-semibold text-gray-900">
                                            {alert.specific}
                                        </p>
                                    </div>
                                </div>
                            </div>
                        ))}
                    </div>
                </div>
            </div>
        </div>
    );
}