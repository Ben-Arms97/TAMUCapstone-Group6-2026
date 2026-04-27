# TAMUCapstone-Group6-2026

End-to-end valve monitoring system for the Bray International capstone project. An STM32-based embedded device samples a valve angle and battery level, transmits the readings over LoRaWAN, and a web stack ingests the packets via MQTT, persists them to PostgreSQL, and visualizes them in a React dashboard.

---

## Repository Layout

```
.
├── Embedded/        STM32CubeIDE project for the LoRaWAN sensor node (firmware)
├── web/
│   ├── backend/     Flask + SQLAlchemy API, MQTT packet sniffer, Postgres models
│   ├── frontend/    React + TypeScript + Vite dashboard (Tailwind, React Query, React Router)
│   ├── compose.yaml         Local dev orchestration (db, mqtt, server, client)
│   └── compose.prod.yaml    Production overrides
├── sim.c            Tiny C utility that publishes fake sensor packets to the MQTT broker
├── README.md        (this file)
├── .gitignore
└── .dockerignore
```

### Embedded/

STM32CubeIDE C project targeting the STM32L082CZYX MCU. The firmware is **entirely hand-written**: STM32CubeMX's code generator could not be used alongside the I-CUBE-LRWAN expansion in our setup, so the project does not contain a `.ioc` file and there are no auto-generated regions to preserve. Edit any source file directly.

- `Core/Inc/` and `Core/Src/` — application code. Start at `Core/Src/main.c`; sensor sampling is in `sys_sensors.c` / `adc_if.c`, RTC handling in `rtc.c` / `rtc_if.c`, low-power glue in `stm32_lpm_if.c`, and platform/system setup in `sys_app.c`. Peripheral init (clocks, GPIO, ADC, USART, DMA, RTC) is wired up by hand in these files.
- `Drivers/` — vendor HAL/CMSIS for the STM32L0 family (do not modify).
- `LoRaWAN/` — the LoRaWAN MAC/stack vendored from I-CUBE-LRWAN, including the application layer that builds and queues uplinks.
- `Middlewares/` — third-party middleware (utilities, sequencer, low-power timer server, etc.).
- `STM32L082CZYX_FLASH.ld` — linker script for the target part.
- `.cproject` / `.project` / `.settings/` — Eclipse/CubeIDE project metadata (include paths, build configs). Update these when adding new source folders.
- `Embedded.launch` — debug launch configuration for ST-LINK.

### web/backend/

Flask service that runs alongside Mosquitto and Postgres in Docker.

- `app.py` — application factory, route registration, and the MQTT subscriber that decodes 2-byte payloads `[angle, battery]` and inserts them as `Event` rows. Exposes `GET/POST /event`, `GET /packets` (debug `#` topic capture), and `GET /prodpackets` (configured topic capture).
- `database.py` — SQLAlchemy `Event` model (`id` UUID, `angle`, `battery`, `timestamp` epoch-ms).
- `utils/PacketSniffer.py` — paho-mqtt wrapper that subscribes to topics, buffers captured messages, and optionally invokes a callback per message.
- `utils/ClearDatabase.py` — background job that periodically truncates the events table (interval driven by `MESSAGE_CLEAR_INTERVAL`).
- `requirements.txt`, `Dockerfile` — runtime image (Python 3.11, Gunicorn + eventlet worker).
- `.env.local` / `.env.prod` — environment variables loaded by `python-dotenv` and Compose. Expected keys: `POSTGRESQL_CONNECTION_STRING`, `MQTT_TOPIC`, `MESSAGE_CLEAR_INTERVAL`.

### web/frontend/

Single-page React 19 app built with Vite.

- `src/main.tsx` — entry point, sets up the React Query client and router.
- `src/App.tsx` — primary view; fetches `/event` and renders the live valve telemetry.
- `src/components/` — `Navbar.tsx`, `ValveDisplay.tsx`.
- `src/screens/Layout.tsx` — shared route layout.
- `vite.config.ts`, `tsconfig*.json`, `eslint.config.js` — build/lint configuration.
- `.env.development` / `.env.production` — backend URL the client points at.

### sim.c

Standalone C program (links against `libmosquitto`) that prompts on stdin for two bytes and publishes them to `sensors/.../port/1` on the broker. Useful for exercising the backend without flashing hardware.

---

## How the Pieces Talk

```
[STM32 node]  --LoRaWAN-->  [Network server]  --MQTT-->  [mosquitto]
                                                            │
                                                            ├── PacketSniffer ("#")           → /packets
                                                            └── PacketSniffer (MQTT_TOPIC)    → handler
                                                                                                 │
                                                                                                 ▼
                                                                                        Postgres (Event rows)
                                                                                                 │
                                                                                                 ▼
                                                                                       Flask /event ──► React UI
```

`sim.c` (or any MQTT client) can stand in for the LoRaWAN side during development by publishing directly to the broker.

---

## Getting Started

### Prerequisites

Install these once before doing anything else:

- **Git** — clone the repo.
- **Docker Desktop** (or Docker Engine + Compose v2) — runs the database, broker, backend, and frontend together. This is the primary supported dev workflow.
- **Node.js 20+** and **npm** — only needed if you want to run the frontend outside Docker.
- **Python 3.11+** — only needed if you want to run the backend outside Docker. Install deps with `pip install -r web/backend/requirements.txt`.
- **STM32CubeIDE 2.0.0** — required to open, build, and flash the firmware in `Embedded/`. Install the **STM32Cube MCU Package for STM32L0** through the IDE's package manager. The I-CUBE-LRWAN sources are already vendored under `Embedded/LoRaWAN/` and `Embedded/Middlewares/`, so the expansion pack does **not** need to be installed and CubeMX is **not** used in this project.
- **ST-LINK/V2 (or V3) programmer** and the **ST-LINK USB drivers** — to flash and debug the board.
- **libmosquitto + a C compiler** (e.g. `apt install libmosquitto-dev` and `gcc`, or Homebrew `mosquitto`) — only needed to build `sim.c`.

