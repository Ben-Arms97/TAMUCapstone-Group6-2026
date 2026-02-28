import { Outlet } from "react-router";

import Navbar from "../components/Navbar";

export default function Layout() {

    return (
        <div className="h-screen">
            <Navbar />

            <Outlet />
        </div>
    )
}