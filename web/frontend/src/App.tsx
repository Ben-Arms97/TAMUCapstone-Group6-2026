function App() {
  return (
    <div className="h-full flex flex-col p-12 gap-6 bg-gray-50">
      <div className="flex-1 flex gap-6">
        <div className="flex-1 bg-white rounded-2xl border border-gray-200 flex items-center justify-center">
          <p className="text-gray-400 text-sm">Position Visualization</p>
        </div>

        <div className="flex-1 bg-white rounded-2xl border border-gray-200 p-8">
          <p className="text-gray-700 text-sm font-medium mb-3">Position Details</p>
          <ul className="space-y-1.5 text-sm text-gray-500">
            <li>– Timestamp</li>
            <li>– Angle (degrees open)</li>
            <li>– Battery Percentage</li>
          </ul>
        </div>
      </div>

      <div className="flex-1 flex flex-col gap-3">
        <p className="text-gray-700 text-sm font-medium">Events/Log</p>
        <div className="flex-1 flex flex-col gap-3">
          <div className="h-18 bg-white rounded-xl border border-gray-200" />
          <div className="h-18 bg-white rounded-xl border border-gray-200" />
        </div>
      </div>

    </div>
  )
}

export default App