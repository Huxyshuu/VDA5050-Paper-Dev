from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    package_share = Path(get_package_share_directory("rox_vda5050_adapter"))
    default_config = str(package_share / "config" / "rox_vda5050_adapter.yaml")
    config = LaunchConfiguration("config")
    mqtt_host = LaunchConfiguration("mqtt_host")
    map_id = LaunchConfiguration("map_id")
    dry_run = LaunchConfiguration("dry_run_navigation")
    return LaunchDescription(
        [
            DeclareLaunchArgument("config", default_value=default_config),
            DeclareLaunchArgument("mqtt_host", default_value="192.168.1.115"),
            DeclareLaunchArgument("map_id", default_value="warehouse_case_study"),
            DeclareLaunchArgument("dry_run_navigation", default_value="true"),
            Node(
                package="rox_vda5050_adapter",
                executable="rox_vda5050_adapter",
                name="rox_vda5050_adapter",
                output="screen",
                parameters=[
                    config,
                    {
                        "mqtt_host": mqtt_host,
                        "map_id": map_id,
                        "dry_run_navigation": ParameterValue(dry_run, value_type=bool),
                    },
                ],
            ),
        ]
    )
