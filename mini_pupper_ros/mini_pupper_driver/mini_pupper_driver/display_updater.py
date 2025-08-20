#!/usr/bin/env python3


import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from geometry_msgs.msg import Pose

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('display_updater')
        self.pub = self.create_publisher(Image, 'mini_pupper_lcd/image_raw', 10)
        self.bridge = CvBridge()
        #self.timer = self.create_timer(1.0, self.publish_image)
        self.filename= '/home/ubuntu/mini_pupper_bsp/Display/idle.png'
        self.body_pose_sub = self.create_subscription(
            Pose,
            'body_pose',
            self.body_pose_callback,
            10
        )
    def publish_image(self,filename):
        # Load an image from disk
        cv_image = cv2.imread(filename)  # Ensure image exists
        msg = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        self.pub.publish(msg)
        #self.get_logger().info('Published one image')

    def body_pose_callback(self, msg: Pose):
        #self.last_pose = msg  # Store or use this in logic
        #self.get_logger().info(
        #    f"Received body_pose: position=({msg.position.x:.2f}, {msg.position.y:.2f}, {msg.position.z:.2f}), "
        #    f"orientation=({msg.orientation.x:.2f}, {msg.orientation.y:.2f}, {msg.orientation.z:.2f}, {msg.orientation.w:.2f})"
        #)
        oldFilename = self.filename
        if msg.position.z < -0.1:  # Check if the robot is on the ground 
              self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_crouch.png'
        else:      
            if msg.orientation.y < -0.05:  #upper
                if msg.orientation.x > 0.1 or msg.orientation.z > 0.02: #right
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_upper_right.png'
                elif msg.orientation.x < -0.1 or msg.orientation.z < -0.02: #left
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_upper_left.png' 
                else:  #middle   
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_upper_middle.png'
            elif msg.orientation.y>0.05:  #lower
                if msg.orientation.x > 0.1 or msg.orientation.z > 0.02: #right
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_lower_right.png'
                elif msg.orientation.x < -0.1 or msg.orientation.z < -0.02: #left
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_lower_left.png'
                else: #middle
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_lower_middle.png'                
            else: #level
                if msg.orientation.x > 0.1 or msg.orientation.z > 0.02: #right
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_level_right.png'
                elif msg.orientation.x < -0.1 or msg.orientation.z < -0.02: #left
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_level_left.png'
                else: #middle
                    self.filename='/home/ubuntu/ros_ws/src/mini_pupper_ros/mini_pupper_driver/resource/os_eyes_level_middle.png'
        if oldFilename != self.filename:    
            self.publish_image(self.filename)    
            

def main():
    rclpy.init()
    node = ImagePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

