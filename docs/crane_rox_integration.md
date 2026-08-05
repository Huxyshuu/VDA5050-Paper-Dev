# Crane + ROX-Diff integration and calibration

## Coordinate rule

Do not copy the ROX `df_map` coordinates into the crane order. The ROX uses ROS/Nav2 map coordinates (`x`, `y`, `theta`). The crane uses its own absolute bridge/trolley axes and hoist height. The two devices meet physically at the same station, but their numeric coordinates are unrelated. Coordination is through exact VDA node and action IDs.

## Required handover chain

1. ROX reaches `node2` and `rox_hold_at_crane` is `RUNNING`.
2. The master releases crane `action4` only for that exact rendezvous.
3. The crane lowers (`action5`) and waits for the approved manual release (`action6`).
4. The crane raises to the verified safe-lift height (`action7`).
5. The master sends `releaseHold` to the ROX only after `action7` is `FINISHED`. A failed action does not release the ROX.

## Calibrate the crane-local positions

All movement must follow local crane safety procedures. Use no load initially, reduced commissioning speeds, a clear area, and reachable physical emergency stops.

On the Pi or the crane adapter computer:

```bash
cd ~/VDA5050-Paper-Dev
source .venv-crane/bin/activate
cp -n configs/crane_waypoints.yaml.example configs/crane_waypoints.yaml
```

Configure credentials outside Git:

```bash
export CRANE_OPCUA_URL='<real OPC UA URL>'
export CRANE_ACCESS_CODE='<real numeric access code>'
```

Move the crane manually using the approved local controls to the source station, stop all axes, let readings settle, and sample:

```bash
python3 scripts/crane_waypoint_tool.py --update source_station
```

Move the ROX independently to its already verified `crane_handover` pose. Physically align the crane hook/load interface with the robot handover point, stop all crane axes, then sample:

```bash
python3 scripts/crane_waypoint_tool.py --update rox_handover
```

Capture the crane home/reset position:

```bash
python3 scripts/crane_waypoint_tool.py --update home
```

Capture hoist levels at the correct physical heights. Repeat the command with the matching key at each level:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist source_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist source_safe_lift_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_safe_lift_m
```

The tool resets `configured: false` after every change. Review the file manually:

```bash
nano configs/crane_waypoints.yaml
```

Verify every bridge/trolley position and every hoist height repeatedly with crane-only operation. Only then set:

```yaml
configured: true
```

## Generate both full orders

Generate the crane order, update the crane map/home settings, and enable the crane in the dashboard:

```bash
python3 scripts/generate_crane_order.py \
  --waypoints configs/crane_waypoints.yaml \
  --output examples/orders/order_ilmatar_v3.json \
  --update-fleet-env configs/fleet_control.env \
  --enable-crane
```

Regenerate the ROX full route from the current verified ROS waypoints:

```bash
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_crane_case_study.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Check everything together:

```bash
python3 scripts/check_crane_rox_integration.py
./scripts/run_static_checks.sh
```

Do not proceed if either command fails.

## Start the system

Pi terminal 1:

```bash
sudo systemctl enable --now mosquitto
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
./scripts/run_master_control.sh
```

Pi terminal 2 (or the dedicated crane adapter computer):

```bash
cd ~/VDA5050-Paper-Dev
source .venv-crane/bin/activate
./scripts/run_crane_adapter.sh
```

ROX terminal 1:

```bash
rox nav
```

ROX terminal 2:

```bash
rox adapter-real
```

Monitor MQTT on the Pi:

```bash
mosquitto_sub -h 127.0.0.1 -t 'vda5050/v3/#' -v
```

Verify both participants before any combined order:

```bash
curl -s http://127.0.0.1:5000/runtime | python3 -m json.tool
```

Both `connectionState` values must be `ONLINE`, both states must be current, both devices must be in automatic mode, and neither may have an active order.

## Staged commissioning

1. Crane-only, no load: `curl -X POST http://127.0.0.1:5000/order/crane`
2. ROX-only full route, crane prevented from moving: `curl -X POST http://127.0.0.1:5000/order/rox`
3. Coordinated no-load run: use the dashboard coordinated scenario or `curl -X POST http://127.0.0.1:5000/order`
4. Repeat until coordinates, action transitions, hold/release behavior, cancellation, and scanner interventions are consistent.
5. Loaded testing only under the approved local procedure and supervision.

## Emergency and cancellation

Use physical safety controls first. Software cancellation is secondary:

```bash
curl -X POST http://127.0.0.1:5000/cancel/crane
curl -X POST http://127.0.0.1:5000/cancel/rox
```

Never bypass a failed crane homing/preflight, stale localization, scanner intervention, unknown map, or failed safe-lift action by enlarging tolerances or manually releasing the ROX.
