import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import json
from paho.mqtt import client as mqtt_client

BROKER = '192.168.1.150'
PORT = 1883
TOPIC = 'robot/control'
USERNAME = 'admin'
PASSWORD = 'admin'

class MQTT2ROS2Bridge(Node):
    def __init__(self):
        super().__init__('mqtt_to_ros2_bridge')

        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.last_command = None  # For deduplication

        self.mqtt_client = mqtt_client.Client("mqtt_ros2_sub")
        self.mqtt_client.username_pw_set(USERNAME, PASSWORD)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message

        self.mqtt_client.connect(BROKER, PORT)
        self.mqtt_client.loop_start()

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.get_logger().info("Connected to MQTT broker")
            client.subscribe(TOPIC)
        else:
            self.get_logger().error(f"Failed to connect, return code {rc}")

    def on_message(self, client, userdata, msg):
        try:
            payload = msg.payload.decode()
            data = json.loads(payload)

            # Skip if same as last command
            if payload == self.last_command:
                return

            self.last_command = payload  # Update last command

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
    node = MQTT2ROS2Bridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
