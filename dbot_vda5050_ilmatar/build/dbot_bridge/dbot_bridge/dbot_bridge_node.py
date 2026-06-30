import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
import paho.mqtt.client as mqtt
import json
import time
import threading

class DbotBridgeNode(Node):
    def __init__(self):
        super().__init__('dbot_bridge_node')

        # MQTT setup
        self.mqtt = mqtt.Client()
        self.mqtt.on_connect = self.on_connect
        self.mqtt.on_message = self.on_message
        self.mqtt.connect("192.168.1.115", 1883, 60)
        self.mqtt.loop_start()

        self.order_topic = "uagv/v2/dbot/0001/order"
        self.state_topic = "uagv/v2/dbot/0001/state"

        # ROS setup
        self.nav_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.current_pose = None

        self.pose_sub = self.create_subscription(PoseWithCovarianceStamped, '/amcl_pose', self.pose_callback, 10)
        self.pose_pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)

        self.pose_init_done = False
        self.create_timer(1.0, self.publish_initial_pose_once)
        self.create_timer(3.0, self.publish_state)

    def publish_initial_pose_once(self):
        if self.pose_init_done:
            return

        pose = PoseWithCovarianceStamped()
        pose.header.frame_id = 'map'
        pose.header.stamp = self.get_clock().now().to_msg()

        # Your locked initial pose from AMCL
        pose.pose.pose.position.x = 0.9870686479280624
        pose.pose.pose.position.y = -0.39680143411197377
        pose.pose.pose.position.z = 0.0


        pose.pose.pose.orientation.x = 0.0
        pose.pose.pose.orientation.y = 0.0
        pose.pose.pose.orientation.z = -0.914610353397085
        pose.pose.pose.orientation.w = 0.4043363716744505

        pose.pose.covariance = [0.0] * 36  # Minimal valid dummy

        self.pose_pub.publish(pose)
        self.pose_init_done = True
        self.get_logger().info("Initial pose published to /initialpose")

    def on_connect(self, client, userdata, flags, rc):
        print("Connected to MQTT:", rc)
        client.subscribe(self.order_topic)

    def on_message(self, client, userdata, msg):
        try:
            data = json.loads(msg.payload.decode())
            first_node = next(n for n in data["nodes"] if n["released"])
            pos = first_node["nodePosition"]

            goal = NavigateToPose.Goal()
            goal.pose.header.frame_id = "map"
            goal.pose.header.stamp = self.get_clock().now().to_msg()
            goal.pose.pose.position.x = pos["x"]
            goal.pose.pose.position.y = pos["y"]
            goal.pose.pose.position.z = pos.get("z", 0.0)

            goal.pose.pose.orientation.x = pos.get("orientation", {}).get("x", 0.0)
            goal.pose.pose.orientation.y = pos.get("orientation", {}).get("y", 0.0)
            goal.pose.pose.orientation.z = pos.get("orientation", {}).get("z", 0.0)
            goal.pose.pose.orientation.w = pos.get("orientation", {}).get("w", 1.0)

            def send_goal():
                self.nav_client.wait_for_server()
                self.nav_client.send_goal_async(goal)
                print("Navigation goal sent to:", pos["x"], pos["y"])

            threading.Thread(target=send_goal).start()

        except Exception as e:
            print("Error handling MQTT order:", e)

    def pose_callback(self, msg):
        self.current_pose = msg.pose.pose
        self.get_logger().info(f"Pose received: x={msg.pose.pose.position.x}, y={msg.pose.pose.position.y}")

    def publish_state(self):
        if not self.current_pose:
            return

        pos = self.current_pose.position
        ori = self.current_pose.orientation

        state = {
            "headerId": int(time.time()),
            "timestamp": time.strftime("%Y-%m-%dT%H:%M:%S.00Z", time.gmtime()),
            "version": "2.1.0",
            "manufacturer": "dbot",
            "serialNumber": "0001",
            "orderId": "test-order",
            "orderUpdateId": 0,
            "lastNodeId": "debug",
            "lastNodeSequenceId": 0,
            "driving": True,
            "paused": False,
            "nodeStates": [],
            "edgeStates": [],
            "actionStates": [],
            "agvPosition": {
                "x": pos.x,
                "y": pos.y,
                "z": pos.z,
                "mapId": "map",
                "positionInitialized": True,
                "orientation": {
                    "x": ori.x,
                    "y": ori.y,
                    "z": ori.z,
                    "w": ori.w
                }
            }
        }

        self.mqtt.publish(self.state_topic, json.dumps(state))
        print("Published state to MQTT")

def main(args=None):
    rclpy.init(args=args)
    node = DbotBridgeNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
