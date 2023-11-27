cmake_minimum_required(VERSION 3.8)
project(slam_robots)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# find_package(turtlebot4_ignition_bringup REQUIRED)  # for turtle bot 4
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


# add executables
# add_executable(talker src/publisher_member_function.cpp)
# ament_target_dependencies(talker rclcpp std_msgs)


# for testing (not used in our project)
# if(BUILD_TESTING)
  #find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  #set(ament_cmake_cpplint_FOUND TRUE)
  #ament_lint_auto_find_test_dependencies()
#endif()

# so that ros2 can find 
# Install executible files. (make executable called bot1 directory available in workspace/install/slam_robots/lib/slam_robots) so that it is seen by the ros2 run execution command (must be before ament_package() )
# install(TARGETS
#   bot1
#   DESTINATION lib/${PROJECT_NAME})

# Install launch and world files. (make launch directory available in workspace/install/slam_robots/share/slam_robots) so that it is seen by the ros2 launch command (must be before ament_package() )
install(DIRECTORY
  launch worlds
  DESTINATION share/${PROJECT_NAME}
)

# installs the package.xml, registers the package with the ament index, and installs configuration (and possibly target) files for CMake so that it can be found by other packages using find_package and it shall be the last call in CMakeLists.txt
ament_package()
