# `rox_vda5050_adapter`

ROS 2 package for the Neobotix ROX-Diff VDA 5050 v3 case study. It contains the MQTT-to-Nav2 adapter and commissioning utilities for capturing, visualizing, commanding and persistently restoring named map poses.

## Installed executables

| Executable | Purpose |
|---|---|
| `rox_vda5050_adapter` | Translate VDA 5050 orders and instant actions to Nav2 and publish VDA state |
| `capture_waypoint` | Capture the current `map -> base_link` pose into `rox_waypoints.yaml` |
| `waypoint_visualizer` | Publish waypoint names, headings and tolerances as RViz `MarkerArray` markers |
| `goto_waypoint` | Send one exact YAML waypoint to Nav2 and verify the final TF pose |
| `pose_persistence` | Save the last localized pose to disk and restore it to AMCL through `/initialpose` |

## Build

The native Neobotix workspace remains the underlay and this repository is a separate overlay:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
```

The ROX hardware bringup is already started at boot by `ROS_AUTOSTART.sh`. Do not launch another `rox_bringup` instance.

## Normal operation

Start Nav2, RViz and automatic pose restoration:

```bash
./scripts/rox.sh nav
```

When the robot has not been moved since the preceding Nav2 session, the saved pose is supplied to AMCL automatically. In another terminal, after checking scan/map alignment:

```bash
./scripts/rox.sh goto home
```

On the first run, after changing the map, or after physically moving the robot while Nav2 was off:

```bash
./scripts/rox.sh nav-fresh
```

Then set **2D Pose Estimate** once in RViz. The companion node begins saving the localized pose automatically.

## Waypoint workflow

```bash
./scripts/rox.sh visualize
./scripts/rox.sh list
./scripts/rox.sh capture crane_handover
./scripts/rox.sh goto-dry crane_handover
./scripts/rox.sh goto crane_handover
```

The RViz markers are visual only. `goto_waypoint` is the component that commands motion.

## Pose persistence commands

```bash
./scripts/rox.sh pose-status
./scripts/rox.sh pose-save
./scripts/rox.sh pose-restore
./scripts/rox.sh pose-clear
```

The default site-specific runtime file is:

```text
runtime/rox_last_pose.yaml
```

It is excluded from Git and must not be published in the public repository.

## Current site defaults

```text
ROS distribution:     jazzy
RMW implementation:   rmw_cyclonedds_cpp
ROS domain:            0
ROX project:           ~/Projects/VDA5050-Paper-Dev
Neobotix workspace:    ~/ros2_workspace
ROS map frame:         map
Robot base frame:      base_link
Odometry frame:        odom
Nav2 action:           /navigate_to_pose
AMCL initial pose:     /initialpose
VDA map_id:            df_map
Map YAML:              ~/maps/df_map.yaml (preferred)
Waypoint YAML:         configs/rox_waypoints.yaml
Saved pose:            runtime/rox_last_pose.yaml
Marker topic:          /rox_waypoints/markers
```

See:

- [`docs/ROX_COMMANDS.md`](../../../docs/ROX_COMMANDS.md)
- [`docs/POSE_PERSISTENCE.md`](../../../docs/POSE_PERSISTENCE.md)
