# ROX-Diff remote operator workstation

This guide configures an Ubuntu 24.04 computer as a complete ROX-Diff operator workstation. Hardware bringup, safety interfaces, localization, Nav2 and pose persistence remain on the ROX-Diff. RViz, waypoint visualization and ROS command clients run locally on the operator computer.

The resulting daily workflow is:

```bash
rox nav
rox goto home
rox nav-stop
```

No manual `source` commands or Remmina session are required.

## 1. Architecture

```text
Operator laptop/computer                         ROX-Diff 192.168.50.50
────────────────────────                         ──────────────────────
ROS 2 Jazzy Desktop                              boot-time rox_bringup
CycloneDDS + static peer 192.168.50.50   <DDS>   localization and Nav2
Neobotix description/navigation packages         pose persistence
project ROS overlay                              VDA 5050 adapter
local RViz and waypoint markers         <SSH>    managed headless Nav2 start/stop
```

Only the ROX-Diff executes the navigation controller and hardware commands. The workstation only visualizes and sends ROS actions.

## 2. Prerequisites on the operator computer

Required:

- Ubuntu 24.04;
- ROS 2 Jazzy Desktop;
- `rmw_cyclonedds_cpp`;
- the Neobotix ROX workspace built locally, including `rox_description` and `rox_navigation`;
- this repository cloned from `main`;
- network reachability to `192.168.50.50`.

The setup supports common Neobotix workspace locations automatically:

```text
~/neobotix_view_ws
~/rox_ws
~/neobotix_ws
~/ros2_workspace
```

An explicit path is recommended.

## 3. Keep both repositories on `main`

On the operator computer:

```bash
cd ~/Projects/VDA5050-Paper-Dev
git switch main
git pull --ff-only
```

On the ROX-Diff:

```bash
ssh neobotix@192.168.50.50
cd ~/Projects/VDA5050-Paper-Dev
git switch main
git pull --ff-only
```

The waypoint YAML should be committed and synchronized so the laptop and robot use the same named poses.

## 4. Build the project overlay on each computer

Operator computer:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/install_rox_shell.sh operator \
  --neobotix-ws "$HOME/neobotix_view_ws"
exec bash
rox build
```

Replace `~/neobotix_view_ws` with the actual workspace path when different.

ROX-Diff:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/install_rox_shell.sh robot \
  --neobotix-ws "$HOME/ros2_workspace"
exec bash
rox build
```

The installer writes machine-local settings to:

```text
~/.config/rox/rox.env
```

and adds one managed block to `~/.bashrc`. New terminals automatically source, in order:

1. `/opt/ros/jazzy/setup.bash`;
2. the detected Neobotix workspace;
3. this repository's `ros2_ws/install/setup.bash`.

It also defines the global `rox` shell function, so commands work from any directory.

## 5. Configure password-free SSH once

The laptop must be able to start and stop managed headless Nav2 without asking for a password.

```bash
ssh-keygen -t ed25519
ssh-copy-id neobotix@192.168.50.50
ssh -o BatchMode=yes neobotix@192.168.50.50 true
```

The last command should finish silently with exit status zero.

This SSH access only manages processes in the project repository. It does not replace ROS 2 communication; RViz and goal clients still communicate through DDS.

## 6. Verify the complete workstation

Open a new laptop terminal and run:

```bash
rox doctor
```

The required local package checks should pass:

```text
rox_description
rox_navigation
rox_vda5050_adapter
```

The doctor also checks:

- CycloneDDS settings;
- ping to `192.168.50.50`;
- password-free SSH;
- `/tf`, `/robot_description` and `/scan` when visible;
- `/navigate_to_pose` when Nav2 is active.

Inspect all resolved settings with:

```bash
rox env
```

Expected operator values include:

```text
ROX_EFFECTIVE_ROLE=operator
RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
ROS_DOMAIN_ID=169
ROS_AUTOMATIC_DISCOVERY_RANGE=SUBNET
ROS_STATIC_PEERS=192.168.50.50
```

## 7. Normal daily operation from the laptop

### Start or connect to navigation

```bash
rox nav
```

The command performs the following automatically:

1. checks whether `/navigate_to_pose` is already available;
2. if Nav2 is absent, connects to the ROX-Diff through SSH;
3. starts headless Nav2 with pose persistence on the robot;
4. waits until the navigation action is discoverable;
5. opens the standard Neobotix Nav2 RViz configuration locally;
6. publishes the local `configs/rox_waypoints.yaml` to `/waypoints`.

The standard RViz layout displays the live map, robot model, laser scan, costmaps, paths and waypoint markers. Its fixed frame is `map`.

Closing RViz does not stop robot navigation. Reopen only the visualization with:

