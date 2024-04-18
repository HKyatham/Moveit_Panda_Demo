cmake_minimum_required(VERSION 3.22)
project(hkyatham_config)

find_package(ament_cmake REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_visual_tools REQUIRED)


include_directories(include)

add_executable(panda_moveit src/panda_moveit.cpp)
ament_target_dependencies(
  panda_moveit
  "moveit_ros_planning_interface"
  "moveit_visual_tools"
  "rclcpp"
)

install(TARGETS panda_moveit
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(FILES .setup_assistant DESTINATION share/${PROJECT_NAME})
