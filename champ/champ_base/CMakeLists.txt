cmake_minimum_required(VERSION 3.5)
project(champ_base)

add_compile_options(-std=c++17)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(champ_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(urdf REQUIRED)
find_package(champ REQUIRED)
find_package(message_filters REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)

# Specify dependencies in a variable for reuse
set(dependencies
  rclcpp
  rclpy
  champ_msgs
  visualization_msgs
  geometry_msgs
  sensor_msgs
  trajectory_msgs
  nav_msgs
  tf2_ros
  urdf
  message_filters
  champ
  rclcpp_action
  #rosidl_default_runtime 
  behaviortree_cpp_v3  
)




# Include directories
include_directories(
  include
  ${ament_cmake_INCLUDE_DIRS}
  ${champ_INCLUDE_DIRS}
  ${champ_INCLUDE_DIRS}/champ/
  #${champ_INCLUDE_DIRS}/champ/champ/
  ${champ_INCLUDE_DIRS}/champ/champ_base/
  ${PROJECT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}/
  ${behaviortree_cpp_v3_INCLUDE_DIRS}
)

# Add the action interface
#rosidl_generate_interfaces(${PROJECT_NAME}
#  "action/LegMoveActions.action"
#  DEPENDENCIES builtin_interfaces
#)

# Create libraries and nodes
add_library(quadruped_controller SHARED src/quadruped_controller.cpp)
ament_target_dependencies(quadruped_controller ${dependencies})

add_executable(quadruped_controller_node src/quadruped_controller_node.cpp)
target_link_libraries(quadruped_controller_node quadruped_controller)
ament_target_dependencies(quadruped_controller_node ${dependencies})

add_library(message_relay SHARED src/message_relay.cpp)
ament_target_dependencies(message_relay ${dependencies})

add_executable(message_relay_node src/message_relay_node.cpp)
target_link_libraries(message_relay_node message_relay)
ament_target_dependencies(message_relay_node ${dependencies})

add_library(state_estimation SHARED src/state_estimation.cpp)
ament_target_dependencies(state_estimation ${dependencies})

add_executable(state_estimation_node src/state_estimation_node.cpp)
target_link_libraries(state_estimation_node state_estimation)
ament_target_dependencies(state_estimation_node ${dependencies})

# LegMove Node
#add_executable(leg_move_node src/leg_move_node.cpp)
#rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
#target_link_libraries(leg_move_node ${typesupport_target})
#ament_target_dependencies(leg_move_node
#  rclcpp
#  rclcpp_action
#  champ_msgs
#  rosidl_typesupport_cpp
#)

 #LegMove action Node
#add_executable(leg_move_action_node src/leg_move_action_node.cpp)
#rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
#target_link_libraries(leg_move_action_node 
#  rclcpp_action
#  ${typesupport_target}
#  ${behaviortree_cpp_v3_LIBRARIES}
#  )
#ament_target_dependencies(leg_move_action_node
#  rclcpp
#  rclcpp_action
#  action_msgs
#  champ_msgs
#  rosidl_typesupport_cpp
#  behaviortree_cpp_v3
#)
# Install targets
install(TARGETS 
    quadruped_controller
    quadruped_controller_node
    message_relay
    message_relay_node
    state_estimation
    state_estimation_node
    #leg_move_node
    #leg_move_action_node    
    #LIBRARY DESTINATION lib
    #RUNTIME DESTINATION bin
    #ARCHIVE DESTINATION lib
    DESTINATION lib/${PROJECT_NAME}
)

#install(DIRECTORY config
#  DESTINATION share/${PROJECT_NAME}
#)




# Export dependencies
ament_export_include_directories(include)
ament_export_dependencies(${dependencies})
ament_package()


