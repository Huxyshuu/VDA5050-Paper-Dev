from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('x', default_value='0'),
        DeclareLaunchArgument('y', default_value='0'),
        DeclareLaunchArgument('theta', default_value='0'),

        ## The static transform between map frame to odom frame
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = [
                '--x', LaunchConfiguration('x'), 
                '--y', LaunchConfiguration('y'), 
                '--z', '0', 
                '--yaw', LaunchConfiguration('theta'), 
                '--pitch', '0', 
                '--roll', '0',  
                '--frame-id', 'map', 
                '--child-frame-id', 'odom']
        ),

        ## The dynamic transform between odom frame to baselink frame
        Node(
            package='tf2_dbot',
            executable='odom_baselink_broadcaster',
            name='odom_baselink_broadcaster',
        ),
        
        ## The static transform between DBot's base_link frame to velodyne frame
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = ['--x', '0.1', '--y', '0', '--z', '0.45', '--yaw', '-0', '--pitch', '0', '--roll', '0', '--frame-id', 'base_link', '--child-frame-id', 'velodyne']
        ),

        ## The static transform between DBot's base_link frame to camera frame
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = ['--x', '0.12', '--y', '0', '--z', '0.32', '--yaw', '0', '--pitch', '0', '--roll', '0', '--frame-id', 'base_link', '--child-frame-id', 'camera_link']
        ),

        ## Right wheel
        Node(
                package='tf2_ros',
                executable='static_transform_publisher',
                arguments = ['--x', '0', '--y', '-0.3', '--z', '0.1', '--yaw', '-0', '--pitch', '0', '--roll', '1.57', '--frame-id', 'base_link', '--child-frame-id', 'right_wheel']
        ),
        
        ## Left wheel
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = ['--x', '0', '--y', '0.3', '--z', '0.1', '--yaw', '-0', '--pitch', '0', '--roll', '-1.57', '--frame-id', 'base_link', '--child-frame-id', 'left_wheel']
        ),


    ])
