import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro


def generate_launch_description():

    # Check if we're told to use sim time
    use_sim_time = LaunchConfiguration('use_sim_time')
    use_ros2_control = LaunchConfiguration('use_ros2_control')
    name = LaunchConfiguration('name')

    # Process the URDF file
    pkg_path = os.path.join(get_package_share_directory('slam_robots'))
    xacro_file = os.path.join(pkg_path,'robot','robot.urdf.xacro')
    # robot_description_config = xacro.process_file(xacro_file).toxml()
    robot_description_config = Command(['xacro ', xacro_file, ' robot1:=true'])

    # robot_description_config = xacro.process_file(urdf_file_path, mappings={'robot_name_arg': args.drone_name}) #remap link/joint namespaces in xacro file
    # robot_desc = robot_description_config.toxml() #convert xacro to xml string
    
    # Create a robot_state_publisher node (this will publish to the spawn node by gazebo)
    params = {'robot_description': robot_description_config, 'use_sim_time': use_sim_time}
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params],
        namespace=name
    )

    # Launch!
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use sim time if true'),
        DeclareLaunchArgument(
            'use_ros2_control',
            default_value='true',
            description='Use ros2_control if true'),
        DeclareLaunchArgument(
            'name',
            default_value='',
            description='namespace for the robot'),

        node_robot_state_publisher,
    ])
