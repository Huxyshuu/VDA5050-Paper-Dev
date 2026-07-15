# ROX-Diff VDA 5050 ROS 2 overlay

This workspace contains only project-specific overlay packages:

- `rox_vda5050_adapter`: direct VDA 5050 v3.0 MQTT-to-Nav2 adapter;
- `vda5050_schemas_v3`: installs the official JSON schemas into the ROS share tree.

Do not replace the Neobotix ROX workspace with this directory. Build it as a separate
overlay on the ROX onboard computer:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash   # Neobotix underlay
mkdir -p ~/vda5050_ws/src
# Copy or clone both packages into ~/vda5050_ws/src/
cd ~/vda5050_ws
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash
```

Always source the Neobotix workspace before this overlay so Nav2 and the robot-specific
message packages are available.
