# ROX Waypoint Visualization and Exact Nav2 Goals

The package reads `configs/rox_waypoints.yaml` and publishes persistent RViz markers on:

```text
/rox_waypoints/markers
```

For every waypoint RViz shows its name, map position, heading, XY tolerance circle and yaw-tolerance rays. The visualizer automatically reloads the YAML after a valid file change.

## Start

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh visualize
```

In RViz, set **Fixed Frame** to `map`, add a **MarkerArray** display and use `/rox_waypoints/markers` as the topic.

The markers are visual only. Clicking a normal marker does not send a Nav2 goal.

## Send an exact marker pose to Nav2

```bash
./scripts/rox.sh goto crane_handover
```

Equivalent direct command:

```bash
ros2 run rox_vda5050_adapter goto_waypoint \
  --name crane_handover \
  --waypoint-file configs/rox_waypoints.yaml
```

The goal sender reads the same `x`, `y` and `theta` values used by the visualizer. It converts `theta` to a quaternion, sends a `nav2_msgs/action/NavigateToPose` goal and checks the final `map -> base_link` pose against the YAML tolerances.

Preview without motion:

```bash
./scripts/rox.sh goto-dry crane_handover
```

List all names and coordinates:

```bash
./scripts/rox.sh list
```

## Interpretation

```text
RViz Fixed Frame: map
ROS map file:     df_map.yaml / df_map.pgm
VDA map_id:       df_map
```

These are related but not interchangeable. `map` is the ROS TF frame. `df_map.yaml` is the occupancy-grid metadata file. `map_id: df_map` is a logical VDA/project identifier.

The displayed tolerances and the final check are commissioning aids; they do not change the Nav2 controller's own goal-checker parameters and are not safety functions.
