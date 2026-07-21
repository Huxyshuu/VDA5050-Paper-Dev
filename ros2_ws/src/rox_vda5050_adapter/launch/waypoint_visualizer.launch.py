#!/usr/bin/env python3
"""Launch the ROX waypoint MarkerArray publisher."""

import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    project_root = os.environ.get(
        "VDA5050_PROJECT",
        os.path.expanduser("~/Projects/VDA5050-Paper-Dev"),
    )
    default_waypoint_file = os.path.join(project_root, "configs", "rox_waypoints.yaml")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "waypoint_file",
                default_value=default_waypoint_file,
                description="Absolute path to rox_waypoints.yaml",
            ),
            DeclareLaunchArgument(
                "frame_id",
                default_value="map",
                description="RViz fixed frame used by waypoint coordinates",
            ),
            DeclareLaunchArgument(
                "marker_topic",
                default_value="/rox_waypoints/markers",
                description="MarkerArray topic displayed in RViz",
            ),
            DeclareLaunchArgument(
                "reload_period",
                default_value="1.0",
                description="Seconds between file-change checks",
            ),
            DeclareLaunchArgument(
                "show_tolerances",
                default_value="true",
                description="Show XY circles and yaw tolerance rays",
            ),
            Node(
                package="rox_vda5050_adapter",
                executable="waypoint_visualizer",
                name="waypoint_visualizer",
                output="screen",
                parameters=[
                    {
                        "waypoint_file": LaunchConfiguration("waypoint_file"),
                        "frame_id": LaunchConfiguration("frame_id"),
                        "marker_topic": LaunchConfiguration("marker_topic"),
                        "reload_period": LaunchConfiguration("reload_period"),
                        "show_tolerances": LaunchConfiguration("show_tolerances"),
                    }
                ],
            ),
        ]
    )