Recommended editor extras: an editor with TypeScript, ESLint, Python, and C/C++ support (VS Code works for everything except the embedded build, which lives in CubeIDE).

### Environment files

The backend looks for `.env.local` (dev) and `.env.prod` (prod) under `web/backend/`. They should define:

```
POSTGRESQL_CONNECTION_STRING=<your-connection-string>
MQTT_TOPIC=sensors/<device-id>/port/1
MESSAGE_CLEAR_INTERVAL=86400
```

The frontend reads its API base URL from `web/frontend/.env.development` and `.env.production`.

### Run the web stack (recommended path)

```bash
cd web
docker compose up --build
```

This brings up:
- Postgres (pgvector image) on `localhost:5432`
- Mosquitto on `localhost:1883`
- Flask backend on `http://localhost:5000`
- Vite dev server on `http://localhost:5173`

Compose `develop.watch` is configured, so edits under `web/backend/` and `web/frontend/` hot-reload in their containers.

### Build and run sim.c

```bash
gcc sim.c -lmosquitto -o sim
./sim
# then type two bytes per line, e.g.: 90 75
```

It connects to the broker on the IP hard-coded at the top of `sim.c` — change the host to `127.0.0.1` when targeting the local Compose stack.

### Build and flash the firmware

1. Open STM32CubeIDE and **File → Open Projects from File System…** → point it at `Embedded/`.
2. Let the IDE index, then **Project → Build Project**.
3. Connect the board via ST-LINK and **Run → Debug As → STM32 C/C++ Application** (the launch config in `Embedded.launch` should be picked up automatically).
4. To change pins, peripherals, clocks, or stack settings, edit the relevant `Core/Src/*.c` and `Core/Inc/*.h` files directly. There is no `.ioc` to regenerate from. If you add new source folders or change include paths, update `.cproject` and `.settings/` (or use **Project → Properties → C/C++ General → Paths and Symbols**) so the build picks them up.

---

## Where to Start Reading

If you are new to the codebase, walk through it in this order:

1. `web/compose.yaml` — see how the services fit together.
2. `web/backend/app.py` — the entry point and the place where MQTT payloads become database rows.
3. `web/backend/database.py` — the data model.
4. `web/frontend/src/App.tsx` and `src/components/ValveDisplay.tsx` — how the UI consumes `/event`.
5. `Embedded/Core/Src/main.c` and `sys_sensors.c` — the firmware loop and where uplink payloads are constructed.
6. `sim.c` — the smallest possible producer for the same MQTT contract.

---

## How to Add to the Code

**Backend (Flask).** Add new routes in `app.py` (or split them into a blueprint as the file grows). Add new tables/columns to `database.py`; for non-trivial schema changes consider introducing Flask-Migrate. New MQTT topics can be subscribed to by instantiating another `PacketSniffer` in `setup_packet_sniffer`. After editing `requirements.txt`, Compose's watch rule will rebuild the image automatically.

**Frontend (React).** New presentational pieces go in `src/components/`, new full-page views in `src/screens/`, and routes are wired up in `App.tsx`/`main.tsx`. Use React Query for any server state and Tailwind utility classes for styling. Run `npm run lint` before committing.

**Firmware.** Every file under `Core/` is hand-maintained — there is no CubeMX round-trip to worry about, so edit freely. Application logic — sensor reads, payload packing, uplink scheduling — belongs in `Core/Src/main.c` and `sys_sensors.c`. Peripheral init (clocks, GPIO, ADC, USART, DMA, RTC) is implemented directly in the matching `Core/Src/*.c` files; touch those when you add or reconfigure hardware. New source files need to be added to the CubeIDE build (Properties → C/C++ General → Paths and Symbols) so they end up in `.cproject`. The payload contract today is two bytes: `[angle, battery]`. If you change the payload format, update the decoder in `web/backend/app.py` and the `Event` schema together.

**Simulator.** Edit `sim.c` to match any new payload shape so the backend can be exercised without hardware.

### Coding conventions

- TypeScript: ESLint config under `web/frontend/eslint.config.js`. Prefer functional components and hooks; no class components.
- Python: 4-space indent, type hints where practical, environment-driven config (no hard-coded secrets).
- C (firmware): the project is hand-written — no CubeMX user-code regions to honor — but never edit files under `Drivers/` or `Middlewares/` (treat those as vendored).
- Commits: small, focused, with imperative-mood messages (`Add valve angle smoothing`, not `added stuff`).

---

## Useful References

- STM32L0 reference manual (RM0367) and STM32L082 datasheet — for the MCU peripherals.
- ST I-CUBE-LRWAN documentation — reference for the LoRaWAN stack vendored into `Embedded/LoRaWAN/` (the pack itself is **not** installed in CubeIDE for this project).
- LoRa Alliance LoRaWAN 1.0.x specification — for uplink/downlink semantics.
- Eclipse Mosquitto docs — broker configuration reference.
- Flask, SQLAlchemy, paho-mqtt, React, React Query, Vite, and Tailwind official docs — linked from their respective `package.json` / `requirements.txt` entries.
