# ROX-Diff Mapping, Coordinates and VDA Orders

The DBot coordinates are invalid for ROX-Diff. A pose only has meaning in the exact map/frame in which it was recorded. A different robot, scanner mounting, footprint, map origin, localization configuration and crane placement require a new map and new poses.

This guide produces:

```text
ROX map:                         ~/maps/warehouse_case_study.yaml/.pgm
Captured poses:                 configs/rox_waypoints.yaml
Generated active VDA order:     examples/orders/order_rox_diff_v3.json
Pi initial-pose configuration:  ROX_INIT_* in configs/fleet_control.env
```

---

## 1. Verify native robot interfaces

Source the Neobotix underlay and project overlay. Discover and start the actual native ROX bringup installed on the delivered robot:

```bash
ros2 pkg prefix rox_bringup
find "$(ros2 pkg prefix rox_bringup)/share/rox_bringup/launch" \
  -maxdepth 1 -type f -name '*.launch.py' -printf '%f\n' | sort
ros2 launch rox_bringup <ACTUAL_BRINGUP_FILE>.launch.py --show-arguments
```

Start that file with `rox_type:=diff` and verified scanner/frame/namespace arguments.

Check:

```bash
ros2 topic echo /odom --once
ros2 topic echo /scan --once
ros2 topic echo /emergency_stop_state --once
ros2 topic echo /safety_state --once
ros2 run tf2_ros tf2_echo odom base_link
./scripts/check_rox_ros_interfaces.sh
```

The robot must teleoperate safely and its scanner/emergency-stop behavior must be correct before mapping.

---

## 2. Create the map

Use separate terminals.

Terminal A: native bringup.

Terminal B: discover the installed mapping launch file and its arguments:

```bash
find "$(ros2 pkg prefix rox_navigation)/share/rox_navigation/launch" \
  -maxdepth 1 -type f -iname '*map*.launch.py' -printf '%f\n' | sort
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py --show-arguments
mkdir -p ~/maps
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py \
  rox_type:=diff <OTHER_VERIFIED_ARGUMENTS>
```

Drive slowly through the full case-study area. Include:

- home/start area;
- a short commissioning target;
- path to the crane;
- handover region;
- drop-off region;
- enough surrounding walls/features for stable localization;
- safe approach and departure space around each target.

Revisit known areas to create loop closures. Avoid major environmental changes after mapping.

Save:

```bash
ros2 run nav2_map_server map_saver_cli \
  -f ~/maps/warehouse_case_study
```

Expected files:

```text
~/maps/warehouse_case_study.pgm
~/maps/warehouse_case_study.yaml
```

Saving outside the Neobotix package source means no package rebuild is required merely to use the map by absolute path.

---

## 3. Start localization and Nav2

Stop mapping, keep/start native bringup, then:

```bash
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  map:=$HOME/maps/warehouse_case_study.yaml
```

Verify the actual installed launch arguments:

```bash
ros2 launch rox_navigation navigation.launch.py --show-arguments
```

In RViz:

1. set the initial pose;
2. wait for localization to settle;
3. inspect scanner alignment and costmaps;
4. send at least three ordinary Nav2 goals;
5. confirm the robot reaches both position and orientation repeatably.

Check:

```bash
ros2 run tf2_ros tf2_echo map base_link
ros2 action list -t | grep navigate_to_pose
```

A VDA adapter cannot compensate for a broken map, localization, footprint, costmap, controller or transform tree.

---

## 4. Choose physical waypoints

Recommended first set:

| Waypoint | Purpose | Guidance |
|---|---|---|
| `home` | order start/end | open, repeatable localization area |
| `short_test` | commissioning | short clear move from home, no crane interaction |
| `crane_handover` | AMR–crane rendezvous | load aligned with crane; scanner/footprint clearance verified |
| `warehouse_dropoff` | destination | open approach, turning and braking space |

At the handover pose, verify more than the robot center point:

- full ROX footprint;
- payload footprint;
- scanner protective fields;
- crane reach and hook/load alignment;
- safe departure direction;
- no need for an impossible in-place rotation;
- sufficient localization features near the crane.

---

## 5. Capture poses

Create the working file on the ROX checkout:

```bash
cd ~/VDA5050-Paper-Dev
cp configs/rox_waypoints.yaml.example configs/rox_waypoints.yaml
```

For each pose:

