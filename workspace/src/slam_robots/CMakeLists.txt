cmake_minimum_required(VERSION 3.8)
project(slam_robots)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# below depenecies are related to packages in src directory
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

# add executables so that we can run our node using ros2 run command 
add_executable(gazebo_middleware src/gazebo_middleware.cpp)
ament_target_dependencies(gazebo_middleware rclcpp sensor_msgs geometry_msgs nav_msgs std_msgs)

# so that ros2 can find 
# Install executible files. (make executable called gazebo_middleware directory available in workspace/install/slam_robots/lib/slam_robots) so that it is seen by the ros2 run execution command (must be before ament_package() )
install(TARGETS
  gazebo_middleware
  DESTINATION lib/${PROJECT_NAME})

# # same as above but for python files
# install(TARGETS
#   gazebo_mid
#   DESTINATION lib/${PROJECT_NAME})

# Install launch and world files. (make launch directory available in workspace/install/slam_robots/share/slam_robots) so that it is seen by the ros2 launch command (must be before ament_package() )
install(DIRECTORY
  launch worlds robot config
  DESTINATION share/${PROJECT_NAME}
)

# installs the package.xml, registers the package with the ament index, and installs configuration (and possibly target) files for CMake so that it can be found by other packages using find_package and it shall be the last call in CMakeLists.txt
ament_package()
