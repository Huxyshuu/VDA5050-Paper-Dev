# Flask HMI v2: live map, immutable mission history and experiment mode

This dashboard update is for the Raspberry Pi master controller in the ROX-Diff + Ilmatar VDA 5050 v3.0 case study.

## Main behavior changes

### Mission state correctness

A mission is now terminal and immutable once it reaches one of:

- `FINISHED`
- `FAILED`
- `REJECTED`
- `CANCELLED`

A later VDA state belonging to another order can no longer rewrite an already finished mission as rejected. A mission is marked `REJECTED` only when the robot reports a VDA order-rejection error that explicitly references that mission's `orderId`. Critical/fatal errors during an accepted order are classified as `FAILED`, not `REJECTED`. Rejected and failed history entries also show the reported reason so operators can distinguish a real protocol rejection from an execution failure.

This follows the VDA 5050 model: order rejection is communicated through errors, while traversal is reported through `nodeStates`, `edgeStates`, `lastNodeId`, and `lastNodeSequenceId`. The dashboard does not invent an `orderStatus` field.

### One command-chain view

The large command-chain panel is now the only live scenario progress view. It shows every scenario waypoint in order and updates each step as:

- completed
- active
- upcoming
- failed/cancelled

The repeatable-test section is now only a mission library. It no longer repeats the active run. A completed scenario chain remains visible until a newer direct waypoint order or scenario supersedes it.

### Live map

The browser displays:

- the ROS occupancy map;
- current ROX-Diff position and heading;
- all configured waypoints;
- the current scenario route;
- completed and active route segments.

The connecting line is the logical VDA waypoint sequence, not the exact obstacle-avoiding Nav2 path. Nav2 remains responsible for the actual trajectory.

The map can be dragged, zoomed, and rotated. Toolbar actions can center the robot, center the robot while keeping every waypoint visible, fit all route content, follow the robot, or reset to the full north-up map. The selected view is stored per browser and map revision, so one-second dashboard polling does not reset it. See `docs/FLASK_HMI_MAP_CONTROLS.md`.

If the Pi does not yet have the map files, the UI automatically falls back to a scaled coordinate view using robot and waypoint positions.

### Styled confirmations

Waypoint dispatch, scenario start, scenario stop, order cancellation, and experiment-mode changes all use the same in-page modal. No native browser `window.confirm()` dialogs remain.

### Experiment mode

Experiment mode writes runs to:

```text
results/experiments/mission_control.sqlite3
```

For every mission dispatched while logging is enabled it records:

- session, mission and order identifiers;
- source and scenario;
- waypoint;
- start, acceptance, running and finish timestamps;
- terminal status;
- duration;
- approximate travelled distance from sampled VDA positions;
- pause count;
- cancellation request;
- start, target and end poses;
- final XY and angular error;
- battery state at start and end;
- VDA errors.

Exports:

```text
/api/experiments
/api/experiments/export.csv
```

The distance is a sampled estimate from the reported robot pose, not wheel-integrated odometry. Dashboard statistics aggregate every stored run in the database; the on-screen recent list is intentionally limited, while CSV export contains all rows.

## Map files on the Pi

The dashboard expects by default:

```text
configs/maps/df_map.yaml
configs/maps/df_map.pgm
```

When those files are already tracked in the repository, use them directly; no `/tmp` directory or installation command is required. Verify that the YAML uses a valid relative image reference such as `image: df_map.pgm`.

Use `scripts/install_dashboard_map.sh` only to import or normalize a map stored outside the repository.

## Configuration

Add these settings to `configs/fleet_control.env`:

```dotenv
FLEET_UI_MAP_YAML=configs/maps/df_map.yaml
FLEET_UI_EXPERIMENT_DB=results/experiments/mission_control.sqlite3
FLEET_UI_EXPERIMENT_DEFAULT=false
FLEET_UI_EXPERIMENT_SAMPLE_DISTANCE_M=0.01
```

The SQLite database is runtime research data and is ignored by Git.

## Start and test

Pi:

```bash
cd ~/VDA5050-Paper-Dev
./scripts/run_master_control.sh
```

ROX:

```bash
rox nav
rox adapter-real
```

Read-only API check on the Pi:

```bash
cd ~/VDA5050-Paper-Dev
.venv/bin/python scripts/dashboard_hmi_smoke_test.py
```

Open:

```text
http://192.168.50.115:5000
```

## Recommended physical test

1. Confirm MQTT and ROX are online.
2. Confirm localization and safety are clear.
3. Send `short_test` from the waypoint card.
4. Verify the chain reaches `FINISHED` and stays `FINISHED`.
5. Send a second order and confirm the first history entry remains unchanged.
6. Start the short commissioning scenario.
7. Verify the full scenario tree advances one step at a time.
8. Drag, zoom, rotate, fit all, use Robot + all, and enable Follow; verify polling does not reset the map view.
9. Enable experiment mode and repeat one short run.
10. Export CSV and verify the recorded row.
11. Test pause, resume, and controlled cancellation.

## Important safety note

The web map is an operator visualization. It does not replace RViz, Nav2 diagnostics, the safety PLC, scanners, physical emergency stops, or supervised commissioning procedures.
