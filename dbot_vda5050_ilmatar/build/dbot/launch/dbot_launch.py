import launch
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        # Node for motor bringup in the motor_driver package
        launch_ros.actions.Node(
            package='motor_driver',
            executable='motor_bringup',
            name='motor_bringup',
            output = "log"
        ),

        # Node to publish joy stick messages
        launch_ros.actions.Node(
            package='joy_linux',
            executable='joy_linux_node',
            name='joy_linux_node'
        ),

        # Node to convert joy stick messages to vehicle control commands
        launch_ros.actions.Node(
            package='joycontrol',
            executable='joycontrol',
            name='joycontrol',
            output = "log"
        ),

        # Node for wheel odometry estimator in the odom_motion_model package
        launch_ros.actions.Node(
            package='odom_motion_model',
            executable='odom_motion_model',
            name='odom_motion_model',
            output = "log"
        ),

        # Include Velodyne launch file from the velodyne package
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                '/opt/ros/humble/share/velodyne/launch/velodyne-all-nodes-VLP16-launch.py'
            ),
            # If the Velodyne launch file requires arguments, add them here. 
            # Example: launch_arguments={'argument_name': 'value'}.items()
        ),

        # Include Intel Realsense launch file 
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                '/opt/ros/humble/share/realsense2_camera/launch/rs_launch.py'
            ),
            # Required arguments to enable IMU
            launch_arguments={'enable_accel': 'true', 
                              'enable_gyro': 'true'}.items()
        ),
    ])
