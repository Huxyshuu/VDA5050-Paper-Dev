# Remote operator workstation update — 2026-07-22

This update was prepared against the merged `main` branch containing the named-waypoint tools and disk-backed pose persistence.

## Added

- role-aware `scripts/rox.sh` for robot and operator computers;
- automatic local ROS/Neobotix/project overlay sourcing;
- global `rox` command available from every new terminal;
- idempotent `scripts/install_rox_shell.sh`;
- password-free SSH process management for headless robot Nav2;
- local standard Neobotix Nav2 RViz with model, map, scan, costmaps and paths;
- automatic `/waypoints` MarkerArray publication;
- `rox doctor`, `rox rviz`, `rox nav-start`, `rox nav-stop`, `rox nav-status` and `rox nav-log`;
- complete remote-computer setup and troubleshooting documentation.

## Preserved

- boot-time native `rox_bringup`;
- `df_map` map ID and map lookup;
- named waypoint capture/list/goto workflow;
- final TF tolerance checks;
- pose persistence and `nav-fresh` safety behavior;
- VDA adapter dry/real commands.

## Safety behavior

The operator `rox nav` command checks for `/navigate_to_pose` before remotely starting Nav2. Robot-side `nav-start` also checks the action and its managed PID before launch. This prevents accidental duplicate Nav2 controller stacks.

`nav-stop` only stops a process created through the managed command. It refuses to kill an unknown manually launched Nav2 process.
