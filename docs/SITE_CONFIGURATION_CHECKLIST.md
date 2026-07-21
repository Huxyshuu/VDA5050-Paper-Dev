# Site Configuration Checklist

Complete this file on the real equipment. Do not replace unknown values with guesses.

## Commands for launch arguments
ros2 launch rox_bringup bringup_launch.py --show-arguments
ros2 launch rox_navigation mapping.launch.py --show-arguments
ros2 launch rox_navigation navigation.launch.py --show-arguments
ros2 launch rox_navigation localization_neo.launch.py --show-arguments


## Raspberry Pi and network

- [x] Pi username: `raspberrypi`
- [x] Pi hostname: `raspberrypi`
- [x] Pi Ethernet / DTLabOpen IPv4: `192.168.50.115`
- [ ] Pi Ethernet prefix length: `____________________`
- [x] Pi Wi-Fi / Ilmatar IPv4: `192.168.0.116`
- [ ] Pi Wi-Fi prefix/gateway: `____________________`
- [x] ROX-Diff / DTLabOpen IPv4: `192.168.50.50`
- [ ] ROX-Diff DTLabOpen interface and prefix: `____________________`
- [x] DTLabOpen gateway remains: `192.168.1.1`
- [x] MQTT port: `1883`
- [x] Pi project path: `~/VDA5050-Paper-Dev`
- [x] ROX project path: `~/Projects/VDA5050-Paper-Dev`
- [x] Flask address/port: `192.168.50.115:5000`
- [x] Pi and ROX can communicate directly and bidirectionally.
- [ ] `ip route get 192.168.50.50` on Pi selects Ethernet.
- [ ] `ip route get 192.168.50.115` on ROX selects its DTLabOpen interface.
- [ ] ROX can open TCP connection to MQTT port.
- [ ] MQTT is restricted to loopback and the trusted DTLabOpen-facing interface.
- [ ] Authentication/TLS plan documented for non-lab use.

## Neobotix delivered software

### ROS environment

- [x] ROS distribution: `jazzy`
- [x] ROS middleware: `rmw_cyclonedds_cpp`
- [x] ROS domain ID: `0`
- [x] Neobotix workspace: `/home/neobotix/ros2_workspace`

### Native ROX bringup at boot

- [x] Native hardware bringup is started automatically when the robot boots by `ROS_AUTOSTART.sh`.
- [ ] Exact path and boot mechanism that invokes `ROS_AUTOSTART.sh`: `____________________`
- [x] Autostart script content:

```bash
source ~/ros2_workspace/install/setup.bash
sleep 2
ros2 launch rox_bringup bringup_launch.py rox_type:=diff imu_enable:=True use_d435:=True enable_io_board:=True
```

- [x] `rox_bringup` launch file: `bringup_launch.py`
- [x] Actual physical-robot arguments:
  - `rox_type:=diff`
  - `imu_enable:=True`
  - `use_d435:=True`
  - `enable_io_board:=True`
- [x] Robot namespace is not explicitly passed and therefore remains empty.
- [x] Scanner type is not explicitly passed and therefore uses the launch default: `nanoscan`.
- [x] No robot arm or gripper is enabled by this command.
- [x] Do **not** launch `bringup_launch.py` again in a normal commissioning terminal. A second bringup may create duplicate ROS nodes and TF publishers or compete for the same hardware devices.
- [ ] After each reboot, verify the autostarted bringup with `ros2 node list`, `ros2 topic list`, and `./scripts/check_rox_ros_interfaces.sh`.

### Mapping and navigation launch files

- [x] `rox_navigation` mapping launch file: `mapping.launch.py`
- [x] Mapping defaults:
  - `autostart:=True`
  - `use_lifecycle_manager:=False`
  - `use_sim_time:=False`
  - `slam_params_file:=/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/configs/mapping.yaml`
- [x] An existing commissioned map is available, so mapping is not required for the normal startup path.
- [ ] Optional remapping command, only if the environment changes or `df_map` proves unsuitable: `ros2 launch rox_navigation mapping.launch.py`

- [x] Navigation launch file: `navigation.launch.py`
- [x] Navigation package arguments verified:
  - override package default with `rox_type:=diff`
  - `use_sim_time:=False`
  - `autostart:=True`
  - `robot_namespace:=`
  - `use_multi_robots:=False`
  - `head_robot:=False`
  - set `use_amcl:=True` for localization on the commissioned saved map
  - replace the default map with the commissioned map YAML path
  - leave `nav2_params_file:=` empty to use the robot-type default unless a verified site-specific file is created
  - `use_rviz:=True`
- [ ] Start and verify navigation with the existing map:

```bash
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  use_amcl:=True \
  map:=/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml
```

- [x] Localization launch file: `localization_neo.launch.py`
- [x] `localization_neo.launch.py` exposes no launch arguments.
- [x] `frame_type` is not exposed by the installed bringup, mapping, navigation, or localization launch files. Do not pass it to these commands.

### Verified ROS interfaces with native bringup running

The following were observed from `./scripts/check_rox_ros_interfaces.sh` while the boot-time native bringup was running:

