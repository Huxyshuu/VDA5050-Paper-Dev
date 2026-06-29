#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from nav_msgs.msg import Odometry
import numpy as np

from dbot_custom_msgs.msg import WheelEncoder
from .vehicle_model import VehicleModel

class OdomMotionModel(Node):

    def __init__(self):
        super().__init__('odom_motion_model')
        self.start_time = self.get_clock().now().to_msg()
        self.vehicle_model = VehicleModel(initialize_time=self.start_time)
        self.odom_publisher = self.create_publisher(Odometry, '/odom', 10)
        self.encoder_subscriber = self.create_subscription(WheelEncoder, 'wheel_encoder_rpm', self.encoder_callback, 10)
        self.encoder_subscriber

    def encoder_callback(self, encoder_msg):
        encoder_left_rpm = encoder_msg.left
        encoder_right_rpm = encoder_msg.right
        current_time = encoder_msg.header.stamp

        current_state, quaternion, linear_vel, angular_vel = self.vehicle_model.update_state(encoder_left_rpm, encoder_right_rpm, current_time)
        #self.get_logger().info(f'Linear velocity: {linear_vel} & Angular velocity: {angular_vel}')

        current_state_msg = Odometry()
        
        current_state_msg.header.stamp = self.get_clock().now().to_msg()
        current_state_msg.header.frame_id = "odom"

        current_state_msg.pose.pose.position.x = current_state[0]
        current_state_msg.pose.pose.position.y = current_state[1]
        #current_state_msg.pose.pose.position.z = current_state[2]

        current_state_msg.pose.pose.orientation.w = quaternion[0]
        current_state_msg.pose.pose.orientation.x = quaternion[1]
        current_state_msg.pose.pose.orientation.y = quaternion[2]
        current_state_msg.pose.pose.orientation.z = quaternion[3]

        current_state_msg.twist.twist.linear.x = linear_vel
        current_state_msg.twist.twist.angular.z = angular_vel

        self.odom_publisher.publish(current_state_msg)



def main(args=None):
    rclpy.init(args=args)
    odom_motion_model = OdomMotionModel()
    rclpy.spin(odom_motion_model)
    odom_motion_model.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()