cmake_minimum_required(VERSION 3.8)
project(single_leg_actions)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#find_package(rclpy REQUIRED)
find_package(champ_msgs REQUIRED)
#find_package(visualization_msgs REQUIRED)
#find_package(geometry_msgs REQUIRED)
#find_package(sensor_msgs REQUIRED)
#find_package(trajectory_msgs REQUIRED)
#find_package(nav_msgs REQUIRED)
#find_package(tf2_ros REQUIRED)
#find_package(urdf REQUIRED)
#find_package(champ REQUIRED)
#find_package(message_filters REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)
#find_package(behaviortree_cpp_v3 REQUIRED)
#find_package(nav2_behavior_tree)
#find_package(action_tutorials_interfaces)
#find_package(nav2_costmap_2d)
#find_package(nav2_common REQUIRED)
#find_package(nav2_msgs REQUIRED)
#find_package(single_leg_actions)
#find_package(rclcpp_lifecycle REQUIRED)
#find_package(builtin_interfaces REQUIRED)
#find_package(nav2_util REQUIRED)

#nav2_package()

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

set(library_name ${PROJECT_NAME})

set(dependencies
  rclcpp
  std_msgs
  #rclpy
  champ_msgs
  #visualization_msgs
  #geometry_msgs
  #sensor_msgs
  #trajectory_msgs
  #nav_msgs  
  #tf2_ros
  #urdf
  #message_filters
  #champ
  rclcpp_action
  #rosidl_default_runtime 
  #behaviortree_cpp_v3  
  #nav2_behavior_tree
  #action_tutorials_interfaces
  #nav2_costmap_2d
  #single_leg_actions
  #nav2_msgs
  #rclcpp_lifecycle
  #builtin_interfaces
  #nav2_util  
)



#add_library(${library_name} SHARED
#  src/behavior_tree_engine.cpp
#)

#ament_target_dependencies(
#  ${library_name}
#  ${dependencies}
#)

# Include directories
include_directories(
  #/opt/ros/humble/include
  #/home/ubuntu/ros_ws/src
  include
  #${ament_cmake_INCLUDE_DIRS}
  #${champ_INCLUDE_DIRS}
  #${champ_INCLUDE_DIRS}/champ/
  #${champ_INCLUDE_DIRS}/champ/champ/  
  #${PROJECT_SOURCE_DIR}/include
  #${CMAKE_CURRENT_BINARY_DIR}/rosidl_typesupport_cpp
  #${behaviortree_cpp_v3_INCLUDE_DIRS}
  #${rclcpp_action_INCLUDE_DIRS}
)

#if(BUILD_TESTING)
#  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
#  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
#  set(ament_cmake_cpplint_FOUND TRUE)
#  ament_lint_auto_find_test_dependencies()
#endif()



#add_library(nav2_wait_action_bt_node SHARED plugins/action/wait_action.cpp)
#list(APPEND plugin_libs nav2_wait_action_bt_node)

# Add action files
#set(ROSIDL_TYPESUPPORT_CPP_TYPE rosidl_typesupport_cpp)
#set(ROSIDL_TYPESUPPORT_INTERFACE rosidl_typesupport_interface)

find_package(rosidl_default_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/LegMoveActions.action"
)

#foreach(bt_plugin ${plugin_libs})
#  ament_target_dependencies(${bt_plugin} ${dependencies})
#  target_compile_definitions(${bt_plugin} PRIVATE BT_PLUGIN_EXPORT)
#endforeach()


# LegMove Node
add_executable(leg_move_node src/leg_move_node.cpp)
rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(leg_move_node ${typesupport_target})
ament_target_dependencies(leg_move_node
  rclcpp
  rclcpp_action
  std_msgs
  champ_msgs
  #rosidl_typesupport_cpp
)

#LegMove action Node
#add_executable(leg_move_action_node src/leg_move_action_node.cpp)
#rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
#target_link_libraries(leg_move_action_node 
#  ${rclcpp_action_LIBRARIES}
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

#bt action Node
#add_executable(bt_action_node src/bt_action_node.cpp)
#rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
#target_link_libraries(bt_action_node 
#  rclcpp
#  rclcpp_action
#  #nav2_costmap_2d
#  behaviortree_cpp_v3
#  nav2_behavior_tree
#  ${typesupport_target}
#  )
#ament_target_dependencies(bt_action_node
#  rclcpp
#  rclcpp_action
#  action_msgs
#  geometry_msgs
#  #rosidl_typesupport_cpp
#  behaviortree_cpp_v3
#  #nav2_behavior_tree
#  #action_tutorials_interfaces
#  #nav2_costmap_2d
#)


#Install targets
install(TARGETS     
    leg_move_node
    #leg_move_action_node   
    #bt_action_node 
    #{library_name}
    #${plugin_libs}
    #LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    #ARCHIVE DESTINATION lib
    #DESTINATION lib/${PROJECT_NAME}
)

#ament_export_include_directories(
#  include
#)

#ament_export_libraries(
#  ${library_name}
#  ${plugin_libs}
#)

#ament_export_dependencies(${dependencies})
ament_export_dependencies(rosidl_default_runtime)
ament_package()
