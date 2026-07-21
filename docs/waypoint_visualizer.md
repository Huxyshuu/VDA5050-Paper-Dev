# ROX waypoint visualizer patch

This patch adds an RViz visualizer to the existing ROS 2 package:

```text
ros2_ws/src/rox_vda5050_adapter
```

It reads `configs/rox_waypoints.yaml` and publishes persistent
`visualization_msgs/msg/MarkerArray` markers on:

```text
/rox_waypoints/markers
```

For every waypoint, RViz can show:

- a position marker;
- an arrow for `theta`;
- the waypoint name and numeric pose;
- a circle for `allowed_deviation_xy`;
- two rays for `theta ± allowed_deviation_theta`;
- the file's `map_id` and `configured` state.

The node checks the YAML once per second and republishes automatically after a
successful file change. Invalid edits do not erase the last valid markers.

## 1. Apply at the project root

Copy this folder onto the ROX-Diff and run:

```bash
cd ~/Projects/VDA5050-Paper-Dev
python3 /path/to/VDA5050_waypoint_visualizer_patch/apply_patch.py "$PWD"
```

The installer:

- adds `waypoint_visualizer.py` to the Python package;
- adds `waypoint_visualizer.launch.py`;
- adds `scripts/run_waypoint_visualizer.sh`;
- adds `docs/waypoint_visualizer.md`;
- adds the `waypoint_visualizer` console entry point to `setup.py`;
- adds missing RViz/YAML runtime dependencies to `package.xml`;
- backs up `setup.py` and `package.xml` before changing them.

## 2. Install dependencies and rebuild

```bash
cd ~/Projects/VDA5050-Paper-Dev
export ROS_DISTRO=${ROS_DISTRO:-jazzy}
export NEOBOTIX_WS=${NEOBOTIX_WS:-$HOME/ros2_workspace}
export AMENT_TRACE_SETUP_FILES=""

source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"

rosdep install --from-paths ros2_ws/src --ignore-src -r -y
./scripts/build_rox_overlay.sh
source ros2_ws/install/setup.bash
```

Confirm the executable and launch file are installed:

```bash
ros2 pkg executables rox_vda5050_adapter | grep waypoint_visualizer
ros2 launch rox_vda5050_adapter waypoint_visualizer.launch.py --show-arguments
```

## 3. Start it

The helper script uses the current repository's waypoint file:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/run_waypoint_visualizer.sh
```

Equivalent direct launch:

```bash
ros2 launch rox_vda5050_adapter waypoint_visualizer.launch.py \
  waypoint_file:="$HOME/Projects/VDA5050-Paper-Dev/configs/rox_waypoints.yaml" \
  frame_id:=map
```

Do not start a second native ROX bringup. The visualizer is only an additional
publisher and does not command motion.

## 4. Add the markers in the existing RViz

In the RViz window started with Nav2:

1. Set **Fixed Frame** to `map`.
2. Select **Add**.
3. Select **By topic**.
4. Expand `/rox_waypoints/markers`.
5. Add the **MarkerArray** display.

If `By topic` does not list it, add **MarkerArray** manually and set **Topic**
to `/rox_waypoints/markers`.

Verify the publisher:

```bash
ros2 topic info /rox_waypoints/markers --verbose
ros2 topic echo /rox_waypoints/markers --once
```

The publisher uses reliable, transient-local QoS. Therefore the most recent
markers should appear even when the RViz display is added after the visualizer
starts.

## 5. Edit and reload

Edit normally:

```bash
nano ~/Projects/VDA5050-Paper-Dev/configs/rox_waypoints.yaml
```

Save the file. The visualizer detects the modification and updates RViz within
about one second. The node warns when two waypoints have exactly the same pose,
which helps detect untouched `0.0` placeholders.

## Parameters

```text
waypoint_file      required YAML path
frame_id           map
marker_topic       /rox_waypoints/markers
reload_period      1.0 seconds
show_tolerances    true
marker_diameter    0.18 metres
arrow_length       0.55 metres
label_height       0.42 metres
text_size          0.16 metres
```

Example without tolerance graphics:

```bash
ros2 launch rox_vda5050_adapter waypoint_visualizer.launch.py \
  waypoint_file:="$PWD/configs/rox_waypoints.yaml" \
  show_tolerances:=false
```

## Important interpretation

The markers use the coordinates directly in the ROS `map` frame. `map_id` is
shown as metadata; it is not used as a TF frame and it does not load a map.
Nav2 must still be started with `df_map.yaml`, and RViz must use `map` as its
Fixed Frame.

The tolerance graphics are commissioning aids. They do not alter Nav2 goal
tolerances and are not safety functions.
