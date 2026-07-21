# Raspberry Pi to ROX-Diff Commissioning Test Plan

Run stages in order. Do not combine crane and AMR movement until both have passed independent tests.

## Stage 0 — Static repository checks

On Pi or development machine:

```bash
./scripts/run_static_checks.sh
```

Expected: syntax/schema checks pass. This does not test ROS or hardware.

## Stage 1 — Network and broker

On Pi:

```bash
ip addr
ss -ltnp | grep 1883
mosquitto_sub -h 192.168.50.115 \
  -t 'vda5050/v3/commissioning/ping' -C 1 -v
```

On ROX:

```bash
ping -c 3 192.168.50.115
./scripts/check_pi_mqtt_from_rox.sh 192.168.50.115 1883
```

Acceptance:

- TCP 1883 reachable;
- Pi receives the commissioning MQTT message;
- no routing/VPN ambiguity between robot and Pi.

## Stage 2 — Native robot health

Without VDA adapter:

- start Neobotix bringup;
- verify scanner and emergency-stop state;
- teleoperate slowly;
- verify `/odom`, `/scan`, `/tf`, `/battery_state`, `/emergency_stop_state`, `/safety_state`;
- inspect actual message definitions;
- ensure operating mode and field violation values make sense.

Acceptance: native robot operation is stable and safety devices act as expected.

## Stage 3 — Map and ordinary Nav2

- create/save new map;
- initialize localization;
- verify costmaps and footprint;
- send repeated RViz/Nav2 goals to intended areas;
- capture `home`, `short_test`, `crane_handover`, `warehouse_dropoff`;
- verify each captured pose with ordinary Nav2.

Acceptance: all target poses are repeatable without VDA.

## Stage 4 — Generate Pi order

- copy waypoint YAML to Pi;
- set `configured: true` only after review;
- generate short route and update `fleet_control.env`;
- restart master;
- inspect generated JSON and `/runtime`.

Acceptance: generated order validates and contains no DBot coordinates/identity.

## Stage 5 — Adapter dry run

Launch:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.50.115 \
  map_id:=warehouse_case_study \
  dry_run_navigation:=true
```

Send:

```bash
curl -X POST http://192.168.50.115:5000/order/rox
```

Expected:

1. retained connection is `ONLINE`;
2. periodic schema-valid state appears;
3. order is accepted;
4. simulated node transitions occur;
5. `holdPose` remains `RUNNING`;
6. `/release_hold` changes it to `FINISHED`;
7. order completes without robot motion.

Monitor:

```bash
mosquitto_sub -h 192.168.50.115 \
  -t 'vda5050/v3/neobotix/rox_diff_1/#' -v
curl http://192.168.50.115:5000/runtime | python3 -m json.tool
```

## Stage 6 — Instant actions

Test target-specific calls:

```bash
curl -X POST http://192.168.50.115:5000/pause/rox
curl -X POST http://192.168.50.115:5000/resume/rox
curl -X POST http://192.168.50.115:5000/cancel/rox
curl -X POST http://192.168.50.115:5000/automatic
```

The initialization route requires real `ROX_INIT_*` values. Confirm instant action states reach the expected terminal state.

## Stage 7 — Short real VDA motion

- use `rox_short_motion_test.yaml` generated order;
- lower platform/Nav2 speed limits;
- clear the area;
- keep emergency stops accessible;
- localize ROX at `home` within tolerance;
- launch adapter with `dry_run_navigation:=false`;
- send only `/order/rox`;
- verify `holdPose` then release it.

Acceptance:

- Nav2 goal sent once;
- robot reaches correct position/orientation;
- state node/action progression is consistent;
- pause/resume and cancel do not cause late unintended movement.

## Stage 8 — Full ROX route without crane motion

Generate the full route and run:

```text
home -> handover hold -> drop-off -> home
```

Manually release hold. Confirm:

- orientation at handover;
- route clearance;
- action ID maps to logical `node2`;
- cancellation produces consistent state;
- reconnect/restart does not silently resend an order.

## Stage 9 — Crane only

Run the crane adapter and send:

```bash
curl -X POST http://192.168.50.115:5000/order/crane
```

Confirm crane VDA state, action transitions, connection and hoist information independently.

## Stage 10 — Coordinated handover without load

Send both orders only after Stages 8 and 9 pass:

```bash
curl -X POST http://192.168.50.115:5000/order
```

Confirm:

- ROX holds at the configured handover pose;
- crane reaches its logical rendezvous;
- master associates the correct action IDs and node IDs;
- release is tied to the correct rendezvous;
- ROX is not released until the configured crane safe-lift action reaches FINISHED;
- no unsafe overlap occurs.

## Stage 11 — Loaded and disturbance tests

Only after supervised unloaded repetition:

- intended payload;
- pause/resume;
- cancellation before movement;
- cancellation during safe horizontal robot movement;
- broker/adapter communication loss;
- robot localization loss;
- Nav2 failure;
- scanner intervention;
- document which recovery requires a person.

Record logs and do not claim safety or performance validation beyond what was actually tested.
