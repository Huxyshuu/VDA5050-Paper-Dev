#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import json
from paho.mqtt import client as mqtt_client
import random
import time
import logging
import os


# === MQTT CONFIGURATION (Secure TLS) ===
BROKER = 'i7e2212f.ala.eu-central-1.emqxsl.com'
PORT = 8883
TOPIC = 'robot/control'
USERNAME = 'admin'
PASSWORD = 'admin'
CA_CERTS = '/home/dbot2/ros2_ws/src/dbot_nav_slam/scripts/emqxsl-ca.crt'
CLIENT_ID = f"mqtt_ros2_sub_{random.randint(0, 1000)}"

# Reconnect logic
FIRST_RECONNECT_DELAY = 1
RECONNECT_RATE = 2
MAX_RECONNECT_COUNT = 12
MAX_RECONNECT_DELAY = 60

class MQTT2ROS2Bridge(Node):
    def __init__(self):
        super().__init__('mqtt_to_ros2_bridge')

        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.last_command = None  # For deduplication

        # Configure MQTT client with TLS and reconnect handling
        self.mqtt_client = mqtt_client.Client(CLIENT_ID)
        self.mqtt_client.username_pw_set(USERNAME, PASSWORD)
        self.mqtt_client.tls_set(ca_certs=CA_CERTS)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_disconnect = self.on_disconnect
        self.mqtt_client.on_message = self.on_message

        try:
            self.mqtt_client.connect(BROKER, PORT)
            self.mqtt_client.loop_start()
        except Exception as e:
            self.get_logger().error(f"MQTT initial connection failed: {e}")

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.get_logger().info("Connected to MQTT broker")
            client.subscribe(TOPIC)
        else:
            self.get_logger().error(f"Failed to connect, return code {rc}")

    def on_disconnect(self, client, userdata, rc):
        self.get_logger().warn(f"MQTT disconnected with code {rc}, attempting to reconnect...")
        reconnect_count = 0
        reconnect_delay = FIRST_RECONNECT_DELAY
        while reconnect_count < MAX_RECONNECT_COUNT:
            time.sleep(reconnect_delay)
            try:
                client.reconnect()
                self.get_logger().info("Reconnected to MQTT broker")
                return
            except Exception as e:
                self.get_logger().error(f"Reconnect failed: {e}")
                reconnect_delay = min(reconnect_delay * RECONNECT_RATE, MAX_RECONNECT_DELAY)
                reconnect_count += 1

    def on_message(self, client, userdata, msg):
        try:
            payload = msg.payload.decode()
            data = json.loads(payload)

            if payload == self.last_command:
                return
            self.last_command = payload

            twist = Twist()
            twist.linear.x = data['linear']['x']
            twist.linear.y = data['linear']['y']
            twist.linear.z = data['linear']['z']
            twist.angular.x = data['angular']['x']
            twist.angular.y = data['angular']['y']
            twist.angular.z = data['angular']['z']

            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f'Received from MQTT: {payload}')
        except Exception as e:
            self.get_logger().error(f"Failed to parse or publish message: {e}")

def main(args=None):
    rclpy.init(args=args)
    logging.basicConfig(level=logging.INFO)
    node = MQTT2ROS2Bridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
