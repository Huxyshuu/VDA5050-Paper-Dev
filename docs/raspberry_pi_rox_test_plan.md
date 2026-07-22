# Raspberry Pi to ROX-Diff Commissioning Test Plan

Execute the stages in order. A stage passes only when its evidence is recorded and no unresolved safety or interface issue remains.

## Stage 1 — Repository and static checks

On both hosts:

```bash
git status --short
git rev-parse --short HEAD
```

On the Pi:

```bash
cd ~/VDA5050-Paper-Dev
./scripts/run_static_checks.sh
```

On the ROX:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
./scripts/rox.sh status
```

## Stage 2 — DTLabOpen and MQTT

On the ROX:

```bash
ping -c 3 192.168.50.115
nc -vz 192.168.50.115 1883
./scripts/check_pi_mqtt_from_rox.sh 192.168.50.115 1883
```

On the Pi:

```bash
ping -c 3 192.168.50.50
mosquitto_sub -h 127.0.0.1 -t 'vda5050/v3/commissioning/ping' -C 1 -v
```

Acceptance: bidirectional IP communication and successful ROX-to-Pi MQTT publication.

## Stage 3 — Native ROX hardware interfaces

Do not start another bringup; it already runs from boot.

```bash
./scripts/rox.sh interfaces
```

Acceptance: `/tf`, `/tf_static`, `/odom`, `/scan`, `/battery_state`, `/emergency_stop_state` and `/safety_state` have the expected types. Nav2 action and `map -> base_link` may still be absent at this stage.

## Stage 4 — Nav2 localization

```bash
./scripts/rox.sh nav
```

Set the initial pose in RViz. Then:

```bash
./scripts/rox.sh status
./scripts/rox.sh tf
```

Acceptance: `/navigate_to_pose` exists, `map -> base_link` is stable, laser data aligns with `df_map`, and the robot can execute an ordinary supervised RViz goal.

## Stage 5 — Waypoint visualization and exact goals

In a separate terminal:

```bash
./scripts/rox.sh visualize
```

Add `/rox_waypoints/markers` as an RViz `MarkerArray` display.

For each waypoint:

```bash
./scripts/rox.sh goto-dry WAYPOINT
./scripts/rox.sh goto WAYPOINT
```

Repeat from different starting poses. Record final XY/yaw error and inspect complete footprint, payload clearance, scanner behavior, departure path and crane alignment.

Acceptance: `WAYPOINT CHECK: PASS` repeatedly and physical suitability confirmed. Only then set `configured: true`.

## Stage 6 — Generate and validate the ROX order

Copy the verified waypoint file to the Pi:

```bash
scp configs/rox_waypoints.yaml \
  raspberrypi@192.168.50.115:/home/raspberrypi/VDA5050-Paper-Dev/configs/
```

On the Pi:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
./scripts/run_static_checks.sh
```

Acceptance: generated order uses `mapId: df_map`, schema checks pass, and `ROX_INIT_*` matches the first waypoint.

## Stage 7 — VDA adapter dry run

On the ROX:

```bash
./scripts/rox.sh adapter-dry
```

On the Pi:

```bash
mosquitto_sub -h 192.168.50.115 \
  -t 'vda5050/v3/neobotix/rox_diff_1/#' -v
curl -X POST http://192.168.50.115:5000/order/rox
curl http://192.168.50.115:5000/runtime | python3 -m json.tool
```

Exercise pause, resume, cancel and hold release. Acceptance: correct schema-valid state/action progression with no physical robot motion.

## Stage 8 — Short real VDA motion

Start the real adapter only after Stage 7 passes:

```bash
./scripts/rox.sh adapter-real
```

Use the short two-node order, reduced speed, no payload, clear area and reachable emergency stops.

Acceptance: first node recognized correctly, exact short route completed, hold behavior correct, no safety-state inconsistency, and logs saved.

## Stage 9 — Full ROX route without crane movement

Generate the full route from `examples/routes/rox_crane_case_study.yaml`. Run it with the crane disabled from motion.

Acceptance: ROX reaches and holds at `crane_handover`, continues only after approved release, reaches `warehouse_dropoff`, and returns home.

## Stage 10 — Crane-only test

Run the crane adapter and crane order without ROX motion and without load. Verify exact action IDs, PLC preflight, automatic mode, homing and safe-lift completion state.

## Stage 11 — Coordinated no-load test

Run both adapters and the combined order. Keep physical safety controls authoritative.

Acceptance:

- ROX holds at the commissioned crane handover pose;
- crane action milestones match the configured IDs;
- ROX is not released before the exact safe-lift action finishes;
- cancellation, broker loss and scanner intervention produce the documented safe response;
- test repeats successfully from a known reset state.

Do not proceed to a loaded test until a responsible local operator approves the no-load evidence.
