#!/usr/bin/env python3
#credits to: https://github.com/ros-teleop/teleop_twist_keyboard/blob/master/teleop_twist_keyboard.py

from __future__ import print_function

import select
import sys
import termios
import tty

import numpy as np
import rclpy

from champ_msgs.msg import Pose as PoseLite
from geometry_msgs.msg import Pose as Pose
from geometry_msgs.msg import Twist
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32
#from example_interfaces.msg import Float32MultiArray
from std_msgs.msg import Float32MultiArray

def quaternion_from_euler(roll, pitch, yaw):
    """
    Converts euler roll, pitch, yaw to quaternion (w in last place)
    quat = [x, y, z, w]
    Bellow should be replaced when porting for ROS 2 Python tf_conversions is done.
    """
    """
        Reading from the keyboard  and Publishing to Twist!
        ---------------------------
        Moving around:
        u    i    o
        j    k    l
        m    ,    .
        For Holonomic mode (strafing), hold down the shift key:
        ---------------------------
        U    I    O
        J    K    L
        M    <    >
        t : up (+z)
        b : down (-z)
        anything else : stop
        q/z : increase/decrease max speeds by 10%
        w/x : increase/decrease only linear speed by 10%
        e/c : increase/decrease only angular speed by 10%
        CTRL-C to quit
    """

    cy = np.cos(yaw * 0.5)
    sy = np.sin(yaw * 0.5)
    cp = np.cos(pitch * 0.5)
    sp = np.sin(pitch * 0.5)
    cr = np.cos(roll * 0.5)
    sr = np.sin(roll * 0.5)

    q = [0] * 4
    q[0] = cy * cp * cr + sy * sp * sr
    q[1] = cy * cp * sr - sy * sp * cr
    q[2] = sy * cp * sr + cy * sp * cr
    q[3] = sy * cp * cr - cy * sp * sr

    return q

