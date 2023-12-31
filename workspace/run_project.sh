# importance of --symlink-install is: "instead of a copy of the launch file it will put a symbolic link to the launchfile. This means that if you change something to the launch file in your package you don't have to rebuild the package for the changes to take effect." 
colcon build --symlink-install --packages-select slam_robots
# so that the built packages can be seen in current terminal 
source install/setup.bash
# ros2 launch slam_robots slam_robots_main.launch.py
# ros2 launch slam_robots slam_robots_main_turtlebot4.launch.py
# ros2 launch slam_robots robot_launch.py use_sim_time:=true
# launch the main launch file
# ros2 launch slam_robots slam_robots_main.launch.py
ros2 launch slam_robots launch_sim.launch.py
 
