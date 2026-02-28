import { Outlet } from "react-router";

import Navbar from "../components/Navbar";

export default function Layout() {

    return (
        <div className="h-screen flex flex-col bg-gray-50">
            <Navbar />
            <div className="flex-1 min-h-0">
                <Outlet />
            </div>
        </div>
    )
}