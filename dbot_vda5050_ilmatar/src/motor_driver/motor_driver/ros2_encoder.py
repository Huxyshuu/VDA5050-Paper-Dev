import canopen
import time
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float64MultiArray

class VelocityPublisher(Node):
    def __init__(self):
        super().__init__('velocity_publisher')
        self.publisher_left = self.create_publisher(Float64, 'left_wheel_rpm', 10)
        self.publisher_right = self.create_publisher(Float64, 'right_wheel_rpm', 10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'left_right_wheel_rpm', 10)        
        self.timer = self.create_timer(0.1, self.publish_velocity)

        # CANopen setup
        self.network = canopen.Network()
        self.network.connect(channel='can0', bustype='socketcan')
        self.node = self.network.add_node(1, '/home/dbot2/ros2_ws/src/motor_driver/motor_driver/zlac8015d.eds')

        # Indices and sub-indices
        self.VELOCITY_INDEX = 0x606C
        self.SUBINDEX_LEFT = 1
        self.SUBINDEX_RIGHT = 2

    def publish_velocity(self):
        try:
            velocity_left = self.node.sdo[self.VELOCITY_INDEX][self.SUBINDEX_LEFT].raw
            velocity_right = self.node.sdo[self.VELOCITY_INDEX][self.SUBINDEX_RIGHT].raw

            velocity_left_msg = Float64()
            velocity_right_msg = Float64()

            velocity_left_msg.data = 10 * float(velocity_left) 
            velocity_right_msg.data = -10 * float(velocity_right) 

            velocity_msg = Float64MultiArray()
            velocity_msg.data = [10 * float(velocity_left), -10 * float(velocity_right)]

            self.publisher_left.publish(velocity_left_msg)
            self.publisher_right.publish(velocity_right_msg)
            self.publisher_.publish(velocity_msg)

            self.get_logger().info(f'Publishing Velocity Left: {velocity_left_msg.data}, Velocity Right: {velocity_right_msg.data}')

        except Exception as e:
            self.get_logger().error(f'Error: {e}')

def main(args=None):
    rclpy.init(args=args)
    velocity_publisher = VelocityPublisher()
    rclpy.spin(velocity_publisher)
    velocity_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
