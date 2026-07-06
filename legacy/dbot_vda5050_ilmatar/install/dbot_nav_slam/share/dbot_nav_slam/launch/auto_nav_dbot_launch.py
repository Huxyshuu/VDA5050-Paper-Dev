from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node

def generate_launch_description():
    # Define launch configurations
    map_file = LaunchConfiguration('map', default='/home/dbot2/dbot_vda5050_ilmatar/src/dbot_nav_slam/maps/clean_df_map.yaml')
    params_file = LaunchConfiguration('params_file', default='/home/dbot2/dbot_vda5050_ilmatar/src/dbot_nav_slam/config/nav2_params.yaml')

    # Define launch description
    ld = LaunchDescription()

    # Include dbot launch file from the dbot package
    dbot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('dbot'), 'launch', 'dbot_launch.py'
            ])
        ])
    )

    # Include tf2_dbot launch file from the tf2_dbot package
    tf2_dbot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('tf2_dbot'), 'launch', 'tf2_dbot_launch.py'
            ])
        ])
    )

    # Include nav2_bringup launch file with arguments from the nav2_bringup package
    nav2_bringup_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('nav2_bringup'), 'launch', 'bringup_launch.py'
            ])
        ]),
        launch_arguments={
            'map': map_file,
            'params_file': params_file
        }.items()
    )



    # Add actions with delays
    ld.add_action(dbot_launch)
    ld.add_action(TimerAction(period=3.0, actions=[tf2_dbot_launch]))  # Wait 5 seconds before launching tf2_dbot
    ld.add_action(TimerAction(period=3.0, actions=[nav2_bringup_launch]))  # Wait 10 seconds before launching nav2_bringup

    return ld
