import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_msgs.msg import Float32
from sensor_msgs.msg import Imu
#from tf2ros import euler_from_quaternion
import math

class MinimalSubscriber(Node):

    def __init__(self):
        #self.node = rclpy.create_node('Minimal_Subscriber')
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            Imu,
            'imu/data',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.publisherYaw_ = self.create_publisher(Float32, 'yaw', 10)
        self.publisherPitch_ = self.create_publisher(Float32, 'pitch', 10)
        self.publisherRoll_ = self.create_publisher(Float32, 'roll', 10)
        
        self.roll_old=0.0
        self.roll_sub_flag=False
        self.pitch_old=0.0
        self.pitch_sub_flag=False
        self.yaw_old=0.0
        self.yaw_sub_flag=False


    def listener_callback(self, imu_msg):
        
        # Convert quaternion to euler angles (roll, pitch, yaw)
        quaternion = imu_msg.orientation
        (roll, pitch, yaw) = self.quaternion_to_euler(
            quaternion.x, quaternion.y, quaternion.z, quaternion.w)
        roll_deg = math.degrees(-roll) 

        Delta=roll_deg-self.roll_old
        if abs(Delta)>10 and not self.roll_sub_flag:
            roll_deg=self.roll_old
            self.roll_sub_flag=True
        else:
            self.roll_sub_flag=False
        self.roll_old=roll_deg         

        pitch_deg = math.degrees(pitch)

        Delta=pitch_deg-self.pitch_old
        if abs(Delta)>10 and not self.pitch_sub_flag:
            pitch_deg=self.pitch_old
            self.pitch_sub_flag=True
        else:
            self.pitch_sub_flag=False
        self.pitch_old=pitch_deg 

        yaw_deg = math.degrees(math.pi-yaw)

        Delta=yaw_deg-self.yaw_old
        if abs(Delta)>10 and not self.yaw_sub_flag:
            yaw_deg=self.yaw_old
            self.yaw_sub_flag=True
        else:
            self.yaw_sub_flag=False
        self.yaw_old=yaw_deg

        msg = Float32()
        msg.data = yaw_deg
        self.publisherYaw_.publish(msg)
        msg.data = pitch_deg
        self.publisherPitch_.publish(msg)
        msg.data = roll_deg
        self.publisherRoll_.publish(msg)
        
        #self.get_logger().info("Roll: %f degrees, Pitch: %f degrees, Yaw: %f degrees" % (roll_deg, pitch_deg, yaw_deg)) 
  
    def quaternion_to_euler(self, x, y, z, w):
        """
        Convert quaternion to euler angles (roll, pitch, yaw)
        """
        # Roll (x-axis rotation)
        sinr_cosp = +2.0 * (w * x + y * z)
        cosr_cosp = +1.0 - 2.0 * (x * x + y * y)
        roll = math.atan2(sinr_cosp, cosr_cosp)

        # Pitch (y-axis rotation)
        sinp = +2.0 * (w * y - z * x)
        if math.fabs(sinp) >= 1:
            pitch = math.copysign(math.pi / 2, sinp)  # Use 90 degrees if out of range
        else:
            pitch = math.asin(sinp)

        # Yaw (z-axis rotation)
        siny_cosp = +2.0 * (w * z + x * y)
        cosy_cosp = +1.0 - 2.0 * (y * y + z * z)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        return roll, pitch, yaw

def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()