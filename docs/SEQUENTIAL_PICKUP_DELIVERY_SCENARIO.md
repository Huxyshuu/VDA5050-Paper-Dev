# Sequential pickup and warehouse-delivery scenario

This scenario runs the crane and ROX-Diff strictly one command at a time. A later
motion is never dispatched until the preceding VDA command reports `FINISHED`.
The scenario is configured in `configs/dashboard_scenarios.yaml` and appears in
the dashboard Mission library as **Sequential pickup and warehouse delivery**.

## Implemented sequence

1. Home all crane axes.
2. Move ROX-Diff to `home`.
3. Move ROX-Diff to `crane_handover`.
4. Move the crane bridge/trolley to `source_station`.
5. Lower the hook to `source_lower_m`.
6. Wait for **Item attached — continue**.
7. Raise the hook to `source_safe_lift_m`.
8. Move the crane bridge/trolley to `rox_handover`.
9. Lower the hook to `handover_lower_m`.
10. Wait for **Item released — continue**.
11. Raise the hook to `handover_safe_lift_m`.
12. Move ROX-Diff to `warehouse_dropoff`.
13. Wait for **Item removed — return home**.
14. Move ROX-Diff to `home`.
15. Home all crane axes.

Two horizontal crane steps were made explicit even though the short verbal
sequence mentioned only the hook heights. `source_lower_m` and
`handover_lower_m` are Z-axis values; they cannot position the bridge and
trolley. The scenario therefore moves to `source_station` before source lowering
and to `rox_handover` before handover lowering.

The three operator confirmations are intentional. The current project has no
authoritative payload-attached, payload-released, or human-unloading sensor. The
scenario must not infer those physical events from elapsed time.

## Preconditions

The scenario remains unavailable unless:

- `ROX_ENABLED=true` and `CRANE_ENABLED=true`;
- both adapters are VDA `ONLINE` and publishing fresh state;
- crane `operatingMode` is `AUTOMATIC` from
  `DX_Custom_V.Status.WatchDogFault=false`;
- neither participant has another active order;
- `configs/rox_waypoints.yaml` is `configured: true`;
- `configs/crane_waypoints.yaml` is `configured: true`;
- all scenario-referenced waypoint and hook names exist.

Do not mark a file configured merely to enable the button. First verify every
position independently without a payload.

## ROX-Diff waypoint calibration

Run these on the ROX-Diff computer after Nav2 localization is valid:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh nav
```

At each physically selected pose, stop the robot and capture:

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

Test each pose independently:

```bash
./scripts/rox.sh goto home
./scripts/rox.sh goto crane_handover
./scripts/rox.sh goto warehouse_dropoff
```

The uploaded project currently contains these starting values:

```yaml
home:              x=0.1729, y=0.0150, theta=-0.0073
crane_handover:    x=3.1939, y=-2.5503, theta=3.1275
warehouse_dropoff: x=2.2782, y=0.8154, theta=1.5540
```

Treat them as valid only if they still match the current map and physical cell.

## Crane coordinate and hook-height calibration

The crane uses its own absolute bridge/trolley coordinate system. Its values
must not be copied from the ROX/Nav2 map.

Stop the crane adapter while capturing, place the crane with approved local
controls, stop all axes, and run the sampling tool from the project environment.
The tool only reads OPC UA positions; it does not issue movement commands.

### Horizontal positions

At the physical source pickup location:

```bash
python3 scripts/crane_waypoint_tool.py --update source_station
```

Park ROX-Diff at its verified `crane_handover`, align the crane over the actual
transfer point, then capture:

```bash
python3 scripts/crane_waypoint_tool.py --update rox_handover
```

### Hook heights

Capture the minimum general horizontal-travel clearance:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist travel_safe_m
```

At the source attachment height:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist source_lower_m
```

At the height where the item fully clears the source:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist source_safe_lift_m
```

At the height where the item rests correctly on ROX-Diff:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist handover_lower_m
```

At the height where the hook/load interface is fully clear and ROX-Diff may
safely depart:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist handover_safe_lift_m
```

At the desired reset/start/end position:

```bash
python3 scripts/crane_waypoint_tool.py --update home
```

The uploaded project contains legacy starting values:

```yaml
source_station:       bridge=17.534 m, trolley=6.664 m
rox_handover:         bridge=19.501 m, trolley=5.302 m
travel_safe_m:        2.071 m
source_lower_m:       0.445 m
source_safe_lift_m:   2.071 m
handover_lower_m:     0.445 m
handover_safe_lift_m: 2.071 m
home:                 bridge=17.534 m, trolley=6.664 m, hoist=3.071 m
```

Do not assume those values match the present ROX handover geometry.

Each capture resets `configured: false`. After every value has been tested
independently and repeatedly without a payload, set:

```yaml
configured: true
```

Then synchronize the adapter's home coordinates and regenerate the crane order:

```bash
python3 scripts/generate_crane_order.py \
  --waypoints configs/crane_waypoints.yaml \
  --output examples/orders/order_ilmatar_v3.json \
  --update-fleet-env configs/fleet_control.env \
  --enable-crane
```

Restart the crane adapter after this command. The `resetAllHome` instant action
uses `CRANE_HOME_BRIDGE_M`, `CRANE_HOME_TROLLEY_M`, and `CRANE_HOME_HOIST_M`
loaded at adapter startup.

## Validation

```bash
python3 scripts/check_sequential_pickup_delivery.py
./scripts/run_static_checks.sh
```

If your local static checker intentionally treats tracked `crane_edge/access.txt`
as a warning, that warning does not affect scenario execution.

## Running the scenario

1. Start Mosquitto and the master controller.
2. Start the crane adapter and confirm the dashboard reports crane `ONLINE`,
   `AUTOMATIC`, and `WatchDogFault=false`.
3. Start Nav2 and the ROX-Diff VDA adapter and confirm ROX-Diff is `ONLINE` and
   localized.
4. Open the dashboard and choose **Sequential pickup and warehouse delivery**.
5. Review all 15 steps in the confirmation modal.
6. Start with no payload.
7. Use the green confirmation button only after completing the displayed manual
   task and clearing the next motion envelope.

The **Stop active scenario** button cancels the currently active crane or ROX
VDA command. During an operator wait, stopping ends the scenario without sending
additional motion.
