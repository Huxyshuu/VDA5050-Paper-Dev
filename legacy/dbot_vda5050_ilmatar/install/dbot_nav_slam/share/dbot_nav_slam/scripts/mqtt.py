#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
import paho.mqtt.client as mqtt
import json
import math

class AMCLPosePublisher(Node):

    def __init__(self):
        super().__init__('amcl_pose_publisher')
        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/amcl_pose',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        # MQTT client setup with MQTTv3.1.1 protocol
        self.mqtt_client = mqtt.Client(protocol=mqtt.MQTTv311)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_disconnect = self.on_disconnect

        try:
            self.mqtt_client.connect('192.168.0.123', 1883, 60)  # Replace with the actual IP address or hostname
            self.mqtt_client.loop_start()  # Start the MQTT client loop in a background thread
        except Exception as e:
            self.get_logger().error(f'Failed to connect to MQTT broker: {e}')

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.get_logger().info('Connected to MQTT broker')
        else:
            self.get_logger().error(f'Failed to connect to MQTT broker, return code {rc}')

    def on_disconnect(self, client, userdata, rc):
        self.get_logger().info('Disconnected from MQTT broker')

    def listener_callback(self, msg):
        self.get_logger().info('Received a message on /amcl_pose')
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation

        payload = {
            'position': {
                'x': round(position.x, 3),
                'y': round(position.y, 3)
            },
            'orientation': {
                'z': round(orientation.z, 3),                
                'w': round(orientation.w, 3)
            }
        }

        self.get_logger().info(f'Publishing payload to MQTT: {json.dumps(payload)}')
        result = self.mqtt_client.publish('test/topic', json.dumps(payload))
        if result.rc == mqtt.MQTT_ERR_SUCCESS:
            self.get_logger().info('Message published successfully')
        else:
            self.get_logger().error(f'Failed to publish message, return code {result.rc}')

    def destroy(self):
        self.mqtt_client.loop_stop()  # Stop the MQTT client loop
        self.mqtt_client.disconnect()  # Disconnect from the MQTT broker
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)

    amcl_pose_publisher = AMCLPosePublisher()

    try:
        rclpy.spin(amcl_pose_publisher)
    except KeyboardInterrupt:
        pass
    finally:
        amcl_pose_publisher.destroy()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
