#!/usr/bin/env python3
"""Launch Neobotix Nav2 with pose persistence and optional waypoint markers."""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    project_root = os.environ.get(
        "VDA5050_PROJECT", os.path.expanduser("~/Projects/VDA5050-Paper-Dev")
    )
    navigation_launch = os.path.join(
        get_package_share_directory("rox_navigation"),
        "launch",
        "navigation.launch.py",
    )

    map_yaml = LaunchConfiguration("map")
    pose_file = LaunchConfiguration("pose_file")
    map_id = LaunchConfiguration("map_id")
    rox_type = LaunchConfiguration("rox_type")
    use_rviz = LaunchConfiguration("use_rviz")
    auto_restore = LaunchConfiguration("auto_restore")
    save_period = LaunchConfiguration("save_period")
    max_age_hours = LaunchConfiguration("max_age_hours")
    show_waypoints = LaunchConfiguration("show_waypoints")
    waypoint_file = LaunchConfiguration("waypoint_file")
    marker_topic = LaunchConfiguration("marker_topic")

    return LaunchDescription(
        [
            DeclareLaunchArgument("map", description="Absolute path to map YAML"),
            DeclareLaunchArgument("rox_type", default_value="diff"),
            DeclareLaunchArgument("use_rviz", default_value="True"),
            DeclareLaunchArgument(
                "pose_file",
                default_value=os.path.join(
                    project_root, "runtime", "rox_last_pose.yaml"
                ),
                description="Runtime YAML containing the last localized pose",
            ),
            DeclareLaunchArgument("map_id", default_value="df_map"),
            DeclareLaunchArgument("auto_restore", default_value="true"),
            DeclareLaunchArgument("save_period", default_value="2.0"),
            DeclareLaunchArgument(
                "max_age_hours",
                default_value="0.0",
                description="Reject older poses; 0 disables age rejection",
            ),
            DeclareLaunchArgument(
                "show_waypoints",
                default_value="true",
                description="Publish named waypoint markers while this launch runs",
            ),
            DeclareLaunchArgument(
                "waypoint_file",
                default_value=os.path.join(
                    project_root, "configs", "rox_waypoints.yaml"
                ),
                description="Project waypoint YAML",
            ),
            DeclareLaunchArgument(
                "marker_topic",
                default_value="/waypoints",
                description="MarkerArray topic used by Neobotix Nav2 RViz",
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(navigation_launch),
                launch_arguments={
                    "rox_type": rox_type,
                    "use_rviz": use_rviz,
                    "map": map_yaml,
                }.items(),
            ),
            Node(
                package="rox_vda5050_adapter",
                executable="pose_persistence",
                name="rox_pose_persistence",
                output="screen",
                arguments=[
                    "run",
                    "--pose-file",
                    pose_file,
                    "--map-id",
                    map_id,
                    "--map-yaml",
                    map_yaml,
                    "--auto-restore",
                    auto_restore,
                    "--save-period",
                    save_period,
                    "--max-age-hours",
                    max_age_hours,
                ],
            ),
            Node(
                package="rox_vda5050_adapter",
                executable="waypoint_visualizer",
                name="rox_navigation_waypoint_visualizer",
                output="screen",
                condition=IfCondition(show_waypoints),
                parameters=[
                    {
                        "waypoint_file": waypoint_file,
                        "frame_id": "map",
                        "marker_topic": marker_topic,
                        "reload_period": 1.0,
                        "show_tolerances": True,
                    }
                ],
            ),
        ]
    )