- [x] Dynamic TF topic: `/tf` — `tf2_msgs/msg/TFMessage`
- [x] Static TF topic: `/tf_static` — `tf2_msgs/msg/TFMessage`
- [x] Odometry topic: `/odom` — `nav_msgs/msg/Odometry`
- [x] Battery topic: `/battery_state` — `sensor_msgs/msg/BatteryState`
- [x] Emergency-stop topic: `/emergency_stop_state` — `neo_msgs2/msg/EmergencyStopState`
- [x] Safety-state topic: `/safety_state` — `neo_msgs2/msg/SafetyState`
- [x] Lidar topic: `/scan` — `sensor_msgs/msg/LaserScan`

Emergency-stop message interpretation:

- `emergency_state=0` (`EMFREE`): normal operation
- `emergency_state=1` (`EMSTOP`): emergency stop active
- `emergency_state=2` (`EMCONFIRMED`): stop acknowledged and system reinitializing
- Cause flags: `emergency_button_stop`, `scanner_stop`, and `software_stop`

Safety-state message interpretation:

- `current_safety_field`: active scanner field-set ID
- `triggered_cutoff_paths[7]`: cutoff-path trigger states

### Interfaces not yet present at this stage

- [ ] Nav2 `NavigateToPose` action: **not detected while only native bringup was running**. This is expected before the navigation stack is launched. Re-run the interface check after Part C and record the exact action name: `____________________`
- [ ] `map -> base_link` TF sample: **not available while mapping/localization/Nav2 was not running**. Verify after launching mapping or saved-map localization/navigation.
- [ ] Base frame confirmed from active TF tree: `____________________`
- [ ] Map frame confirmed from active TF tree: `____________________`

## Map and navigation

- [x] Map ID: `df_map`
- [x] Installed map directory: `/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps`
- [x] Map YAML absolute path: `/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml`
- [x] Map image absolute path: `/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.pgm`
- [ ] Confirm that `df_map.yaml` references `df_map.pgm` correctly.
- [ ] Copy both map files outside the workspace `install/` tree as a backup; a workspace rebuild can replace generated install content.
- [ ] Map backup path: `____________________`
- [ ] Lidar alignment verified in RViz.
- [ ] Robot footprint and payload footprint verified.
- [ ] Global/local costmaps verified.
- [ ] Controller and planner verified.
- [ ] Commissioning maximum linear speed: `____________________`
- [ ] Commissioning maximum angular speed: `____________________`
- [ ] Emergency stops accessible throughout test route.
- [ ] After navigation starts, `ros2 action list -t` contains the Nav2 `NavigateToPose` action.
- [ ] After localization starts, `ros2 run tf2_ros tf2_echo map base_link` produces a stable transform.

## Captured waypoints

| Waypoint | x (m) | y (m) | theta (rad) | XY tolerance (m) | theta tolerance (rad) | Repeated Nav2 test passed |
|---|---:|---:|---:|---:|---:|---|
| home | | | | | | [ ] |
| short_test | | | | | | [ ] |
| crane_handover | | | | | | [ ] |
| warehouse_dropoff | | | | | | [ ] |

- [ ] All waypoints belong to the same saved map.
- [ ] `configs/rox_waypoints.yaml` changed to `configured: true` only after verification.
- [ ] Short order generated and validated.
- [ ] Full route generated and validated.

## VDA identities and topics

- [ ] Version: `3.0.0`
- [ ] ROX manufacturer: `neobotix`
- [ ] ROX serial number: `rox_diff_1` / actual configured: `____________________`
- [ ] ROX topic root: `____________________`
- [ ] Crane manufacturer: `konecranes`
- [ ] Crane serial number: `ilmatar_1` / actual configured: `____________________`
- [ ] Crane topic root: `____________________`
- [ ] Factsheets contain verified physical/capability values.
- [ ] Factsheet identities match adapter/master identities exactly.

## Crane and handover

- [ ] OPC UA URL configured outside Git.
- [ ] Access code configured outside Git.
- [ ] Crane automatic mode requirement verified.
- [ ] Homing/preflight requirement verified.
- [ ] `ALLOW_UNHOMED_START=false` for motion tests.
- [ ] Crane handover node ID: `____________________`
- [ ] ROX handover node ID: `____________________`
- [ ] Automatic release action ID: `____________________`
- [ ] Manual release action ID: `____________________`
- [ ] Safe-lift completion action ID: `____________________`
- [ ] ROX hold action ID: `____________________`
- [ ] Manual release time-to-live: `____________________`
- [ ] Exact action IDs checked against both order files.
- [ ] Free-text `information[]` excluded from safety/control decisions.
- [ ] Crane-only test passed without load.
- [ ] ROX-only full route passed without crane motion.
- [ ] Coordinated no-load test passed repeatedly.
- [ ] Failure/recovery procedure documented for broker loss, adapter loss, localization loss, Nav2 failure and scanner intervention.

## Sign-off

- Test date: `____________________`
- Software commit/package: `____________________`
- Operator: `____________________`
- Observer/safety responsible person: `____________________`
- Result and open issues: `____________________________________________________________`
