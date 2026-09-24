# VDA 5050 v3: ROX-Diff and Ilmatar

This repository operates a ROX-Diff AMR and an overhead crane through a
Raspberry Pi master. The paper benchmark uses a separate laptop with native
ROS 2 Jazzy as command origin and the only timing clock. Native commands go
directly to ROX/Nav2 or the crane OPC UA interface. VDA orders go through the Pi
broker and device adapters. Only one device/path is exercised per trial.

The two durations are command-to-acknowledgement and command-to-completion.
All three timestamps come from the laptop. Old Pi/ROX-origin datasets are not
compatible with this measurement boundary.

## Start here

| Task | Guide |
|---|---|
| Paper timing architecture and executable commands | [LaTeX methods fragment](paper/measurement_architecture.tex) |
| Start the existing robot, Pi and crane services | [Deployment](docs/deployment.md) |
| ROX daily commands | [ROX commands](docs/ROX_COMMANDS.md) |
| Update the map and dependent waypoints | [Remapping](docs/REMAP_AND_RECAPTURE_WAYPOINTS.md) |
| Use the master UI and view timings | [Dashboard](docs/DASHBOARD.md) |
| Commission physical motion and handover | [Commissioning](docs/COMMISSIONING_RUNBOOK.md) |
| Crane automatic/manual controls | [Crane controls](docs/crane_automatic_and_manual_controls.md) |
| Diagnose crane watchdog issues | [Watchdog](docs/DEDICATED_WATCHDOG_SESSION.md) |

## Active source

| Directory | Purpose |
|---|---|
| `fleet_control/` | Pi master, dashboard, sequential handover |
| `crane_edge/` | Crane adapter, OPC UA access and watchdog |
| `ros2_ws/src/rox_vda5050_adapter/` | ROX adapter, waypoint and pose tools |
| `benchmark/` | Laptop runner, configuration, schedule and three timing events |
| `analysis/` | One-log CSV derivation, statistics and paper figures |
| `configs/`, `schemas/`, `examples/` | Site settings and protocol definitions |
| `deploy/`, `scripts/` | Installation and operational tools |
| `tests/` | Offline regression checks |

The retired DBot stack, generated legacy workspaces, old map copy and historical
update notes were removed from the working tree. Git history retains them.
Current maps, waypoints, controllers, crane watchdogs and safety interlocks are
preserved.

## Offline verification

```bash
python3 -m pip install -r benchmark/requirements.txt
bash scripts/run_static_checks.sh
```

This does not command hardware. Benchmark configuration is deliberately disabled
until the laptop hostname, broker address and physical endpoints are verified.
Use `python3 benchmark/latency_benchmark.py --help` for the shared ROX/crane CLI.
Run a supervised pilot before the final campaign. The LaTeX fragment contains
setup and analysis commands as comments; no separate benchmark guide is needed.