1. manually drive to the exact desired placement;
2. wait for localization to settle;
3. inspect `map -> base_link` in RViz/TF;
4. run the capture command;
5. move away and return to verify repeatability.

Commands:

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name home \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name short_test \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name crane_handover \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name warehouse_dropoff \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

Stored values:

- `x`, `y`: metres in ROS `map` frame;
- `theta`: radians;
- `map_id`: stable project-level identifier;
- `allowed_deviation_xy`: circular position tolerance used to construct the v3 ellipse;
- `allowed_deviation_theta`: orientation tolerance in radians.

The capture tool updates the pose and preserves the tolerance fields already present in the template.

---

## 6. Validate each waypoint with ordinary Nav2

Before enabling generation:

- send an RViz/Nav2 goal to each exact captured pose;
- repeat each pose multiple times from different approach directions;
- measure handover alignment repeatability;
- verify scanner and costmap clearance;
- verify payload and crane reach;
- confirm the robot can exit safely.

Only then change:

```yaml
configured: true
```

Do not commit `configs/rox_waypoints.yaml` if the coordinates are site-sensitive or likely to change. The template remains committed.

---

## 7. Copy waypoint data to the Pi

The Pi needs the VDA node coordinates, but does not need to run ROS or host the robot map.

From ROX:

```bash
scp configs/rox_waypoints.yaml \
  pi@192.168.50.115:/home/pi/VDA5050-Paper-Dev/configs/
```

Use the real Pi username/repository path.

---

## 8. Generate the short test order

On the Pi:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --schema schemas/vda5050_v3/order.schema \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Restart the master after updating the environment file.

The short route is:

```text
test_node1 = home
test_edge1
test_node2 = short_test + holdPose
```

The first node is the current/start pose. The second node is a short low-speed target. `holdPose` keeps the order visibly blocked until the master sends `releaseHold`.

---

## 9. Generate the full case-study order

After the short route and full ordinary Nav2 route are safe:

```bash
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_crane_case_study.yaml \
  --schema schemas/vda5050_v3/order.schema \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Full logical route:

```text
node1 = home
edge1
node2 = crane_handover + holdPose
edge2
node3 = warehouse_dropoff
edge3
node4 = home
```

The generator:

- refuses `configured: false`;
- requires all route waypoint names to exist;
- assigns continuous even node / odd edge sequence IDs;
- creates v3 node positions and tolerance ellipses;
- adds declared node actions;
- validates against official `order.schema`;
- writes the active order;
- updates the Pi initialization pose from the first route node.

---

## 10. Tolerances

The example starts with:

```text
ordinary nodes:     0.20 m XY, 0.20 rad theta
handover node:      0.12 m XY, 0.15 rad theta
```

These are commissioning defaults, not validated values. Tighten the crane handover tolerance only after collecting repeated approach data. If it is too tight, normal localization variance can reject/retry valid arrivals; if too loose, crane/load alignment may be inadequate.

Edit tolerances in `configs/rox_waypoints.yaml` and regenerate the order.

---

## 11. First-node requirement

A new VDA order starts at a node that is expected to be trivially reachable/current. The adapter therefore requires:

- valid `map -> base_link` localization;
- matching `mapId`;
- physical distance to the first node within the configured tolerance.

In dry-run mode, the first node is assumed current so MQTT/state logic can be tested without TF. In real-navigation mode, an out-of-range start is rejected. Always place/localize ROX at `home` before sending the generated order.

`initializePosition` publishes `/initialpose` using the captured first-node pose. It initializes localization; it does not drive the robot to that pose.

---

## 12. ROS frames versus VDA identifiers

Do not confuse:

- `map`, `odom`, `base_link`: ROS frames;
- `mapId`: VDA/project identifier for the coordinate system;
- `node1`, `node2`: logical VDA order node IDs;
- `home`, `crane_handover`: YAML waypoint keys.

The master matches crane `node2` and ROX `node2` as a logical rendezvous. It does not assume the crane and robot use the same physical coordinates.

---

## 13. Changing the route later

1. capture a new waypoint in the same map;
2. verify it with ordinary Nav2;
3. add it to a route YAML;
4. keep unique IDs and route order;
5. regenerate and validate JSON;
6. dry-run;
7. run at low speed;
8. update the master handover node configuration if the rendezvous ID changed.

If the map origin or map data changes materially, capture all poses again rather than reusing old numbers.
