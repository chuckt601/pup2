
import os

import launch_ros
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, LaunchConfiguration
from rcl_interfaces.msg import SetParametersResult


def generate_launch_description():

    use_sim_time = LaunchConfiguration("use_sim_time")
    use_joy = LaunchConfiguration("use_joy")
    dev_port = LaunchConfiguration("dev_port")
    
    declare_use_joy = DeclareLaunchArgument("use_joy", default_value="true", description="Use joy or keyboard")
    declare_dev_port = DeclareLaunchArgument("dev_port", default_value="/dev/input/js0", description="Path to joystick dev port")
    declare_use_sim_time = DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true")


 
    joy = Node(
        package="joy",
        output="screen",
        executable="joy_node",
        condition=IfCondition(use_joy),
        parameters=[
            {'use_sim_time': use_sim_time},
            {"dev_port": dev_port},
            {"autorepeat_rate": 5.0}
            ]
    )

    champ_teleop = Node(
        package="champ_teleop",
        executable="champ_teleop.py",
        # output="screen",
        #prefix="xterm -e",
        #emulate_tty=True,
        parameters=[
            {'use_sim_time': use_sim_time},
            {"joy": use_joy}
            ]
    )
    return LaunchDescription(
        [
            declare_use_sim_time,
            declare_use_joy,
            declare_dev_port,
           
            champ_teleop
        ]
    )
