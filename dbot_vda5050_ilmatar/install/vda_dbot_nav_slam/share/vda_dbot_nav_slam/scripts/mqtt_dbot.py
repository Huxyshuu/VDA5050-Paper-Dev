import json
import logging
import time
import random
from paho.mqtt import client as mqtt_client
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped

# MQTT Configuration
BROKER = 'i7e2212f.ala.eu-central-1.emqxsl.com'
PORT = 8883
TOPIC = "python-mqtt/debot"
AMCL_TOPIC = "amcl_pose"
CLIENT_ID = f'python-mqtt-tcp-pub-sub-{random.randint(0, 1000)}'
USERNAME = 'admin'
PASSWORD = 'admin'

FIRST_RECONNECT_DELAY = 1
RECONNECT_RATE = 2
MAX_RECONNECT_COUNT = 12
MAX_RECONNECT_DELAY = 60

FLAG_EXIT = False

def connect_mqtt():
    """Connects to the MQTT broker and handles reconnection."""
    reconnect_delay = FIRST_RECONNECT_DELAY  # Defined here
    while True:
        try:
            client = mqtt_client.Client(CLIENT_ID)
            client.username_pw_set(USERNAME, PASSWORD)
            client.tls_set(ca_certs='emca.crt')  # Make sure this CA certificate is valid
            client.connect(BROKER, PORT, keepalive=120)
            print("MQTT Client connected")
            return client
        except Exception as e:
            print(f"Failed to connect to MQTT broker: {e}. Retrying in {reconnect_delay} seconds...")
            time.sleep(reconnect_delay)
            reconnect_delay = min(reconnect_delay * RECONNECT_RATE, MAX_RECONNECT_DELAY)  # Incremental backoff

def on_mqtt_disconnect(client, userdata, rc):
    """Handles MQTT disconnection and attempts reconnection."""
    logging.info("MQTT Client disconnected. Attempting to reconnect...")
    return connect_mqtt()

class AmclPosePublisher(Node):
    """ROS 2 Node to subscribe to amcl_pose and publish to MQTT."""
    def __init__(self, mqtt_client):
        super().__init__('amcl_pose_publisher')
        self.mqtt_client = mqtt_client
        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            AMCL_TOPIC,
            self.amcl_pose_callback,
            10)
        self.subscription  # prevent unused variable warning

    def amcl_pose_callback(self, msg):
        """Callback function to handle incoming amcl_pose messages."""
        pose_data = {
            'position': {
                'x': msg.pose.pose.position.x,
                'y': msg.pose.pose.position.y,
                'z': msg.pose.pose.position.z
            },
            'orientation': {
                'x': msg.pose.pose.orientation.x,
                'y': msg.pose.pose.orientation.y,
                'z': msg.pose.pose.orientation.z,
                'w': msg.pose.pose.orientation.w
            }
        }
        msg_str = json.dumps(pose_data)
        if not self.mqtt_client.is_connected():
            logging.error("publish: MQTT client is not connected! Reconnecting...")
            self.mqtt_client = on_mqtt_disconnect(self.mqtt_client, None, None)
        result = self.mqtt_client.publish(TOPIC, msg_str)
        if result.rc == mqtt_client.MQTT_ERR_SUCCESS:
            print(f'Sent `{msg_str}` to topic `{TOPIC}`')
        else:
            print(f'Failed to send message to topic {TOPIC}')

def publish(mqtt_client):
    """Publishes AMCL pose to MQTT."""
    rclpy.init(args=None)
    amcl_publisher = AmclPosePublisher(mqtt_client)
    
    while not FLAG_EXIT:
        if not mqtt_client.is_connected():
            logging.error("publish: MQTT client is not connected! Reconnecting...")
            mqtt_client = on_mqtt_disconnect(mqtt_client, None, None)
            continue
        rclpy.spin_once(amcl_publisher, timeout_sec=1)  # Ensure this runs to handle callbacks
    amcl_publisher.destroy_node()
    rclpy.shutdown()

def run():
    logging.basicConfig(format='%(asctime)s - %(levelname)s: %(message)s',
                        level=logging.DEBUG)
    mqtt_client = connect_mqtt()
    mqtt_client.on_disconnect = on_mqtt_disconnect  # Assign the disconnect handler
    mqtt_client.loop_start()  # Starts a background thread to handle network traffic, etc.
    
    time.sleep(1)
    if mqtt_client.is_connected():
        publish(mqtt_client)
    else:
        mqtt_client.loop_stop()

if __name__ == '__main__':
    run()
