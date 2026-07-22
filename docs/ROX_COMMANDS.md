# ROX-Diff Command Reference

This is the main command sheet for the ROX-Diff side of the VDA 5050 case study. Run commands from:

```bash
cd ~/Projects/VDA5050-Paper-Dev
```

The native ROX hardware stack already starts at boot through `ROS_AUTOSTART.sh`:

```bash
source ~/ros2_workspace/install/setup.bash
sleep 2
ros2 launch rox_bringup bringup_launch.py \
  rox_type:=diff \
  imu_enable:=True \
  use_d435:=True \
  enable_io_board:=True
```

Do **not** start a second `rox_bringup` process.

## One command entry point

Use:

```bash
./scripts/rox.sh help
```

The script sources ROS Jazzy, the Neobotix underlay and the project overlay in the correct order. It also applies these current defaults:

```text
ROS_DISTRO=jazzy
NEOBOTIX_WS=$HOME/ros2_workspace
RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
ROS_DOMAIN_ID=0
VDA_MAP_ID=df_map
```

## First build or after source changes

```bash
./scripts/rox.sh build
source ros2_ws/install/setup.bash
./scripts/rox.sh status
```

Expected package tools include:

```text
capture_waypoint
goto_waypoint
waypoint_visualizer
rox_vda5050_adapter
```

## Normal commissioning terminals

### Terminal 1 — Nav2, AMCL and RViz

```bash
./scripts/rox.sh nav
```

This resolves the installed map path automatically. The current map pair is:

```text
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.pgm
```

Equivalent direct launch:

```bash
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  use_amcl:=True \
  use_rviz:=True \
  map:=/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml
```

Set the robot's initial pose in RViz and confirm the laser scan aligns with the map.

### Terminal 2 — waypoint markers

```bash
./scripts/rox.sh visualize
```

Add a `MarkerArray` display in RViz and select:

```text
/rox_waypoints/markers
```

The markers show the exact YAML coordinates, heading and tolerance graphics. They do not command motion.

### Terminal 3 — inspect, capture or command waypoints

List exact values:

```bash
./scripts/rox.sh list
```

Capture the current localized robot pose:

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture short_test
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

Print the goal without motion:

```bash
./scripts/rox.sh goto-dry crane_handover
```

Send the exact pose to Nav2:

```bash
./scripts/rox.sh goto crane_handover
```

Equivalent direct command:

```bash
ros2 run rox_vda5050_adapter goto_waypoint \
  --name crane_handover \
  --waypoint-file configs/rox_waypoints.yaml
```

`goto_waypoint` performs four checks:

1. validates the YAML and waypoint name;
2. converts `theta` to a quaternion and sends the exact pose to `/navigate_to_pose`;
3. waits for the Nav2 action result;
4. reads the final `map -> base_link` transform and compares it with `allowed_deviation_xy` and `allowed_deviation_theta`.

It prints `WAYPOINT CHECK: PASS` only when Nav2 succeeds and the final TF pose is inside both YAML tolerances. Nav2 may report success while the stricter project tolerance fails; this is intentional and useful during commissioning.

`configured: false` produces a warning but is allowed, because exact Nav2 return tests are part of the process used before setting `configured: true`. For operational scripts that must refuse unapproved coordinates, add:

```bash
--require-configured
```

## Interface and TF checks

```bash
./scripts/rox.sh interfaces
./scripts/rox.sh status
./scripts/rox.sh tf
```

Before Nav2 starts, it is normal for `/navigate_to_pose` and the `map -> base_link` transform to be absent. After Nav2/AMCL is running and the initial pose is set, both must be available.

Verified hardware topics are:

```text
/tf                       tf2_msgs/msg/TFMessage
/tf_static                tf2_msgs/msg/TFMessage
/odom                     nav_msgs/msg/Odometry
/battery_state            sensor_msgs/msg/BatteryState
/emergency_stop_state     neo_msgs2/msg/EmergencyStopState
/safety_state             neo_msgs2/msg/SafetyState
/scan                     sensor_msgs/msg/LaserScan
```

## VDA adapter commands

Dry run first:

```bash
./scripts/rox.sh adapter-dry
```

Real Nav2 movement only after dry-run and ordinary waypoint tests pass:

```bash
./scripts/rox.sh adapter-real
```

## Useful overrides

Use a different map:

```bash
ROX_MAP_YAML=/absolute/path/map.yaml ./scripts/rox.sh nav
```

Use a different waypoint file:

```bash
ROX_WAYPOINT_FILE=/absolute/path/waypoints.yaml ./scripts/rox.sh visualize
ROX_WAYPOINT_FILE=/absolute/path/waypoints.yaml ./scripts/rox.sh goto home
```

Use a different logical map ID:

```bash
VDA_MAP_ID=df_map ./scripts/rox.sh capture home
```

The logical `map_id` does not load the ROS map. It must remain consistent across the waypoint file, generated VDA order and adapter configuration.

## Recommended verification sequence

For every waypoint:

```bash
./scripts/rox.sh goto-dry WAYPOINT
./scripts/rox.sh goto WAYPOINT
```

Repeat the real command several times from different starting poses. Check the full footprint, payload clearance, final yaw, scanner fields, departure path and—in particular for `crane_handover`—crane reach and hook/load alignment.

Only after all waypoints pass repeatedly:

```bash
nano configs/rox_waypoints.yaml
```

Set:

```yaml
configured: true
```

Do not use this flag to bypass an unverified coordinate set.
