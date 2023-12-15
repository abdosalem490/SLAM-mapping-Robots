# SLAM-mapping-Robots
robots performing mapping in a real time

to run the project, go to the directory workspace and run: ros2 launch slam_robots slam_robots_launch.py



# How to solve error in Turtlebot4
edit /opt/ros/humble/share/irobot_create_description/urdf/create3.urdf.xacro
using command 'sudo gedit create3.urdf.xacro' and comment 

<gazebo>
      <plugin filename="libignition-gazebo-sensors-system.so" name="ignition::gazebo::systems::Sensors">
        <render_engine>ogre</render_engine>
      </plugin>
    </gazebo>
