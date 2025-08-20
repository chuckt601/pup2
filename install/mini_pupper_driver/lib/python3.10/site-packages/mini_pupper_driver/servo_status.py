#from __future__ import print_function
import rclpy
from rclpy.node import Node
from MangDang.mini_pupper.ESP32Interface import ESP32Interface
from std_msgs.msg import Int64MultiArray
from std_msgs.msg import Float64MultiArray
from std_msgs.msg import Float64
from trajectory_msgs.msg import JointTrajectory
from champ_msgs.msg import ContactsStamped
#include <champ_msgs/msg/contacts_stamped.hpp>
import numpy as np


class ServoStatus(Node):
    class lpfilter:
        def __init__(self):
            self.decay=0.96
            self.b=1-self.decay
            self.filter_out=0.0
        def update_lpfilter(self, input): 
            self.filter_out += self.b*(input-self.filter_out)   
            return self.filter_out 

    def __init__(self):
        super().__init__('Servo_Status')        
        self.publisherTorque_ = self.create_publisher(Float64MultiArray, 'measured_torque', 10)
        self.publisherPosition_ = self.create_publisher(Int64MultiArray, 'measured_position', 10)
        self.publisherFootForce_ = self.create_publisher(Float64MultiArray, 'measured_footForce', 10)
        self.publisherFFFR_ = self.create_publisher(Float64,'FF_FR',10)
        self.publisherContact_ = self.create_publisher(ContactsStamped,'foot_contact_torque',10)
        self.subscriber = self.create_subscription(
            JointTrajectory, '/joint_group_effort_controller/joint_trajectory',
            self.cmd_callback, 1)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)        
        self.ESP32_interface = ESP32Interface()
        rf2_position=3.5
        #self.torque_int=[0,0,0,0,0,0,0,0,0,0,0,0]
        self.torque_int=[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
        self.torque_float=[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
        self.torque_sign=[1.0,1.0,-1.0,1.0,1.0,1.0,1.0,1.0,-1.0,1.0,1.0,1.0]
        self.footForce=[0.0,0.0,0.0,0.0]
        self.footForceFiltered=[0.0,0.0,0.0,0.0]
        self.ma_filter = MovingAverageFilter(40)
        self.footForceFiltered_FL = self.lpfilter()
        self.footForceFiltered_FR = self.lpfilter()
        self.footForceFiltered_BL = self.lpfilter()
        self.footForceFiltered_BR = self.lpfilter()
    
    def cmd_callback(self, msg):
        joint_positions = msg.points[0].positions
        lf1_position = joint_positions[0]
        lf2_position = joint_positions[1]
        lf3_position = joint_positions[2]
        rf1_position = joint_positions[3]
        rf2_position = joint_positions[4]
        rf3_position = joint_positions[5]
        lb1_position = joint_positions[6]
        lb2_position = joint_positions[7]
        lb3_position = joint_positions[8]
        rb1_position = joint_positions[9]
        rb2_position = joint_positions[10]
        rb3_position = joint_positions[11]
        upper_leg_length=50
        lower_leg_length=60
        sholder_length=18

        self.joint_angles = np.array([
            [rf1_position, lf1_position, rb1_position, lb1_position],
            [rf2_position, lf2_position, rb2_position, lb2_position],
            [rf2_position + rf3_position, lf2_position + lf3_position,
             rb2_position + rb3_position, lb2_position + lb3_position]
     ]) 
        near_zero_indices = np.abs(self.joint_angles) < .0001
        self.joint_angles[near_zero_indices] = .0001
        self.torques_array = np.array([
            [float(self.torque_float[0]), float(self.torque_float[3]), float(self.torque_float[6]), float(self.torque_float[9])],
            [float(self.torque_float[1]), float(self.torque_float[4]), float(self.torque_float[7]), float(self.torque_float[10])],
            [float(self.torque_float[2]), float(self.torque_float[5]), float(self.torque_float[8]), float(self.torque_float[11])]
            ]) 
        #arm_array=(self.joint_angles[0,0],self.joint_angles[0,1],self.joint_angles[0,2],self.joint_angles[0,3])
        #arm_array=(self.joint_angles)
        leg=0
        self.footForce[leg]=(1*self.torques_array[2,leg]/(lower_leg_length*np.cos(self.joint_angles[2,leg]))
        +self.torques_array[1,leg]/(upper_leg_length*np.cos(self.joint_angles[1,leg]))
        +self.torques_array[0,leg]/(sholder_length*np.cos(self.joint_angles[0,leg])))
        self.footForceFiltered[leg]=self.footForceFiltered_FL.update_lpfilter(self.footForce[leg])
         
        leg=1
        self.footForce[leg]=(+1*self.torques_array[2,leg]/(lower_leg_length*np.cos(self.joint_angles[2,leg]))
        -self.torques_array[1,leg]/(upper_leg_length*np.cos(self.joint_angles[1,leg]))
        -self.torques_array[0,leg]/(sholder_length*np.cos(self.joint_angles[0,leg]))
        ) 
        self.footForceFiltered[leg]=self.footForceFiltered_FR.update_lpfilter(self.footForce[leg])
        leg=2
        self.footForce[leg]=(1*self.torques_array[2,leg]/(lower_leg_length*np.cos(self.joint_angles[2,leg]))
        +self.torques_array[1,leg]/(upper_leg_length*np.cos(self.joint_angles[1,leg]))
        -self.torques_array[0,leg]/(sholder_length*np.cos(self.joint_angles[0,leg]))
        ) 
        self.footForceFiltered[leg]=self.footForceFiltered_BL.update_lpfilter(self.footForce[leg])
        leg=3
        self.footForce[leg]=(+1*self.torques_array[2,leg]/(lower_leg_length*np.cos(self.joint_angles[2,leg]))
        -self.torques_array[1,leg]/(upper_leg_length*np.cos(self.joint_angles[1,leg]))
        +self.torques_array[0,leg]/(sholder_length*np.cos(self.joint_angles[0,leg]))
        ) 
        self.footForceFiltered[leg]=self.footForceFiltered_BR.update_lpfilter(self.footForce[leg])      
        sensor_data = Float64MultiArray()
        #first_row = self.torques_array[2] 
        #first_column = self.torques_array[:, 0]
        #sensor_data.data = first_row.tolist()  
        sensor_data.data = self.footForceFiltered
        self.publisherFootForce_.publish(sensor_data)
        #FR_data = Float64()
        #FR_data.data = self.footForceFiltered[0] #self.ma_filter.update(self.footForce[0])

        #self.publisherFFFR_.publish(FR_data)
        #sensor_data.data = rf2_position      
        #self.publisherfootForce_.publish(sensor_data)
        #self.get_logger().info("rf1_position is  %f" % (rf1_position))  
        #self.get_logger().info("rb2_position is") 
        #print("test")
        #elf.get_logger().info("Roll: %f degrees, Pitch: %f degrees, Yaw: %f degrees" % (roll_deg, pitch_deg, yaw_deg))
        footForceData = ContactsStamped()
        footForceData.header.stamp = self.get_clock().now().to_msg()  # Add current time to header
        footForceData.header.frame_id = "base_link"  # Example frame ID
        footForceData.contacts = [False] * 4
        for index,element in enumerate(self.footForceFiltered):            
            if element>.15:
                footForceData.contacts[index]=True
            
        self.publisherContact_.publish(footForceData)

    def timer_callback(self):        
        sensor_data = Float64MultiArray()  
        #self.torque_float = [float(x) for x in self.ESP32_interface.servos_get_torque()]  # Convert each int in the list to a float      
        
        self.torque_float = [float(x) * y for x, y in zip(self.ESP32_interface.servos_get_torque(),self.torque_sign)]
        #self.torque_int = self.ESP32_interface.servos_get_torque()        
        sensor_data.data = self.torque_float      
        self.publisherTorque_.publish(sensor_data)
        sensor_data = Int64MultiArray() 
        self.position_int = self.ESP32_interface.servos_get_position()        
        sensor_data.data = self.position_int        
        self.publisherPosition_.publish(sensor_data)    
        
class MovingAverageFilter:
    def __init__(self, n):
        if n <= 0:
            raise ValueError("The number of elements (n) must be a positive integer")
        self.n = n
        self.window = []
        self.sum_window = 0.0

    def update(self, new_value):
        new_value = float(new_value)
        self.window.append(new_value)
        self.sum_window += new_value

        if len(self.window) > self.n:
            self.sum_window -= self.window.pop(0)

        return self.sum_window / len(self.window)

def main(args=None):
    rclpy.init(args=args)
    Servo_status = ServoStatus()
    rclpy.spin(Servo_status)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    Servo_status.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()