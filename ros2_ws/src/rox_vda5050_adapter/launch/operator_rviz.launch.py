#!/usr/bin/env python3
"""Open the standard Neobotix Nav2 RViz view with project waypoint markers."""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, EmitEvent, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    project_root = os.environ.get(
        "VDA5050_PROJECT",
        os.path.expanduser("~/Projects/VDA5050-Paper-Dev"),
    )
    default_waypoint_file = os.path.join(
        project_root,
        "configs",
        "rox_waypoints.yaml",
    )
    default_rviz_config = os.path.join(
        get_package_share_directory("rox_vda5050_adapter"),
        "config",
        "rox_operator.rviz",
    )

    waypoint_file = LaunchConfiguration("waypoint_file")
    frame_id = LaunchConfiguration("frame_id")
    marker_topic = LaunchConfiguration("marker_topic")
    rviz_config = LaunchConfiguration("rviz_config")

    rviz = Node(
        package="rviz2",
        executable="rviz2",
        name="rox_operator_rviz",
        arguments=["-d", rviz_config],
        output="screen",
    )

    waypoint_visualizer = Node(
        package="rox_vda5050_adapter",
        executable="waypoint_visualizer",
        name="rox_operator_waypoint_visualizer",
        output="screen",
        parameters=[
            {
                "waypoint_file": waypoint_file,
                "frame_id": frame_id,
                "marker_topic": marker_topic,
                "reload_period": 1.0,
                "show_tolerances": True,
            }
        ],
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "waypoint_file",
                default_value=default_waypoint_file,
                description="Local project waypoint YAML",
            ),
            DeclareLaunchArgument(
                "frame_id",
                default_value="map",
                description="RViz fixed frame used by waypoint coordinates",
            ),
            DeclareLaunchArgument(
                "marker_topic",
                default_value="/waypoints",
                description=(
                    "MarkerArray topic already configured in the standard "
                    "Neobotix Nav2 RViz layout"
                ),
            ),
            DeclareLaunchArgument(
                "rviz_config",
                default_value=default_rviz_config,
                description="Neobotix Nav2 RViz configuration",
            ),
            rviz,
            waypoint_visualizer,
            RegisterEventHandler(
                OnProcessExit(
                    target_action=rviz,
                    on_exit=[EmitEvent(event=Shutdown(reason="RViz closed"))],
                )
            ),
        ]
    )
