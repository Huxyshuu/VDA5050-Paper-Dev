import json
import logging
import time
import random
from opcua import Client
from paho.mqtt import client as mqtt_client
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped

# OPC UA Configuration
OPCUA_URL = "opc.tcp://10.210.1.12:4840"
RECONNECT_DELAY = 5  # Delay in seconds before retrying OPC UA connection

# MQTT Configuration
BROKER = 'i7e2212f.ala.eu-central-1.emqxsl.com'
PORT = 8883
TOPIC = "python-mqtt/ilmatar"
AMCL_TOPIC = "amcl_pose"
CLIENT_ID = f'python-mqtt-tcp-pub-sub-{random.randint(0, 1000)}'
USERNAME = 'admin'
PASSWORD = 'admin'

FIRST_RECONNECT_DELAY = 1
RECONNECT_RATE = 2
MAX_RECONNECT_COUNT = 12
MAX_RECONNECT_DELAY = 60

FLAG_EXIT = False

def connect_opcua():
    """Connects to the OPC UA server and handles reconnection."""
    while True:
        try:
            client = Client(OPCUA_URL)
            client.connect()
            print("OPC UA Client connected")
            return client
        except Exception as e:
            print(f"Failed to connect to OPC UA server: {e}. Retrying in {RECONNECT_DELAY} seconds...")
            time.sleep(RECONNECT_DELAY)

def check_opcua_server_state(client):
    """Checks the OPC UA server state before attempting reconnection."""
    try:
        server_state = client.get_node("i=2259").get_value()  # NodeId for ServerState
        if server_state == 0:
            logging.warning("OPC UA server state is DOWN. Waiting before reconnecting...")
            return False
        return True
    except Exception as e:
        logging.error(f"Error checking OPC UA server state: {e}")
        return False

def on_opcua_disconnect(client):
    """Handles OPC UA disconnection and attempts reconnection."""
    logging.info("OPC UA Client disconnected. Attempting to reconnect...")
    reconnect_count, reconnect_delay = 0, FIRST_RECONNECT_DELAY
    while reconnect_count < MAX_RECONNECT_COUNT:
        if check_opcua_server_state(client):
            try:
                client.disconnect()
                client.connect()
                logging.info("Reconnected to OPC UA successfully!")
                return client
            except Exception as err:
                logging.error("%s. OPC UA Reconnect failed. Retrying...", err)
        reconnect_delay *= RECONNECT_RATE
        reconnect_delay = min(reconnect_delay, MAX_RECONNECT_DELAY)
        logging.info("Reconnecting in %d seconds...", reconnect_delay)
        time.sleep(reconnect_delay)
        reconnect_count += 1
    logging.info("Reconnect to OPC UA failed after %s attempts. Exiting...", reconnect_count)
    global FLAG_EXIT
    FLAG_EXIT = True

def disconnect_opcua(client):
    """Safely disconnects from the OPC UA server."""
    try:
        client.disconnect()
        print("OPC UA Client disconnected")
    except Exception as e:
        print(f"Error disconnecting OPC UA client: {e}")

def fetch_opcua_data(client):
    """Fetches crane position data from OPC UA server."""
    try:
        Hoist_position_mm = client.get_node("ns=5;s=DX_Custom_V.Status.Hoist.Position.Position_mm").get_value()
        Trolly_position_mm = client.get_node("ns=5;s=DX_Custom_V.Status.Trolley.Position.Position_mm").get_value()
        Bridge_position_mm = client.get_node("ns=5;s=DX_Custom_V.Status.Bridge.Position.Position_mm").get_value()
        return {
            "Hoist": Hoist_position_mm,
            "Trolly": Trolly_position_mm,
            "Bridge": Bridge_position_mm
        }
    except Exception as e:
        print(f"Error reading OPC UA nodes: {e}")
        return None

def connect_mqtt():
    """Connects to the MQTT broker and handles reconnection."""
    while True:
        try:
            client = mqtt_client.Client(CLIENT_ID)
            client.username_pw_set(USERNAME, PASSWORD)
            client.tls_set(ca_certs='emqxsl-ca.crt')
            client.connect(BROKER, PORT, keepalive=120)
            print("MQTT Client connected")
            return client
        except Exception as e:
            print(f"Failed to connect to MQTT broker: {e}. Retrying in {RECONNECT_DELAY} seconds...")
            time.sleep(RECONNECT_DELAY)

def on_mqtt_disconnect(client):
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
        msg = json.dumps(pose_data)
        if not self.mqtt_client.is_connected():
            logging.error("publish: MQTT client is not connected! Reconnecting...")
            self.mqtt_client = on_mqtt_disconnect(self.mqtt_client)
        result = self.mqtt_client.publish(TOPIC, msg)
        if result[0] == 0:
            print(f'Sent `{msg}` to topic `{TOPIC}`')
        else:
            print(f'Failed to send message to topic {TOPIC}')

def publish(mqtt_client, opcua_client):
    """Publishes OPC UA data and AMCL pose to MQTT."""
    rclpy.init(args=None)
    amcl_publisher = AmclPosePublisher(mqtt_client)
    while not FLAG_EXIT:
        data = fetch_opcua_data(opcua_client)
        if data:
            msg = json.dumps(data)
            if not mqtt_client.is_connected():
                logging.error("publish: MQTT client is not connected! Reconnecting...")
                mqtt_client = on_mqtt_disconnect(mqtt_client)
                continue
            result = mqtt_client.publish(TOPIC, msg)
            if result[0] == 0:
                print(f'Sent `{msg}` to topic `{TOPIC}`')
            else:
                print(f'Failed to send message to topic {TOPIC}')
        else:
            print("Skipping publishing due to OPC UA read error. Reconnecting OPC UA client...")
            opcua_client = on_opcua_disconnect(opcua_client)
        rclpy.spin_once(amcl_publisher, timeout_sec=1)
    amcl_publisher.destroy_node()
    rclpy.shutdown()

def run():
    logging.basicConfig(format='%(asctime)s - %(levelname)s: %(message)s',
                        level=logging.DEBUG)
    opcua_client = connect_opcua()
    mqtt_client = connect_mqtt()
    mqtt_client.loop_start()
    time.sleep(1)
    if mqtt_client.is_connected():
        publish(mqtt_client, opcua_client)
    else:
        mqtt_client.loop_stop()
    disconnect_opcua(opcua_client)

if __name__ == '__main__':
    run()
