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
- [x] Flask address/port: `192.168.50.115:5000`
- [x] Pi and ROX can communicate directly and bidirectionally.
- [ ] `ip route get 192.168.50.50` on Pi selects Ethernet.
- [ ] `ip route get 192.168.50.115` on ROX selects its DTLabOpen interface.
- [ ] ROX can open TCP connection to MQTT port.
- [ ] MQTT is restricted to loopback and the trusted DTLabOpen-facing interface.
- [ ] Authentication/TLS plan documented for non-lab use.

## Neobotix delivered software

- [x] ROS distribution: `jazzy`
- [x] Neobotix workspace: `/home/neobotix/ros2_workspace`
- [x] `rox_bringup` launch file: `bringup_launch.py`
- [x] Intended physical robot type: `rox_type:=diff`
- [x] Default robot namespace: empty (`robot_namespace:=`)
- [x] Default scanner type: `scanner_type:=nanoscan`
- [x] Default IMU setting: `imu_enable:=False`
- [x] No robot arm configured: `arm_type:=`
- [x] UR DC arm disabled: `use_ur_dc:=False`
- [x] Mock arm disabled: `use_mock_arm:=False`
- [x] Default initial arm controller: `initial_controller_arm:=scaled_joint_trajectory_controller`
- [x] Default arm IP, only relevant if an arm is later enabled: `robot_ip:=192.168.1.102`
- [x] Default arm controller file: `/home/neobotix/ros2_workspace/install/rox_bringup/share/rox_bringup/configs/ur/ur_controllers.yaml`
- [x] No gripper configured: `gripper_type:=`
- [x] IO board disabled by default: `enable_io_board:=False`
- [x] RealSense D435 disabled by default: `use_d435:=False`
- [ ] Exact bringup command used on the physical ROX-Diff: `____________________`

- [x] `rox_navigation` mapping launch file: `mapping.launch.py`
- [x] Mapping defaults:
  - `autostart:=True`
  - `use_lifecycle_manager:=False`
  - `use_sim_time:=False`
  - `slam_params_file:=/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/configs/mapping.yaml`
- [ ] Exact mapping command used: `____________________`

- [x] Navigation launch file: `navigation.launch.py`
- [x] Navigation defaults:
  - `rox_type:=argo` by package default; must be overridden with `rox_type:=diff`
  - `use_sim_time:=False`
  - `autostart:=True`
  - `robot_namespace:=`
  - `use_multi_robots:=False`
  - `head_robot:=False`
  - `use_amcl:=False` by package default; set to `True` when localizing on the saved map
  - `map:=/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/neo_workshop.yaml` by default; replace with the commissioned map path
  - `nav2_params_file:=` to use the robot-type default
  - `use_rviz:=True`
- [ ] Exact navigation command used: `____________________`

- [x] Localization launch file: `localization_neo.launch.py`
- [x] `localization_neo.launch.py` exposes no launch arguments.
- [x] `frame_type` is not exposed by the installed `bringup_launch.py`, `mapping.launch.py`, `navigation.launch.py`, or `localization_neo.launch.py`; do not supply it unless another installed launch file explicitly supports it.
- [ ] Lidar topic: `____________________`
- [x] Odometry topic: `/odom`
- [x] Battery topic and message type: `/battery_state`
- [ ] Emergency-stop topic and message type: `____________________`
- [ ] Safety-state topic and message type: `____________________`
- [ ] Nav2 action name: `____________________`
- [ ] Base frame: `____________________`
- [ ] Map frame: `____________________`

## Map and navigation

- [ ] Map ID: `____________________`
- [ ] Map YAML absolute path: `____________________`
- [ ] Map image absolute path: `____________________`
- [ ] Map backed up.
- [ ] Lidar alignment verified in RViz.
- [ ] Robot footprint and payload footprint verified.
- [ ] Global/local costmaps verified.
- [ ] Controller and planner verified.
- [ ] Commissioning maximum linear speed: `____________________`
- [ ] Commissioning maximum angular speed: `____________________`
- [ ] Emergency stops accessible throughout test route.

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
