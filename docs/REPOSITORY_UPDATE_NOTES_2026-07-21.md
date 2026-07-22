# Repository update notes — 21 July 2026

This update consolidates the current ROX-Diff commissioning workflow and adds exact navigation to named YAML waypoints.

## Runtime additions

- `goto_waypoint`: reads a named pose from `configs/rox_waypoints.yaml`, sends it to Nav2 and verifies the final TF pose against the configured tolerances.
- `waypoint_visualizer`: publishes waypoint labels, headings and tolerance graphics to `/rox_waypoints/markers` for RViz.
- `scripts/rox.sh`: one command interface for build, Nav2, interface checks, visualization, capture, exact waypoint goals and VDA adapter startup.

## Corrected site defaults

- ROS 2 Jazzy
- `rmw_cyclonedds_cpp`
- `ROS_DOMAIN_ID=0`
- ROX project path `~/Projects/VDA5050-Paper-Dev`
- Neobotix workspace `~/ros2_workspace`
- Pi MQTT address `192.168.50.115`
- ROX address `192.168.50.50`
- logical map ID `df_map`
- map pair `df_map.yaml` and `df_map.pgm`

## Bringup behavior

The native ROX hardware stack is started at boot by `ROS_AUTOSTART.sh`. Documentation and helper scripts no longer instruct operators to start a second `rox_bringup` instance.

## Waypoint sign-off behavior

The committed waypoint coordinates are retained, but `configured` is set to `false` until the locations have been repeatedly tested with normal Nav2 and physically approved. Capturing or recapturing any waypoint also resets `configured` to `false`.

## Shell robustness

ROS-generated setup files are sourced without enabling Bash `nounset`, avoiding the Jazzy `AMENT_TRACE_SETUP_FILES: unbound variable` failure.

## Files added or replaced

See the update bundle's `FILE_MANIFEST.txt`. Existing destination files are backed up automatically by `apply_repo_update.py` before replacement.
