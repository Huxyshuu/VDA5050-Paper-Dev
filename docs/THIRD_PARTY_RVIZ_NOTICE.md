# Third-party RViz configuration notice

`ros2_ws/src/rox_vda5050_adapter/config/rox_operator.rviz` is derived from the Jazzy branch of Neobotix's `neo_nav2_bringup/rviz/single_robot.rviz` configuration.

Source project: `neobotix/neo_nav2_bringup`

The original project is distributed under the Apache License 2.0. The only functional adaptation in this repository copy is resolving the single-robot `<robot_namespace>` placeholders to the root namespace so the configuration can be opened directly on an operator workstation. The existing `/waypoints` MarkerArray display is retained.
