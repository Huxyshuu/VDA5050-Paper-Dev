import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped

class PoseSubscriber(Node):

    def __init__(self):
        super().__init__('pose_subscriber')
        self.get_logger().info('Pose Subscriber Node has been started')

        # Subscribe to PoseStamped
        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/pose',  # Topic to subscribe to
            self.pose_callback,
            1)

    def pose_callback(self, msg):
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation
        self.get_logger().info(
            f'Pos: x={position.x:.3f}, y={position.y:.3f}, z={position.z:.3f}'
            )
        self.get_logger().info(
            f'Ori: x={orientation.x:.3f}, y={orientation.y:.3f}, z={orientation.z:.3f}, w={orientation.w:.3f}'
            )

def main(args=None):
    rclpy.init(args=args)
    pose_subscriber = PoseSubscriber()
    rclpy.spin(pose_subscriber)
    pose_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()