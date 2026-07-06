import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import cv2
import mediapipe as mp
import numpy as np

class GestureControlNode(Node):
    def __init__(self):
        super().__init__('gesture_control_node')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.initialize_gesture_recognition()

    def initialize_gesture_recognition(self):
        self.mp_drawing = mp.solutions.drawing_utils
        self.mp_hands = mp.solutions.hands
        self.cap = cv2.VideoCapture(4)
        self.BaseOptions = mp.tasks.BaseOptions
        self.GestureRecognizer = mp.tasks.vision.GestureRecognizer
        self.GestureRecognizerOptions = mp.tasks.vision.GestureRecognizerOptions
        self.VisionRunningMode = mp.tasks.vision.RunningMode
        self.options = self.GestureRecognizerOptions(
            base_options=self.BaseOptions(model_asset_path='/home/dbot2/ros2_ws/src/gesturecontrol/gesturecontrol/gesture_recognizer.task'),
            running_mode=self.VisionRunningMode.VIDEO,min_hand_detection_confidence= 0.1,min_tracking_confidence=0.1,min_hand_presence_confidence =0.1)
        self.recognizer = self.GestureRecognizer.create_from_options(self.options)

    def timer_callback(self):
        twist = Twist()
        success, frame = self.cap.read()
        if not success:
            return

        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=np.asarray(rgb_frame))
        frame_timestamp_ms = self.cap.get(cv2.CAP_PROP_POS_MSEC)
        frame_timestamp_us = int(frame_timestamp_ms * 1)
        gesture_recognition_result = self.recognizer.recognize_for_video(mp_image, int(frame_timestamp_us))
        
        #twist = Twist()

        if len(gesture_recognition_result.gestures) != 0:
            gesture = gesture_recognition_result.gestures[0][0].category_name
            handedness = gesture_recognition_result.handedness[0][0].category_name
            print(gesture,handedness)

            if gesture == 'Victory':
                twist.linear.x = 10.0
                twist.angular.z = 0.0
            elif gesture == 'Open_Palm':
                twist.linear.x = 0.0
                twist.angular.z = 0.0
            elif gesture == 'Thumb_Up':
                if handedness == 'Right':
                    twist.angular.z = 10.0
                elif handedness == 'Left':
                    twist.angular.z = -10.0
            
            self.publisher_.publish(twist)
         

        cv2.imshow('Frame', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.cleanup()

    def cleanup(self):
        self.cap.release()
        cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    gesture_control_node = GestureControlNode()
    rclpy.spin(gesture_control_node)
    gesture_control_node.cleanup()
    rclpy.shutdown()

#if __name__ == '__main__':
#    main()
