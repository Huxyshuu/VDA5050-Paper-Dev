import launch
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'velocity_factor',
            default_value='3.0',
            description='The velocity factor parameter'
        ),

        # Node for motor bringup in the motor_driver package
        launch_ros.actions.Node(
            package='motor_driver',
            executable='motor_bringup',
            name='motor_bringup',
            output="log"
        ),

        # Node to convert joystick messages to vehicle control commands
        launch_ros.actions.Node(
            package='joycontrol',
            executable='joycontrol',
            name='joycontrol',
            output="log",
            parameters=[{'velocity_factor': LaunchConfiguration('velocity_factor')}]
        ),

        # Node for wheel odometry estimator in the odom_motion_model package
        launch_ros.actions.Node(
            package='odom_motion_model',
            executable='odom_motion_model',
            name='odom_motion_model',
            output="log"
        ),

        # Include Velodyne launch file from the velodyne package
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                '/opt/ros/humble/share/velodyne/launch/velodyne-all-nodes-VLP16-launch.py'
            ),
        ),

        # Include Intel Realsense launch file 
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                '/opt/ros/humble/share/realsense2_camera/launch/rs_launch.py'
            ),
            launch_arguments={'enable_accel': 'true', 
                              'enable_gyro': 'true'}.items()
        ),
    ])