```bash
rox rviz
```

### Send named goals

```bash
rox list
rox goto-dry home
rox goto home
rox goto crane_handover
```

`goto` runs on the laptop, sends the Nav2 action over DDS and verifies the final `map -> base_link` transform against the waypoint tolerances.

### Inspect the robot

```bash
rox status
rox tf
rox interfaces
rox nav-status
rox pose-status
```

### Stop managed Nav2

```bash
rox nav-stop
```

This sends `SIGINT` to the managed robot-side Nav2 process group and allows pose persistence to save the final localized pose before shutdown.

## 8. Fresh localization

When the robot was physically moved while navigation was off, the saved pose must not be restored.

Run:

```bash
rox nav-fresh
```

This restarts managed Nav2 on the robot after deleting the saved pose and opens local RViz. Use **2D Pose Estimate** once in local RViz, verify laser/map alignment, and allow pose persistence to save the corrected position.

Never use the previous saved pose after the robot was carried, pushed, towed or moved during a complete power-off unless its absolute position is independently known.

## 9. Navigation process management

The operator workflow uses these robot-side runtime files:

```text
runtime/rox_nav.pid
runtime/rox_nav.log
runtime/rox_last_pose.yaml
```

Useful commands:

```bash
rox nav-start
rox nav-start-fresh
rox nav-status
rox nav-log 100
rox nav-log -f
rox nav-stop
```

`rox nav-start` refuses to start a duplicate stack when `/navigate_to_pose` is already active. If Nav2 was started manually outside the manager, `rox nav-stop` refuses to kill an unknown process; stop the original terminal or service instead.

## 10. Waypoint editing and synchronization

`rox capture NAME` writes to the laptop's local YAML because the command runs locally over TF:

```bash
rox capture home
rox goto-dry home
```

After verification:

```bash
cd ~/Projects/VDA5050-Paper-Dev
git add configs/rox_waypoints.yaml
git commit -m "Update commissioned ROX waypoints"
git push
```

Then update the robot:

```bash
ssh neobotix@192.168.50.50 \
  'cd ~/Projects/VDA5050-Paper-Dev && git pull --ff-only'
```

Do not keep separate uncommitted waypoint versions on the two machines.

## 11. Shell configuration

The generated operator configuration normally resembles:

```bash
export ROX_ROLE=operator
export VDA5050_PROJECT="$HOME/Projects/VDA5050-Paper-Dev"
export NEOBOTIX_WS="$HOME/neobotix_view_ws"
export ROS_DISTRO=jazzy
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export ROS_DOMAIN_ID=169
export ROS_AUTOMATIC_DISCOVERY_RANGE=SUBNET
export ROS_STATIC_PEERS=192.168.50.50
export ROX_ROBOT_IP=192.168.50.50
export ROX_ROBOT_USER=neobotix
export ROX_REMOTE_PROJECT=/home/neobotix/Projects/VDA5050-Paper-Dev
```

Re-run the installer to change settings. It replaces its own `~/.bashrc` block rather than adding duplicates.

## 12. Troubleshooting

### Only `/parameter_events` and `/rosout` appear

Confirm:

```bash
rox env
ping -c 2 192.168.50.50
ros2 multicast receive
```

The static peer must be present:

```text
ROS_STATIC_PEERS=192.168.50.50
```

Reset the daemon after changing DDS variables:

```bash
ros2 daemon stop
ros2 daemon start
```

The shell installer already performs this reset once.

### Robot appears but model is missing

Check the local description package:

```bash
ros2 pkg prefix rox_description
ros2 topic echo /robot_description --once
```

Rebuild/source the local Neobotix workspace if `rox_description` is absent. The model mesh files must exist locally even though `/robot_description` is published by the robot.

### RViz opens but waypoints do not appear

Check:

```bash
ros2 topic info /waypoints
ros2 topic echo /waypoints --once
rox list
```

`rox nav` and `rox rviz` automatically launch the waypoint visualizer. The bundled operator RViz file is derived from the standard Neobotix Jazzy `single_robot.rviz` configuration and already has a `MarkerArray` display for `/waypoints`.

### SSH asks for a password

```bash
ssh-copy-id neobotix@192.168.50.50
ssh -o BatchMode=yes neobotix@192.168.50.50 true
```

### Nav2 startup fails

```bash
rox nav-status
rox nav-log 150
rox doctor
```

Also verify on the robot that the boot-time `rox_bringup` is healthy. Do not start a second hardware bringup instance.

## 13. Multi-operator safety

Multiple computers may visualize the ROS graph, but only one person should issue motion goals or VDA control commands at a time. Keep emergency stops accessible, confirm the active map and localization, and inspect the planned path before motion.
