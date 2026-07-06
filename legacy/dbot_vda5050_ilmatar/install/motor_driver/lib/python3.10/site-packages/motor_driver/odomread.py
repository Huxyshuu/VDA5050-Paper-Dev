import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class OdomPositionSubscriber(Node):

    def __init__(self):
        super().__init__('odom_position_subscriber')
        self.subscription = self.create_subscription(
            Odometry,
            'odom',
            self.odom_callback,
            10)
        self.subscription  # prevent unused variable warning

    def odom_callback(self, msg):
        position = msg.pose.pose.position
        self.get_logger().info(f'Position: x={position.x}, y={position.y}')

def main(args=None):
    rclpy.init(args=args)
    odom_position_subscriber = OdomPositionSubscriber()
    rclpy.spin(odom_position_subscriber)
    odom_position_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
