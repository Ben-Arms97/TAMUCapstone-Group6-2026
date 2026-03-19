import { Outlet } from "react-router";
import Navbar from "../components/Navbar";

export default function Layout() {
    return (
        <div className="min-h-screen flex flex-col bg-gray-50">
            <Navbar />
            <div className="flex-1">
                <Outlet />
            </div>
        </div>
    );
}