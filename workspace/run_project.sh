colcon build --packages-select slam_robots
source install/setup.bash
# ros2 launch slam_robots slam_robots_main.launch.py\
ros2 launch slam_robots slam_robots_bot3.launch.py