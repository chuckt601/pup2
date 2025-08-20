#!/usr/bin/env python3


import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from geometry_msgs.msg import Pose as Pose

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('display_updater')
        self.pub = self.create_publisher(Image, 'mini_pupper_lcd/image_raw', 10)
        self.pose_sub = self.create_subscription(
            Pose,
            'body_pose',
            self.pose_callback,
            10
            )
        self.bridge = CvBridge()
        #self.timer = self.create_timer(1.0, self.publish_image)


    def publish_image(self,filename):
        # Load an image from disk
        cv_image = cv2.imread(filenamemangdang
        )  # Ensure image exists
        msg = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        self.pub.publish(msg)
        self.get_logger().info('Published one image')


.    def pose_callback(self, msg: Pose):
        self.get_logger().info(
        f"Received pose: position=({msg.position.x:.2f}, {msg.position.y:.2f}, {msg.position.z:.2f}), "
        f"orientation=({msg.orientation.x:.2f}, {msg.orientation.y:.2f}, {msg.orientation.z:.2f}, {msg.orientation.w:.2f})"
        if msg.orientation.x>0:
            self.puplish_image('/home/ubuntu/mini_pupper_bsp/Display/finishhop.png')
        else:
            self.publish_image('/home/ubuntu/mini_pupper_bsp/Display/hop.png'    
   
    )



def main():
    rclpy.init()
    node = ImagePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

