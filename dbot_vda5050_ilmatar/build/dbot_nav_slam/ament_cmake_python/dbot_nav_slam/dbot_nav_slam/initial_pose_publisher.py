import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import time

class InitialPosePublisher(Node):
    def __init__(self):
        super().__init__('initial_pose_publisher')
        self.publisher = self.create_publisher(PoseStamped, '/initialpose', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.done = False

    def timer_callback(self):
        if self.done:
            return

        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()

        # Your provided initial pose
        pose.pose.position.x = -2.65536
        pose.pose.position.y = -6.45267
        pose.pose.position.z = 0.0
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = -0.70903
        pose.pose.orientation.w = 0.705178

        self.publisher.publish(pose)
        self.get_logger().info(" Initial PoseStamped published")
        self.done = True

def main(args=None):
    rclpy.init(args=args)
    node = InitialPosePublisher()
    rclpy.spin_once(node, timeout_sec=3)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
