# Crane–ROX reconciliation — 5 August 2026

This document records the reconciled runtime state after auditing the uploaded
project archive at Git commit `f13d903` together with the earlier crane and
ROX-Diff integration decisions.

## Resulting architecture

- Raspberry Pi:
  - Mosquitto broker;
  - Flask/master controller;
  - crane OPC UA/VDA 5050 adapter.
- ROX-Diff onboard computer:
  - native ROS 2/Nav2 stack;
  - ROX VDA 5050 adapter.
- MQTT identity:
  - crane: `vda5050/v3/konecranes/ilmatar_1`;
  - ROX-Diff: `vda5050/v3/neobotix/rox_diff_1`.
- Logical maps:
  - crane: `map` using absolute bridge/trolley coordinates;
  - ROX-Diff: `df_map` using ROS/Nav2 poses.

The two coordinate systems are aligned physically at the handover, not by
copying numerical coordinates between them.

## Authoritative crane automatic-mode signal

The crane adapter uses only:

```text
DX_Custom_V.Status.WatchDogFault
```

For this installation:

- `false`: external watchdog healthy and automatic/remote operation available;
- `true`: automatic operation unavailable.

The adapter requires `false` to remain stable before it connects to MQTT. It
continues monitoring the value and fails closed if it changes or becomes
unreadable. The Flask `/automatic` route is not part of crane startup; it is a
legacy alias for ROX `initializePosition` only.

## Reconciled defects

The update fixes the following concrete defects found in the uploaded archive:

1. Paho MQTT v2 `ReasonCode` was passed to `int()`, crashing `_on_connect`.
2. The crane process could print that it was running even when MQTT setup had
   failed in the callback thread.
3. Reset/home helpers could keep issuing movement calls after automatic mode
   was lost or a cancel was received.
4. Reset instant actions could report `FINISHED` despite movement timeout or
   failure.
5. The active ROX order was still the two-node short test order and did not
   contain `rox_hold_at_crane`.
6. Four coordinated-scenario methods existed twice in `dashboard_v3.py` and
   silently overrode the first implementations.
7. The dashboard had no usable release control for crane `buttonPress` actions.
8. `/automatic` combined a crane button counter with ROX initialization,
   producing misleading HTTP 400 responses after successful crane homing.
9. `crane_edge/access.txt` was ignored but still tracked by Git.
10. Static checks omitted the crane hardware wrapper, manual-control module,
    active ROX order, duplicate Flask routes and manual order builders.
11. The active crane waypoint file was marked configured even though its own
    descriptions identified the coordinates as unverified legacy values.
12. The crane runner did not consistently use the project virtual environment.

## Crane dashboard controls

The dashboard publishes standard project VDA orders or instant actions. It does
not call OPC UA motion methods directly.

### XY destinations

- Source station;
- ROX handover;
- crane home XY.

Before a standalone XY move, the generated order raises the hook to at least
`travel_safe_m` if the current hook is lower than that minimum.

### Hook heights

- Safe travel;
- source pickup;
- source clear;
- handover lower;
- handover clear;
- home hook.

### Operations

- Release current crane wait;
- home all axes;
- home bridge/trolley;
- home hook;
- pause;
- resume;
- cancel.

The release button adapts to the current action:

- ordinary crane-only `buttonPress`: releases that crane wait without arming a
  ROX action;
- coordinated `action6` while `rox_hold_at_crane` is running at the matching
  rendezvous: releases the crane wait and arms the safe-lift chain.

## Coordinated handover chain

The generated orders and master controller use exact IDs:

1. ROX reaches `node2`; `rox_hold_at_crane` becomes `RUNNING`.
2. Crane `action4` (`buttonPress`) is automatically released.
3. Crane executes `action5` and lowers the hook.
4. Crane `action6` waits for supervised physical transfer confirmation.
5. Dashboard release sends crane `release` and arms the coordinated chain.
6. Crane executes `action7` (`raiseHoist`).
7. Only after `action7` is `FINISHED` does the master send ROX `releaseHold`.
8. If `action7` is `FAILED`, ROX remains held.

