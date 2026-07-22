# ROX-Diff AMR Migration Update

## Current architecture

The active AMR path is:

```text
VDA 5050 v3 MQTT
  -> rox_vda5050_adapter
  -> Nav2 NavigateToPose
  -> native Neobotix ROX-Diff stack
```

The old DBot stack remains under `legacy/` only. The Raspberry Pi runs Mosquitto and fleet/master control; the ROX onboard computer runs ROS 2 Jazzy, native Neobotix software, Nav2 and this repository's overlay.

## Current commissioned site values

```text
Pi DTLabOpen:     192.168.50.115
ROX DTLabOpen:    192.168.50.50
Pi Ilmatar Wi-Fi: 192.168.0.116
ROS:              jazzy / rmw_cyclonedds_cpp / domain 0
Map file:         df_map.yaml + df_map.pgm
Logical map ID:   df_map
```

The native ROX hardware bringup is started at boot by `ROS_AUTOSTART.sh`; it must not be launched a second time.

## Waypoint tooling

The ROS package now provides:

- `capture_waypoint` — capture the current `map -> base_link` pose;
- `waypoint_visualizer` — display names, headings and tolerances in RViz;
- `goto_waypoint` — send one exact named YAML pose to Nav2 and verify final TF error;
- `rox_vda5050_adapter` — execute VDA 5050 orders through Nav2.

The central helper is:

```bash
./scripts/rox.sh help
```

See [docs/ROX_COMMANDS.md](docs/ROX_COMMANDS.md).

## Configuration consistency corrections

All active defaults now use:

```text
MQTT host: 192.168.50.115
map_id:    df_map
```

This includes the adapter source defaults, ROS parameter file, launch file, runner scripts, Pi environment files, systemd examples, waypoint files and stored short test order.

## Waypoint commissioning rule

The real captured coordinates are retained in `configs/rox_waypoints.yaml`, but the file is set to `configured: false` until each pose is repeatedly tested with normal Nav2 and physically approved. Any recapture resets the flag to false.

## Remaining physical work

- build the overlay on the actual ROX computer;
- back up the installed map pair;
- verify Nav2/localization and actual goal-checker behavior;
- test every exact waypoint from multiple approach poses;
- verify crane handover alignment and scanner fields;
- regenerate the short/full VDA orders after sign-off;
- run VDA dry-run, short-motion, full-route, crane-only and coordinated no-load tests in order.

This repository does not replace the robot or crane safety systems and does not constitute safety certification.
