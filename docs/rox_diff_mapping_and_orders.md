# ROX-Diff map, waypoint and order workflow

This guide covers the commissioned Neobotix ROX-Diff setup used by this repository.
For the compact command reference, see [ROX_COMMANDS.md](ROX_COMMANDS.md).

## Known site values

| Item | Value |
|---|---|
| ROS distribution | `jazzy` |
| Neobotix workspace | `~/ros2_workspace` |
| Project on ROX | `~/Projects/VDA5050-Paper-Dev` |
| ROS map frame | `map` |
| Robot base frame | `base_link` |
| Logical VDA map ID | `df_map` |
| Map YAML | `/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml` |
| Map image | `/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.pgm` |

The native hardware bringup is already started at boot by `ROS_AUTOSTART.sh`:

```bash
source ~/ros2_workspace/install/setup.bash
sleep 2
ros2 launch rox_bringup bringup_launch.py \
  rox_type:=diff \
  imu_enable:=True \
  use_d435:=True \
  enable_io_board:=True
```

Do **not** start another `rox_bringup` instance.

## Build once after pulling changes

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
```

## Start Nav2 with the saved map

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh nav
```

In RViz, set an initial pose with **2D Pose Estimate** and confirm the laser scan aligns with the map. Then check:

```bash
./scripts/rox.sh status
./scripts/rox.sh tf
```

The `/navigate_to_pose` action and `map -> base_link` transform are expected only after Nav2/localization is active.

## Capture named waypoints

Move the robot to each intended physical pose, let localization settle, then run:

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture short_test
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

Each command records the current `map -> base_link` pose in `configs/rox_waypoints.yaml`. Recapturing any point automatically changes `configured` to `false`, because the edited pose must be verified again.

The logical `map_id: df_map` is project metadata. Nav2 loads the actual map through the `df_map.yaml` path. The IDs are kept the same here to reduce configuration mistakes.

## Display waypoints in RViz

Start the marker publisher in another terminal:

```bash
./scripts/rox.sh visualize
```

In RViz, add a **MarkerArray** display using:

```text
/rox_waypoints/markers
```

The markers show the position, heading and configured tolerances. They are visual displays, not clickable navigation controls.

## Send an exact waypoint to Nav2

List the available points:

```bash
./scripts/rox.sh list
```

Validate a goal without moving:

```bash
./scripts/rox.sh goto-dry crane_handover
```

Send the exact YAML pose:

```bash
./scripts/rox.sh goto crane_handover
```

Equivalent direct ROS command:

```bash
ros2 run rox_vda5050_adapter goto_waypoint \
  --name crane_handover \
  --waypoint-file configs/rox_waypoints.yaml
```

The utility:

1. reads `x`, `y` and `theta` from the YAML;
2. converts planar yaw to a quaternion;
3. sends `nav2_msgs/action/NavigateToPose` to `/navigate_to_pose`;
4. waits for Nav2 to finish;
5. reads the final `map -> base_link` transform;
6. compares final XY/yaw error against the waypoint tolerances;
7. prints `WAYPOINT CHECK: PASS` or `FAIL` and returns a non-zero exit status on failure.

A Nav2 success does not alone prove the stricter project tolerance was met; the final TF comparison is the commissioning check.

## Approve the waypoint set

Test every point repeatedly from different starting poses. Check the complete robot and payload footprint, final yaw, scanner behavior, departure path, and crane alignment where relevant.

Only after the physical tests pass:

```bash
nano configs/rox_waypoints.yaml
```

Set:

```yaml
configured: true
```

Do not set the flag merely to bypass order-generation validation.

## Generate the VDA 5050 order

Copy the verified waypoint file to the Raspberry Pi if the repositories are separate:

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

The generated VDA nodes use the same exact map coordinates as the commissioned waypoint file.
