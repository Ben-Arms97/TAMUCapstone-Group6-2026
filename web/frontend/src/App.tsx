import { useMemo, useState } from "react";
import { useQuery } from "@tanstack/react-query";

type EventItem = {
  id: string;
  angle: number;
  battery: number;
  timestamp: string;
};

type EventsResponse = {
  events: EventItem[];
};

function formatTime(timestamp: string) {
  return new Date(timestamp).toLocaleTimeString([], {
    hour: "numeric",
    minute: "2-digit",
    second: "2-digit",
  });
}

function formatDate(timestamp: string) {
  return new Date(timestamp).toLocaleDateString();
}

function getBatteryColor(battery: number) {
  if (battery < 20) return "text-red-500";
  if (battery < 50) return "text-amber-500";
  return "text-gray-600";
}

function getBatteryLabel(battery: number) {
  if (battery < 20) return "Low";
  if (battery < 50) return "Medium";
  return "Good";
}

function LoadingState() {
  return (
    <div className="rounded-2xl border border-gray-200 bg-white overflow-hidden">
      <div className="grid grid-cols-3 border-b border-gray-200 bg-gray-50 px-5 py-3 text-xs font-medium text-gray-500">
        <span>Timestamp</span>
        <span className="text-center">Angle</span>
        <span className="text-right">Battery</span>
      </div>

      <div className="animate-pulse">
        {[...Array(6)].map((_, i) => (
          <div
            key={i}
            className="grid grid-cols-3 items-center border-b border-gray-100 px-5 py-4 last:border-b-0"
          >
            <div className="space-y-2">
              <div className="h-4 w-28 rounded bg-gray-200" />
              <div className="h-3 w-20 rounded bg-gray-100" />
            </div>
            <div className="mx-auto h-4 w-12 rounded bg-gray-200" />
            <div className="ml-auto h-4 w-12 rounded bg-gray-200" />
          </div>
        ))}
      </div>
    </div>
  );
}

function ErrorState() {
  return (
    <div className="flex items-center gap-2 rounded-2xl border border-red-100 bg-red-50 px-4 py-3 text-sm text-red-600">
      <span>⚠️</span>
      <span>Failed to load events. Please try again.</span>
    </div>
  );
}

function EmptyState() {
  return (
    <div className="flex flex-col items-center justify-center rounded-2xl border border-dashed border-gray-200 bg-white py-12 text-sm text-gray-500">
      <span className="font-medium text-gray-700">No events yet</span>
      <span className="mt-1 text-xs text-gray-400">
        Incoming valve data will appear here
      </span>
    </div>
  );
}

function App() {
  const [selectedEvent, setSelectedEvent] = useState<EventItem | null>(null);

  const { isPending: eventsLoading, isError: eventsError, data } = useQuery<EventsResponse>({
    queryKey: ["events"],
    queryFn: async () => {
      const res = await fetch("http://localhost:5000/event");
      if (!res.ok) {
        throw new Error(`Request failed with status ${res.status}`);
      }
      return res.json();
    },
    refetchInterval: 5000,
  });

  const events = useMemo(() => {
    return [...(data?.events ?? [])].sort(
      (a, b) =>
        new Date(b.timestamp).getTime() - new Date(a.timestamp).getTime()
    );
  }, [data]);

  return (
    <div className="h-full bg-gray-50 px-12 py-10 ">
      <div className="mx-auto flex max-w-7xl flex-col gap-6">
        <div className="grid grid-cols-1 gap-6 lg:grid-cols-2">
          <div className="flex min-h-55 items-center justify-center rounded-2xl border border-gray-200 bg-white">
            <p className="text-sm text-gray-400">Position Visualization</p>
          </div>

          <div className="rounded-2xl border border-gray-200 bg-white p-8">
            <p className="mb-5 text-base font-semibold text-gray-800">
              Position Details
            </p>

            {selectedEvent ? (
              <div className="grid grid-cols-1 gap-4 sm:grid-cols-3">
                <div className="rounded-xl bg-gray-50 px-4 py-3">
                  <p className="text-xs font-medium uppercase tracking-wide text-gray-400">
                    Timestamp
                  </p>
                  <p className="mt-2 text-sm font-semibold text-gray-800">
                    {formatTime(selectedEvent.timestamp)}
                  </p>
                  <p className="text-xs text-gray-400">
                    {formatDate(selectedEvent.timestamp)}
                  </p>
                </div>

                <div className="rounded-xl bg-gray-50 px-4 py-3">
                  <p className="text-xs font-medium uppercase tracking-wide text-gray-400">
                    Angle
                  </p>
                  <p className="mt-2 text-sm font-semibold text-gray-800">
                    {selectedEvent.angle}°
                  </p>
                  <p className="text-xs text-gray-400">Degrees open</p>
                </div>

                <div className="rounded-xl bg-gray-50 px-4 py-3">
                  <p className="text-xs font-medium uppercase tracking-wide text-gray-400">
                    Battery
                  </p>
                  <p
                    className={`mt-2 text-sm font-semibold ${getBatteryColor(
                      selectedEvent.battery
                    )}`}
                  >
                    {selectedEvent.battery}%
                  </p>
                  <p className="text-xs text-gray-400">
                    {getBatteryLabel(selectedEvent.battery)}
                  </p>
                </div>
              </div>
            ) : (
              <div className="rounded-xl bg-gray-50 px-4 py-6 text-sm text-gray-500">
                No position data available yet.
              </div>
            )}
          </div>
        </div>

        <div className="flex flex-col gap-3">
          <div className="flex items-center justify-between">
            <p className="text-base font-semibold text-gray-800">Events / Log</p>
            {!eventsLoading && !eventsError && events.length > 0 && (
              <p className="text-sm text-gray-400">
                {events.length} event{events.length === 1 ? "" : "s"}
              </p>
            )}
          </div>

          {eventsError ? (
            <ErrorState />
          ) : eventsLoading ? (
            <LoadingState />
          ) : events.length === 0 ? (
            <EmptyState />
          ) : (
            <div className="overflow-hidden rounded-2xl border border-gray-200 bg-white">
              <div className="grid grid-cols-3 border-b border-gray-200 bg-gray-50 px-5 py-3 text-xs font-semibold uppercase tracking-wide text-gray-500">
                <span>Timestamp</span>
                <span className="text-center">Angle</span>
                <span className="text-right">Battery</span>
              </div>

              <div className="max-h-105 overflow-y-auto">
                {events.map((event) => (
                  <div
                    key={event.id}
                    className={`grid grid-cols-3 items-center border-b border-gray-100 px-5 py-4 text-sm ${selectedEvent?.id == event.id ? 'bg-gray-50' : ''} transition hover:bg-gray-50 last:border-b-0`}
                    onClick={() => setSelectedEvent(event)}
                  >
                    <div className="flex flex-col">
                      <span className="font-semibold text-gray-800">
                        {formatTime(event.timestamp)}
                      </span>
                      <span className="text-xs text-gray-400">
                        {formatDate(event.timestamp)}
                      </span>
                    </div>

                    <div className="text-center font-semibold text-gray-700">
                      {event.angle}°
                    </div>

                    <div className="text-right">
                      <span className={`font-semibold ${getBatteryColor(event.battery)}`}>
                        {event.battery}%
                      </span>
                    </div>
                  </div>
                ))}
              </div>
            </div>
          )}
        </div>
      </div>
    </div>
  );
}

export default App;