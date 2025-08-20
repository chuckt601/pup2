import rclpy
from rclpy.node import Node
from MangDang.mini_pupper.ESP32Interface import ESP32Interface
from std_msgs.msg import Float64
import numpy as np

class BatteryStatus(Node):

    def __init__(self):
        super().__init__('Battery_Status')        
        self.publisher_ = self.create_publisher(Float64, 'battery_voltage', 10)
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)        
        self.ESP32_interface = ESP32Interface()
        
    def timer_callback(self):        
        sensor_data = Float64()         
        power_status=self.ESP32_interface.get_power_status()
        if power_status is not None:        
           current_voltage=power_status['volt']     
           sensor_data.data = current_voltage      
           self.publisher_.publish(sensor_data)       
   

def main(args=None):
    rclpy.init(args=args)
    Battery_status = BatteryStatus()
    rclpy.spin(Battery_status)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    Battery_status.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()