class Teleop(Node):
    def __init__(self):
        super().__init__('champ_teleop')
       
        self.velocity_publisher = self.create_publisher(Twist, 'cmd_vel', 1)
        self.pose_lite_publisher = self.create_publisher(PoseLite, 'body_pose/raw', 1)
        self.pose_publisher = self.create_publisher(Pose, 'body_pose', 1)
        self.arm_offset_publisher=self.create_publisher(Float32MultiArray, 'arm_offset',1)
        self.CG_offset_publisher=self.create_publisher(Float32MultiArray, 'CG_offset',1)

        
        self.joy_subscriber = self.create_subscription(Joy, 'joy', self.joy_callback, 1)
        self.roll_subscriber = self.create_subscription(Float32, 'roll', self.roll_callback, 1)
        self.pitch_subscriber = self.create_subscription(Float32, 'pitch', self.pitch_callback, 1)
        self.imu_roll=0.0
        self.imu_pitch=0.0
        self.pose_roll=0.0
        self.pose_pitch=0.0

        self.pitch_target=0.0
        self.roll_target=0.0
        self.yaw_target=0.0
        self.Z_target=0.0       
        
        self.body_pose_lite = PoseLite()
        self.body_pose_lite.x = 0.0
        self.body_pose_lite.y = 0.0
        self.body_pose_lite.pitch = 0.0
        self.body_pose_lite.yaw = 0.0
        self.body_pose_lite.roll = 0.0

        self.declare_parameter("gait/swing_height", 0)
        self.declare_parameter("gait/nominal_height", 0)
        self.declare_parameter("speed", 0.5)
        self.declare_parameter("turn", 1.0)
        self.declare_parameter("joy", True)
        
        self.swing_height = self.get_parameter("gait/swing_height").value
        self.nominal_height = self.get_parameter("gait/nominal_height").value

        self.speed = self.get_parameter("speed").value
        self.turn = self.get_parameter("turn").value
        self.use_joy = self.get_parameter("joy").value
        self.msg = ""
        self.cg_shift_target_x = 0.0
        self.cg_shift_target_y = 0.0
        self.cg_shift_x = 0.0
        self.cg_shift_y = 0.0
        

        self.velocityBindings = {
                'i':(1,0,0,0),
                'o':(1,0,0,-1),
                'j':(0,0,0,1),
                'k':(0,0,0,0),
                'l':(0,0,0,-1),
                'u':(1,0,0,1),
                ',':(-1,0,0,0),
                '.':(-1,0,0,1),
                'm':(-1,0,0,-1),
                'O':(1,-1,0,0),
                'I':(1,0,0,0),
                'J':(0,1,0,0),
                'L':(0,-1,0,0),
                'U':(1,1,0,0),
                '<':(-1,0,0,0),
                '>':(-1,-1,0,0),
                'M':(-1,1,0,0),
                'v':(0,0,1,0),
                'n':(0,0,-1,0),
            }

        self.poseBindings = {
                'f':(-1,0,0,0),
                'h':(1,0,0,0),
                't':(0,1,0,0),
                'b':(0,-1,0,0),
                'r':(0,0,1,0),
                'y':(0,0,-1,0),
            }

        self.speedBindings={
                'q':(1.1,1.1),
                'z':(.9,.9),
                'w':(1.1,1),
                'x':(.9,1),
                'e':(1,1.1),
                'c':(1,.9),
            }
        
        self.offset_ammount=0.0 

        self.get_logger().info("use_joy is  %s" % self.use_joy)
        if self.use_joy==False:  
            self.poll_keys()
            
    def roll_callback(self, data):
        self.imu_roll = data.data
        #self.get_logger().info("roll is  %f" % self.roll)

    def pitch_callback(self, data):
        self.imu_pitch = data.data
        #self.get_logger().info("pitch is  %f" % self.pitch) 
        #body_pose_lite.roll = ((not data.buttons[5]) *-data.axes[3] * 0.349066) - (self.roll*3.14/180.0)
        if self.imu_roll>45: self.imu_roll=45.0
        if self.imu_roll<-45: self.imu_roll=-45.0
        if self.imu_pitch>45: self.imu_pitch=45.0
        if self.imu_pitch<-45: self.imu_pitch=-45.0
        self.body_pose_lite.roll = self.pose_roll+.12*(self.roll_target- (self.imu_roll*3.14/180.0))
        #body_pose_lite.pitch = data.axes[4] * 0.174533 + self.imu_pitch*3.14/180
        self.body_pose_lite.pitch = self.pose_pitch+.12*(-self.pitch_target + (self.imu_pitch+4)*3.14/180)
        self.pose_roll=self.body_pose_lite.roll
        self.pose_pitch=self.body_pose_lite.pitch
        self.body_pose_lite.yaw = self.yaw_target * 0.436332
        
        if self.Z_target < 0:
            self.body_pose_lite.z = self.Z_target
        else:
            self.body_pose_lite.z = 0.0

        self.pose_lite_publisher.publish(self.body_pose_lite)

        #self.cg_shift_x=self.cg_shift_x+.1*(self.cg_shift_target_x-self.cg_shift_x)
        #self.cg_shift_y=self.cg_shift_y+.1*(self.cg_shift_target_y-self.cg_shift_y)

        body_pose = Pose()
        body_pose.position.z = self.body_pose_lite.z
        body_pose.position.x = self.cg_shift_x
        body_pose.position.y = self.cg_shift_y
        quaternion = quaternion_from_euler(self.body_pose_lite.roll, self.body_pose_lite.pitch, self.body_pose_lite.yaw)
        body_pose.orientation.x = quaternion[1]
        body_pose.orientation.y = quaternion[2]
        body_pose.orientation.z = quaternion[3]
        body_pose.orientation.w = quaternion[0]

        self.pose_publisher.publish(body_pose)  

    def joy_callback(self, data):
        twist = Twist()
        twist.linear.x = data.axes[1] * self.speed
        twist.linear.y = data.buttons[4] * data.axes[0] * self.speed
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = (not data.buttons[4]) * data.axes[0] * self.turn
        self.velocity_publisher.publish(twist) 

        self.roll_target=(not data.buttons[5]) *-data.axes[3] * 0.349066 
        self.pitch_target=-data.axes[4] * 0.174533 
        self.yaw_target=(data.buttons[5]) *data.axes[3] * 0.436332 
        self.Z_target=data.axes[5] * 0.5 
        #self.cg_shift_x=data.axes[7]*.01 
        #self.cg_shift_y=data.axes[6]*.01 

        self.cg_shift_target_x=-data.axes[7]*.02 + data.axes[6]*.02
        self.cg_shift_target_y=-data.axes[7]*.02 - data.axes[6]*.02
        msg = Float32MultiArray()
        msg.data = [self.cg_shift_target_x, self.cg_shift_target_y]
        #self.CG_offset_publisher.publish(msg)

        if data.buttons[0] or data.buttons[1] or data.buttons[2] or data.buttons[3]:
           if data.buttons[1]:
               offset_arm=1.0
           elif data.buttons[0]:
               offset_arm=3.0
           elif data.buttons[2]:
               offset_arm=2.0
           elif data.buttons[3]:
               offset_arm=0.0
           if  data.buttons[4]:            
               self.offset_ammount+=0.001
           elif data.axes[2]==-1:            
               self.offset_ammount-=0.001 
           if data.buttons[5]:
               offset_arm=1.0
               self.offset_ammount=0.0            
           msg = Float32MultiArray()
           msg.data = [offset_arm,self.offset_ammount]       
           self.arm_offset_publisher.publish(msg)     


    def poll_keys(self):
        #self.get_logger().info("Initializing display interface")
        self.settings = termios.tcgetattr(sys.stdin)

        x = 0
        y = 0
        z = 0
        th = 0
        roll = 0
        pitch = 0
        yaw = 0
        status = 0
        cmd_attempts = 0

        try:
            print(self.msg)
            print(self.vels( self.speed, self.turn))

            while rclpy.ok():

                key = self.getKey()
                if key in self.velocityBindings.keys():
                    x = self.velocityBindings[key][0]
                    y = self.velocityBindings[key][1]
                    z = self.velocityBindings[key][2]
                    th = self.velocityBindings[key][3]
                    
                    if cmd_attempts > 1:
                        twist = Twist()
                        twist.linear.x = x *self.speed
                        twist.linear.y = y * self.speed
                        twist.linear.z = z * self.speed
                        twist.angular.x = 0.0
                        twist.angular.y = 0.0
                        twist.angular.z = th * self.turn
                        self.velocity_publisher.publish(twist)

                    cmd_attempts += 1
                    
                elif key in self.speedBindings.keys():
                    self.speed = self.speed * self.speedBindings[key][0]
                    self.turn = self.turn * self.speedBindings[key][1]
                    
                    print(self.vels(self.speed, self.turn))
                    if (status == 14):
                        print(self.msg)
                    status = (status + 1) % 15

                else:
                    cmd_attempts = 0
                    if (key == '\x03'):
                        break

        except Exception as e:
            print(e)

        finally:
            twist = Twist()
            twist.linear.x = 0.0
            twist.linear.y = 0.0
            twist.linear.z = 0.0
            twist.angular.x = 0.0
            twist.angular.y = 0.0
            twist.angular.z = 0.0
            self.velocity_publisher.publish(twist)

            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
            
        
    def getKey(self):
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        if rlist:
            key = sys.stdin.read(1)
        else:
            key = ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def vels(self, speed, turn):
        return "currently:\tspeed %s\tturn %s " % (speed,turn)

    def map(self, x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

def main(args=None):
    rclpy.init(args=args)
    teleop_node = Teleop()
    rclpy.spin(teleop_node)
    rclpy.shutdown()




if __name__ == "__main__":
    main()
    #rclpy.init()
    #teleop = Teleop()