The active ROX order is restored to:

```text
node1 home
  -> node2 crane_handover + rox_hold_at_crane
  -> node3 warehouse_dropoff
  -> node4 home
```

## Fail-closed coordinate state

The installer preserves all numeric crane coordinates but sets:

```yaml
configured: false
```

when the active waypoint descriptions still contain `Legacy starting value
only`. This intentionally disables the coordinated scenario and normal manual
movement until physical calibration is completed.

For supervised no-load calibration only, set:

```text
CRANE_ALLOW_UNVERIFIED_MANUAL=true
```

Restart the master after changing it. This override does not bypass:

- VDA online status;
- fresh state requirement;
- `WatchDogFault=false`;
- emergency-stop state;
- safety-field state;
- active-order exclusion.

## Calibration sequence

Run from the repository root with the crane Python environment active.

### Source XY

```bash
python3 scripts/crane_waypoint_tool.py --update source_station
```

### ROX handover XY

1. Navigate ROX-Diff to its verified `crane_handover` pose.
2. Keep it stationary.
3. Align the crane using approved local controls.
4. Stop all axes.
5. Capture:

```bash
python3 scripts/crane_waypoint_tool.py --update rox_handover
```

### Hook positions

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist travel_safe_m
python3 scripts/crane_waypoint_tool.py --update-hoist source_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist source_safe_lift_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_safe_lift_m
```

### Home

```bash
python3 scripts/crane_waypoint_tool.py --update home
```

Every capture resets `configured: false`. Test every button repeatedly without a
payload. When all values are independently repeatable:

1. set `CRANE_ALLOW_UNVERIFIED_MANUAL=false`;
2. set `configured: true` in `configs/crane_waypoints.yaml`;
3. regenerate the crane order:

```bash
python3 scripts/generate_crane_order.py \
  --waypoints configs/crane_waypoints.yaml \
  --output examples/orders/order_ilmatar_v3.json \
  --update-fleet-env configs/fleet_control.env \
  --enable-crane
```

4. validate:

```bash
python3 scripts/check_crane_rox_integration.py
./scripts/run_static_checks.sh
```

## Normal startup

### Pi terminal 1

```bash
sudo systemctl enable --now mosquitto
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
./scripts/run_master_control.sh
```

### Pi terminal 2

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
./scripts/run_crane_adapter.sh
```

The expected crane sequence is:

```text
OPC UA connected
watchdog loop started
preflight STOP
WatchDogFault=false confirmed
MQTT connected and subscriptions installed
retained ONLINE published
state/visualization/executor threads started
```

With `CRANE_HOME_ON_START=false`, startup does not move the crane. Use the Home
controls after checking the area. With `true`, startup homing remains
interruptible by shutdown or `WatchDogFault` becoming true.

### ROX-Diff

Run the existing native Nav2 stack and then:

```bash
cd ~/Projects/VDA5050-Paper-Dev
export VDA_MQTT_HOST=192.168.50.115
export VDA_MAP_ID=df_map
./scripts/run_rox_adapter_real.sh
```

## Diagnostic checks

```bash
curl -s http://127.0.0.1:5000/api/crane/manual | python3 -m json.tool
curl -s http://127.0.0.1:5000/api/dashboard | python3 -m json.tool
curl -s http://127.0.0.1:5000/runtime | python3 -m json.tool
```

```bash
mosquitto_sub -h 127.0.0.1 -t 'vda5050/v3/#' -v
```

The crane connection topic must report `ONLINE`, state messages must continue,
`operatingMode` must be `AUTOMATIC`, and `WATCHDOG_FAULT` must report `false`.

## Validation boundary

Static checks validate Python/shell syntax, duplicate definitions/routes, VDA
schemas, generated orders, manual dashboard orders, full-route coordination and
credential tracking. They cannot validate physical coordinates, PLC semantics,
scanner behavior, Nav2 localization, payload clearance or actual motion. Those
remain supervised commissioning responsibilities.
