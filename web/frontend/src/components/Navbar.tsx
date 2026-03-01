import React from "react";

interface INavbar {
    children?: React.ReactNode;
}

const Navbar: React.FC<INavbar> = ({ children }) => {
    return (
        <header className="w-full border-b border-gray-200 bg-white">
            <nav className="mx-auto flex h-18 max-w-7xl items-center justify-between px-6">
                {/* Left: Logo */}
                <a
                    href="https://getlogo.net/bray-international-logo-vector-svg/"
                    target="_blank"
                    rel="noopener noreferrer"
                    aria-label="Bray International"
                    className="flex items-center rounded-md px-2 py-1"
                >
                    <img
                        src="https://getlogo.net/wp-content/uploads/2020/02/bray-international-logo-vector.png"
                        alt="Bray International logo"
                        className="h-16 w-auto object-contain"
                    />
                </a>

                {/* Right: Actions */}
                <div className="flex items-center gap-3">
                    {children}

                    <button
                        type="button"
                        className="
                            inline-flex items-center gap-1.5
                            rounded-md
                            border border-red-200
                            bg-white
                            px-6 py-2.5
                            text-sm font-bold uppercase tracking-widest
                            text-red-600
                            transition-all duration-200
                            hover:bg-red-600 hover:text-white hover:border-red-600
                            active:scale-95
                        "
                    >
                        <span className="relative flex h-2 w-2">
                            <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-red-400 opacity-75" />
                            <span className="relative inline-flex rounded-full h-2 w-2 bg-red-500" />
                        </span>
                        Alerts
                    </button>
                </div>
            </nav>
        </header>
    );
};

export default Navbar;