#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
import numpy as np

class JoyController(Node):
    def __init__(self):
        super().__init__('joy_controller')
        self.declare_parameter('velocity_factor', 3.0)
        self.velocity_factor = self.get_parameter('velocity_factor').get_parameter_value().double_value
        self.cmd_vel_publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription = self.create_subscription(Joy, 'joy', self.listener_callback, 10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        vel = Twist()
        FrontNBack = msg.axes[1]
        LeftNRight = msg.axes[2]
        #self.get_logger().info('FrontNBack: {}'.format(FrontNBack))
        #self.get_logger().info('LeftNRight: {}'.format(LeftNRight))

        if msg.buttons[7] == 1:
            vel.angular.z = msg.axes[2] * 2 * self.velocity_factor
            vel.linear.x = msg.axes[1] * 2 * self.velocity_factor
            #vel.linear.x = float(msg.buttons[0] * 10 - msg.buttons[2] * 10)
            #vel.angular.z = float(msg.buttons[3] * 15 - msg.buttons[1] * 15)
        else:
            vel.angular.z = msg.axes[2] * self.velocity_factor
            vel.linear.x = msg.axes[1] * self.velocity_factor
            #vel.linear.x = float(msg.buttons[0] * 5 - msg.buttons[2] * 5)
            #vel.angular.z = float(msg.buttons[3] * 5 - msg.buttons[1] * 5)

        self.cmd_vel_publisher_.publish(vel)


def main(args=None):
    rclpy.init(args=args)
    joy_controller = JoyController()
    rclpy.spin(joy_controller)
    joy_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

