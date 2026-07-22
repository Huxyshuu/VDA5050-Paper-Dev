# ROX-Diff command reference

`scripts/rox.sh` is the central command interface on both the ROX-Diff and configured operator computers. After the one-time shell installer, run it as `rox` from any directory.

## One-time setup

Operator computer:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/install_rox_shell.sh operator \
  --neobotix-ws "$HOME/neobotix_view_ws"
exec bash
rox build
rox doctor
```

ROX-Diff:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/install_rox_shell.sh robot \
  --neobotix-ws "$HOME/ros2_workspace"
exec bash
rox build
```

See [REMOTE_OPERATOR_WORKSTATION.md](REMOTE_OPERATOR_WORKSTATION.md) for complete installation and troubleshooting.

## Daily commands

| Command | Robot behavior | Operator-computer behavior |
|---|---|---|
| `rox nav` | Starts Nav2, pose persistence, local Neobotix RViz and waypoint markers | Starts headless Nav2 remotely when absent, then opens the same RViz and waypoint markers locally |
| `rox nav-fresh` | Deletes saved pose and starts Nav2/RViz | Restarts managed robot Nav2 without pose restoration and opens local RViz |
| `rox rviz` | Opens local RViz and markers without changing Nav2 | Same |
| `rox goto NAME` | Sends named goal through local ROS graph | Sends named goal over DDS to robot Nav2 |
| `rox goto-dry NAME` | Validates goal without motion | Same |
| `rox capture NAME` | Captures TF into robot-local YAML | Captures remote TF into laptop-local YAML |
| `rox list` | Lists local waypoint file | Lists laptop waypoint file |
| `rox status` | Shows robot graph and local tools | Shows shared graph plus robot managed-nav status |
| `rox tf` | Echoes `map -> base_link` | Echoes the same remote transform |
| `rox interfaces` | Checks robot topics | Checks the remotely visible topics |
| `rox pose-*` | Operates on robot pose file | Routes command to robot over SSH |
| `rox adapter-*` | Starts adapter locally | Starts adapter on robot over interactive SSH |

## Navigation lifecycle

```bash
rox nav-start
rox nav-start-fresh
rox nav-status
rox nav-log 100
rox nav-log -f
rox nav-stop
```

On an operator computer these commands are routed to `neobotix@192.168.50.50`. Managed headless Nav2 writes:

```text
runtime/rox_nav.pid
runtime/rox_nav.log
```

`rox nav` is normally preferable because it starts/connects Nav2 and opens local RViz in one operation.

## Waypoints

```bash
rox visualize
rox list
rox capture home
rox goto-dry home
rox goto home
```

The integrated RViz launcher publishes markers on:

```text
/waypoints
```

This matches the MarkerArray display already present in the standard Neobotix Nav2 RViz configuration. The standalone visualizer uses the same topic through `rox visualize`.

## Pose persistence

```bash
rox pose-status
rox pose-save
rox pose-restore
rox pose-clear
```

On an operator computer these modify the robot-side runtime pose, not a laptop copy.

Use:

```bash
rox nav-fresh
```

whenever the robot was physically moved while navigation was off or when scan/map alignment is uncertain.

## Diagnostics

```bash
rox doctor
rox env
rox status
rox nav-status
rox nav-log 150
```

`rox doctor` validates the local model/navigation packages, middleware settings, network reachability and password-free SSH.

## Environment overrides

Common overrides:

```text
ROX_ROLE=robot|operator|auto
NEOBOTIX_WS=/path/to/workspace
ROX_ROBOT_IP=192.168.50.50
ROX_ROBOT_USER=neobotix
ROX_REMOTE_PROJECT=/home/neobotix/Projects/VDA5050-Paper-Dev
ROX_WAYPOINT_FILE=/path/to/rox_waypoints.yaml
ROX_WAYPOINT_MARKER_TOPIC=/waypoints
ROX_MAP_YAML=/path/to/df_map.yaml
ROS_DOMAIN_ID=0
ROS_STATIC_PEERS=192.168.50.50
```

Persistent machine-local settings live in:

```text
~/.config/rox/rox.env
```

Re-run `install_rox_shell.sh` instead of manually duplicating source statements in `~/.bashrc`.
