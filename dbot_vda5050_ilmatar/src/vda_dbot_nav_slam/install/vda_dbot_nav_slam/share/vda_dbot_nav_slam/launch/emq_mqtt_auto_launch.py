from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource, AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node


def generate_launch_description():
    # Define launch configurations
    map_file = LaunchConfiguration('map', default='/home/dbot2/ros2_ws/src/dbot_nav_slam/maps/clean_df_map.yaml')
    params_file = LaunchConfiguration('params_file', default='/home/dbot2/ros2_ws/src/dbot_nav_slam/config/nav2_params.yaml')

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

    # MQTT Bridge Node
    mqtt_bridge = Node(
        package='mqtt_client',
        executable='mqtt_client',
        name='mqtt_bridge',
        parameters=[PathJoinSubstitution([
            FindPackageShare('dbot_nav_slam'),
            'config',
            'mqtt_bridge.yaml'
        ])]
    )

    # Launch emq_mqtt_inspection.py script as a ROS 2 node
    emq_mqtt_inspection = Node(
        package='dbot_nav_slam',
        executable='emq_mqtt_inspection.py',
        name='emq_mqtt_inspection',
        output='screen',
    )

    # Launch emq_mqtt_vel_msg_sub.py script as a ROS 2 node
    emq_mqtt_vel_msg_sub = Node(
        package='dbot_nav_slam',
        executable='emq_mqtt_vel_msg_sub.py',
        name='emq_mqtt_vel_msg_sub',
        output='screen',
    )

    # Include rosbridge_websocket_launch.xml from rosbridge_server using AnyLaunchDescriptionSource
    rosbridge_websocket_launch = IncludeLaunchDescription(
        AnyLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('rosbridge_server'),
                'launch',
                'rosbridge_websocket_launch.xml'
            ])
        ])
    )

    # rosapi node
    rosapi_node = Node(
        package='rosapi',
        executable='rosapi_node',
        name='rosapi_node',
        output='screen',
    )

    # Add actions with delays
    ld.add_action(dbot_launch)
    ld.add_action(TimerAction(period=1.0, actions=[tf2_dbot_launch]))  # Wait 1 second before launching tf2_dbot
    ld.add_action(TimerAction(period=3.0, actions=[nav2_bringup_launch]))  # Wait 3 seconds before launching nav2_bringup
    ld.add_action(TimerAction(period=5.0, actions=[mqtt_bridge]))
    ld.add_action(TimerAction(period=9.0, actions=[emq_mqtt_inspection]))
    ld.add_action(TimerAction(period=10.0, actions=[emq_mqtt_vel_msg_sub]))
    ld.add_action(TimerAction(period=11.0, actions=[rosbridge_websocket_launch]))
    ld.add_action(TimerAction(period=13.0, actions=[rosapi_node]))

    return ld
