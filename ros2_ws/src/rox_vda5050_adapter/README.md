# `rox_vda5050_adapter`

ROS 2 package for the Neobotix ROX-Diff case study. It provides the VDA 5050 v3 MQTT-to-Nav2 adapter plus commissioning tools for named map waypoints.

## Installed executables

| Executable | Purpose |
|---|---|
| `rox_vda5050_adapter` | Translate VDA 5050 orders and instant actions to Nav2 and publish VDA state |
| `capture_waypoint` | Capture the current `map -> base_link` pose into `rox_waypoints.yaml` |
| `waypoint_visualizer` | Publish waypoint names, headings and tolerances as RViz `MarkerArray` markers |
| `goto_waypoint` | Send one exact YAML waypoint to Nav2 and verify the final TF pose |

## Build

The native Neobotix workspace remains the underlay. This package is built in the project overlay:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
```

The ROX hardware bringup is already started at boot by `ROS_AUTOSTART.sh`. Do not launch a duplicate `rox_bringup` instance.

## Waypoint workflow

Start Nav2 and RViz:

```bash
./scripts/rox.sh nav
```

In a second terminal, publish the YAML markers:

```bash
./scripts/rox.sh visualize
```

List exact coordinates:

```bash
./scripts/rox.sh list
```

Capture the robot's current pose:

```bash
./scripts/rox.sh capture crane_handover
```

Validate the exact command without motion:

```bash
./scripts/rox.sh goto-dry crane_handover
```

Send the exact YAML pose to `/navigate_to_pose` and compare the final `map -> base_link` pose with the YAML tolerances:

```bash
./scripts/rox.sh goto crane_handover
```

Equivalent direct command:

```bash
ros2 run rox_vda5050_adapter goto_waypoint \
  --name crane_handover \
  --waypoint-file configs/rox_waypoints.yaml
```

The RViz markers themselves remain visual only. `goto_waypoint` is the component that sends motion.

## Current site defaults

```text
ROS distribution:      jazzy
RMW implementation:    rmw_cyclonedds_cpp
ROS domain:            0
ROX project:           ~/Projects/VDA5050-Paper-Dev
Neobotix workspace:    ~/ros2_workspace
ROS map frame:         map
Robot base frame:      base_link
Nav2 action:           /navigate_to_pose
VDA map_id:            df_map
Map YAML:              <rox_navigation prefix>/share/rox_navigation/maps/df_map.yaml
Waypoint YAML:         configs/rox_waypoints.yaml
Marker topic:          /rox_waypoints/markers
```

See [`docs/ROX_COMMANDS.md`](../../../docs/ROX_COMMANDS.md) for the complete command reference and staged operating procedure.
