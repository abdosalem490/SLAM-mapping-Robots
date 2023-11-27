# OS lib for getting paths of files
import os

# helpful to the get the 'share' directory in which launch files are stored"
from ament_index_python.packages import get_package_share_directory

from pathlib import Path

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess, SetEnvironmentVariable
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution

# create configuration variables for turtlebots
turtlebot4_1 = {
    'x': '0.0',
    'y': '0.0',
    'z': '0.0',
    'yaw': '3.15',
    'namespace': '/turtlebot3_1',
}

turtlebot4_2 = {
    'x': '10.0',
    'y': '10.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot3_2',
}

# this function is called later by ros2 launch with same return type
def generate_launch_description():

    # ------------------------------------------------------ Directories ------------------------------------------------------ #
    # get the paths of the share directory of different packages we want to run.                                                #
    # ------------------------------------------------------------------------------------------------------------------------- #
    pkg_ros_ign_gazebo = get_package_share_directory('ros_ign_gazebo'); # get gazebo share directory through which we can run gazebo
    pkg_slam_robots = get_package_share_directory('slam_robots') # get the share directory of the current packate ('slam_robots')
    pkg_turtlebot4_ignition_bringup = get_package_share_directory('turtlebot4_ignition_bringup')
    pkg_turtlebot4_description = get_package_share_directory('turtlebot4_description')
    
    # ------------------------------------------------------ Paths ------------------------------------------------------ #
    # used to extract the paths of the share files of different packages, as if any package wanted to allow anyone to     #
    # run it or configure it, that shall be done via package launch files where every launch file can have paramters to   #
    # configure paramters of the package.                                                                                 #
    # ------------------------------------------------------------------------------------------------------------------- #
    ign_gazebo_launch = PathJoinSubstitution([pkg_ros_ign_gazebo, 'launch', 'ign_gazebo.launch.py'])    # get the path of ignition gazebo launch file
    slam_robots_world = PathJoinSubstitution([pkg_slam_robots, 'worlds', 'world.sdf'])  # get the path of the world.sdf to run the robot on it
    slam_robots_turtlebots_launch = PathJoinSubstitution([pkg_slam_robots, 'launch', 'slam_robots_turtlebots.launch.py'])    # get the path of another launch file in same project that's responsible for bringing up turtlebots to life 
    robot_spawn_launch = PathJoinSubstitution([pkg_turtlebot4_ignition_bringup, 'launch', 'turtlebot4_spawn.launch.py'])
    pkg_irobot_create_description = get_package_share_directory('irobot_create_description')


    # ------------------------------------------------------ actions ------------------------------------------------------ #
    # used to run the launch files of different packages given the paramters to those packages.                             #
    # --------------------------------------------------------------------------------------------------------------------- #

    # set IGN_GAZEBO_RESOURCE_PATH environment variable to the parent folder of our model. so that gazebo can see all the include in the world directories
    # param: cmd a list where the first item is the executable and the rest are arguments to the executable
    # param: cwd the directory in which to run the executable
    # os.environ['IGN_GAZEBO_RESOURCE_PATH'] = os.environ['HOME']+'/Github_repos/SLAM-mapping-Robots/workspace/install/slam_robots/share/slam_robots/worlds'
    
    # Set ignition resource path
    ign_resource_path = SetEnvironmentVariable(
        name='IGN_GAZEBO_RESOURCE_PATH',
        value=[
            os.path.join(pkg_slam_robots, 'worlds'), ':' +
            str(Path(pkg_turtlebot4_description).parent.resolve()), ':' +
            str(Path(pkg_irobot_create_description).parent.resolve())])

    # execute the command 'ign gazebo world.sdf'
    ignition_gazebo_command = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([ign_gazebo_launch]),
        launch_arguments=[
            ('ign_args', [slam_robots_world])
            ]
    )

    # execute the launch file called 'slam_robots_turtlebots.launch.py' that's in the same project
    spawn_turtlebot4_1_command = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([slam_robots_turtlebots_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_1['namespace']),
            ('rviz', 'false'),
            ('use_sim_time', 'true'),
            ('model', 'standard'),
            ('localization', 'false'),
            ('slam', 'false'),
            ('nav2', 'false'),
            ('x', turtlebot4_1['x']),
            ('y', turtlebot4_1['y']),
            ('z', turtlebot4_1['z']),
            ('yaw', turtlebot4_1['yaw']),
            ]
    )
    spawn_turtlebot4_2_command = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([slam_robots_turtlebots_launch]),
        launch_arguments=[
            ('namespace', 'turtlebot2'),
            ('rviz', 'false'),
            ('use_sim_time', 'true'),
            ('model', 'standard'),
            ('localization', 'false'),
            ('slam', 'false'),
            ('nav2', 'false'),
            ('x', '1.0'),
            ('y', '0.0'),
            ('z', '0.0'),
            ('yaw', '0'),
            ]
    )
    # execute the launch file called 'turtlebot4_spawn.launch.py' that's in turtlebot4 package which is responsible for spawning one turtlebot4
    robot1_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_1['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_1['x']),
            ('y', turtlebot4_1['y']),
            ('z', turtlebot4_1['z']),
            ('yaw', turtlebot4_1['yaw']),
            ]
    )

    robot2_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_2['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_2['x']),
            ('y', turtlebot4_2['y']),
            ('z', turtlebot4_2['z']),
            ('yaw', turtlebot4_2['yaw']),
            ]
    )

    



    # Create launch description and add actions
    ld = LaunchDescription(None)
    ld.add_action(ign_resource_path)
    ld.add_action(ignition_gazebo_command)

    ld.add_action(robot2_spawn)
    # ld.add_action(robot1_spawn)
    # ld.add_action(spawn_turtlebot4_1_command)
    # ld.add_action(spawn_turtlebot4_2_command)
    return ld