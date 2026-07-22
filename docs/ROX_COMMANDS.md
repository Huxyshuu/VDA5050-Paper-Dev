# ROX-Diff command reference

Run all commands from:

```bash
cd ~/Projects/VDA5050-Paper-Dev
```

The native hardware bringup already starts at boot through `ROS_AUTOSTART.sh`. Do not launch a second `rox_bringup`.

## Build after source changes

```bash
./scripts/rox.sh build
source ros2_ws/install/setup.bash
./scripts/rox.sh status
```

## Normal daily operation

### Terminal 1 — Nav2, RViz and automatic pose restoration

```bash
./scripts/rox.sh nav
```

This starts the Neobotix navigation launch and the pose-persistence companion. When a valid saved pose exists, it is sent to AMCL automatically. The current pose is then saved periodically until Nav2 stops.

The first-ever run, or a run after the robot was moved, must instead use:

```bash
./scripts/rox.sh nav-fresh
```

Use RViz **2D Pose Estimate** once, verify scan/map alignment, and allow several seconds for the new pose to be saved.

### Terminal 2 — inspect and command exact waypoints

```bash
./scripts/rox.sh list
./scripts/rox.sh goto-dry home
./scripts/rox.sh goto home
```

`goto` reads the exact `x`, `y` and `theta` from `configs/rox_waypoints.yaml`, sends `NavigateToPose`, and checks the final TF pose against the configured waypoint tolerances.

### Terminal 3 — optional RViz waypoint markers

```bash
./scripts/rox.sh visualize
```

Add `/rox_waypoints/markers` as an RViz `MarkerArray` display. Markers are visual only; `goto` commands motion.

## Persistent-pose commands

```bash
./scripts/rox.sh pose-status
./scripts/rox.sh pose-save
./scripts/rox.sh pose-restore
./scripts/rox.sh pose-clear
```

The runtime file is normally:

```text
runtime/rox_last_pose.yaml
```

It is deliberately ignored by Git.

Detailed behavior and limitations are documented in [POSE_PERSISTENCE.md](POSE_PERSISTENCE.md).

## Waypoint capture

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture short_test
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

Capturing any waypoint resets `configured: false`. Set it to true only after repeated exact Nav2 return tests and physical clearance/alignment checks.

## Diagnostics

```bash
./scripts/rox.sh env
./scripts/rox.sh interfaces
./scripts/rox.sh status
./scripts/rox.sh tf
```

Expected after navigation/localization starts:

```text
/navigate_to_pose
map -> base_link
```

## VDA adapter

```bash
./scripts/rox.sh adapter-dry
./scripts/rox.sh adapter-real
```

Use dry-run before real Nav2 movement.

## Useful overrides

```bash
ROX_MAP_YAML=/absolute/path/df_map.yaml ./scripts/rox.sh nav
ROX_WAYPOINT_FILE=/absolute/path/waypoints.yaml ./scripts/rox.sh goto home
ROX_LAST_POSE_FILE=/absolute/path/last_pose.yaml ./scripts/rox.sh nav
ROX_AUTO_RESTORE=false ./scripts/rox.sh nav
ROX_MAX_POSE_AGE_HOURS=24 ./scripts/rox.sh nav
VDA_MAP_ID=df_map ./scripts/rox.sh nav
```

## Safety rule

Automatic restoration is only an initial localization estimate. Never command motion when the robot was moved while Nav2 was off or when the scan does not align with the map. Clear the pose and initialize manually in those cases.
