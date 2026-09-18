# VDA 5050 v3: ROX-Diff and Ilmatar

This repository operates a ROX-Diff AMR and an overhead crane through a
Raspberry Pi master. The paper benchmark compares direct ROS 2/Nav2 commands
with VDA orders for the same 90-degree ROX rotation.

**All benchmark commands, timestamps, logs and analysis now run on the Pi.**
ROX runs its normal Nav2 stack and VDA adapter. The adapter relays Nav2
acknowledgements and results; it does not record experiment timestamps.

| Measurement | Start on Pi | End on Pi |
|---|---|---|
| Acknowledgement round trip | `COMMAND_ISSUED` | `NAV2_ACK_RECEIVED` |
| Completion response time | `COMMAND_ISSUED` | `NAV2_RESULT_RECEIVED` |

`TRIAL_FINISHED` records the later endpoint check or failure. It is not a third
latency metric. Old ROX-clock pilot logs use a different measurement boundary
and must remain separate from the new dataset.

## Start here

| Task | Guide |
|---|---|
| Install, run and analyse the Pi benchmark | [Pi benchmark](docs/PI_BENCHMARK.md) |
| Understand the two paths and paper claims | [Architecture](docs/architecture.md) |
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
| `benchmark/` | Pi runner, configuration, schedule and three timing events |
| `analysis/` | One-log CSV derivation, statistics and paper figures |
| `configs/`, `schemas/`, `examples/` | Site settings and protocol definitions |
| `deploy/`, `scripts/` | Installation and operational tools |
| `tests/` | Offline regression checks |

The retired DBot stack, generated legacy workspaces, old map copy and historical
update notes were removed from the working tree. Git history retains them.
Current maps, waypoints, controllers, crane watchdogs and safety interlocks are
preserved. See [revision details](docs/PI_REVISION.md).

## Offline verification

```bash
python3 -m pip install -r benchmark/requirements.txt
bash scripts/run_static_checks.sh
```

This does not command hardware. The Pi benchmark guide includes a separate
read-only hardware check and a supervised pilot before the final campaign.

The crane remains operational. Its previous experimental timer was retired:
assigning a local target is not evidence that the PLC accepted a command.
A crane measurement contract must be defined at the actual OPC UA/PLC boundary
before extending this ROX dataset.
