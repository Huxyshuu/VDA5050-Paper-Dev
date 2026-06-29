#!/usr/bin/env python3

from typing import Union
from pathlib import Path
import logging
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger
from diagnostic_msgs.msg import DiagnosticStatus
from diagnostic_msgs.msg import KeyValue
from .zlac8015d_canopen_2 import ZLAC8015D, MotorValues
from . import node_controls as nc
from .log_connector import ConnectPythonLoggingToROS2
from std_msgs.msg import Float64

from dbot_custom_msgs.msg import WheelEncoder
#from canopen.pdo.base import Map


config_path = "/home/dbot2/ros2_ws/src/motor_driver/motor_driver/dbot_config.yaml"

# ROS2 logging integration
logging.getLogger(__name__).addHandler(ConnectPythonLoggingToROS2())
logging.getLogger(__name__).setLevel(logging.DEBUG)

class MotorDriverROS(Node):
    def __init__(self, config_path: Union[str, Path]):
        super().__init__('motor_driver')
        self.config = nc.get_config(config_path)

        # Declare and get parameters
        self.declare_parameter('publish_current_speed_frequency', 5.0)
        publish_current_speed_frequency = self.get_parameter('publish_current_speed_frequency').value

        self.declare_parameter('publish_motor_status_frequency', 1.0)
        publish_motor_status_frequency = self.get_parameter('publish_motor_status_frequency').value

        self.declare_parameter('max_speed', 300)
        max_speed = self.get_parameter('max_speed').value

        # Start CANopen network
        self.network = nc.connect_network(self.config["can_network"])

        # Initialize motor driver
        self.motor_driver = ZLAC8015D(
                node_id=self.config["node_id"], object_dictionary=self.config["od_path"]
            )

        # Add node to network
        self.network.add_node(self.motor_driver)

        # Limit max speed
        self.motor_driver.set_max_velocity_limit(max_speed)
        self.encoder_publisher = self.create_publisher(WheelEncoder, 'wheel_encoder_rpm', 10)
        #self.right_wheel_rpm_publisher = self.create_publisher(Float64, 'right_wheel_rpm', 10)
        #self.left_wheel_rpm_publisher = self.create_publisher(Float64, 'left_wheel_rpm', 10)

        self.timer = self.create_timer(0.1, self.publish_velocity)
        # Setup PDO communication
        self.VELOCITY_INDEX = 0x606C
        self.SUBINDEX_LEFT = 1
        self.SUBINDEX_RIGHT = 2

        #velocity_left = self.motor_driver.sdo[self.VELOCITY_INDEX][self.SUBINDEX_LEFT].raw
        #velocity_right = self.motor_driver.sdo[self.VELOCITY_INDEX][self.SUBINDEX_RIGHT].raw
        #print(f'Publishing Velocity Left: {velocity_left}, Velocity Right: {velocity_right}')
        #self.motor_driver.setup_pdo()

        # Subscribe to velocity command topic
        self.create_subscription(
            Twist, 'cmd_vel', self.callback_velocity_command, 10
        )

        # Create service for stopping motors
        self.create_service(
            Trigger, 'stop_motor', self.callback_stop
        )

        # Create Publishers for current velocity and diagnostics
        self.current_speed_pub = self.create_publisher(
            Twist, 'current_speed', 10
        )
        self.motor_status_pub = self.create_publisher(
            DiagnosticStatus, 'motor_status', 1
        )

        # Set publishers to publish regularly
        self.create_timer(
            1.0 / publish_current_speed_frequency, self.publish_current_speed
        )

        # Setup timeout if no cmd_vel messages received
        self.timer = None
        self.motor_driver.init_profile_velocity(sync=True)
    
    def publish_velocity(self):
        try:
            velocity_left = self.motor_driver.sdo[self.VELOCITY_INDEX][self.SUBINDEX_LEFT].raw
            velocity_right = self.motor_driver.sdo[self.VELOCITY_INDEX][self.SUBINDEX_RIGHT].raw

            velocity_msg = WheelEncoder()

            velocity_msg.header.stamp = self.get_clock().now().to_msg()
            velocity_msg.header.frame_id = "base_link"
            # self.get_logger().info(f'My clock value {velocity_msg.header.stamp}')
            velocity_msg.left = 0.1 * float(velocity_left) 
            velocity_msg.right = -0.1 * float(velocity_right) 

            #velocity_right_msg = Float64()
            #velocity_right_msg.data = -0.1 * float(velocity_right) 
            #self.right_wheel_rpm_publisher.publish(velocity_right_msg)

            #velocity_left_msg = Float64()
            #velocity_left_msg.data = 0.1 * float(velocity_left) 
            #self.left_wheel_rpm_publisher.publish(velocity_left_msg)

            self.encoder_publisher.publish(velocity_msg)

            #self.get_logger().info(f'Publishing Velocity Left: {velocity_left_msg.data}, Velocity Right: {velocity_right_msg.data}')

        except Exception as e:
            self.get_logger().error(f'Error: {e}')

    def set_speed(self, msg: Twist):
        # Function implementation remains the same
        motor_speeds = nc.twist_to_motor_speeds(
            msg,
            self.config["dimensions"]["wheel_radius"],
            self.config["dimensions"]["wheel_span"],
        )
        self.motor_driver.set_target_velocity(motor_speeds)
    def stop(self):
        # Function implementation remains the same
        """
        Stop motor driver
        """
        self.motor_driver.halt_operation()
    def shutdown(self):
        # Function implementation remains the same
        """
        Stop all nodes and disconnect from network
        """
        nc.disconnect_network(self.network)


    def publish_current_speed(self):
        # TODO! add get_speed method to motor driver class
        msg = nc.motor_speeds_to_twist(
            self.motor_driver.velocity,
            self.config["dimensions"]["wheel_radius"],
            self.config["dimensions"]["wheel_span"],
        )
        self.current_speed_pub.publish(msg)

    def publish_motor_status(self, event=None):
    #     # TODO! add get_status method to motor driver class
         status = self.motor_driver.get_status()
         data_list = []
         for key in status:
             data_list.append(KeyValue(key, str(status[key])))
         msg = DiagnosticStatus()
         msg.values = data_list
         self.motor_status_pub.publish(msg)

    def callback_velocity_command(self, msg):
        # Function implementation remains the same
        self.set_speed(msg)


    def callback_stop(self, _, response):
        self.stop()
        response.success = True
        response.message = "Motor has been stopped"
        return response

def main(args=None):
    rclpy.init(args=None)
    motor_driver_wrapper = MotorDriverROS(config_path=config_path)
    rclpy.spin(motor_driver_wrapper)
    motor_driver_wrapper.shutdown()
    rclpy.shutdown()
#main()
