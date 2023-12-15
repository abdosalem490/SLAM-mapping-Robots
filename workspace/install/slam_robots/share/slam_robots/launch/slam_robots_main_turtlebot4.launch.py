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
    'y': '1.0',
    'z': '0.0',
    'yaw': '3.15',
    'namespace': '/turtlebot4_1',
}

turtlebot4_2 = {
    'x': '-14.0',
    'y': '28.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_2',
}

turtlebot4_3 = {
    'x': '-14.0',
    'y': '6.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_3',
}

turtlebot4_4 = {
    'x': '-14.0',
    'y': '-16.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_4',
}

turtlebot4_5 = {
    'x': '-23.0',
    'y': '-38.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_5',
}

turtlebot4_6 = {
    'x': '10.0',
    'y': '-45.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_6',
}

turtlebot4_7 = {
    'x': '8.0',
    'y': '-27.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_7',
}

turtlebot4_8 = {
    'x': '10.0',
    'y': '-9.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_8',
}

turtlebot4_9 = {
    'x': '6.0',
    'y': '11.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_9',
}

turtlebot4_10 = {
    'x': '8.0',
    'y': '21.0',
    'z': '0.0',
    'yaw': '0.0',
    'namespace': '/turtlebot4_10',
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
    # slam_robots_turtlebots_launch = PathJoinSubstitution([pkg_slam_robots, 'launch', 'slam_robots_turtlebots.launch.py'])    # get the path of another launch file in same project that's responsible for bringing up turtlebots to life 
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

    # # execute the launch file called 'slam_robots_turtlebots.launch.py' that's in the same project
    # spawn_turtlebot4_1_command = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([slam_robots_turtlebots_launch]),
    #     launch_arguments=[
    #         ('namespace', turtlebot4_1['namespace']),
    #         ('rviz', 'false'),
    #         ('use_sim_time', 'true'),
    #         ('model', 'standard'),
    #         ('localization', 'false'),
    #         ('slam', 'false'),
    #         ('nav2', 'false'),
    #         ('x', turtlebot4_1['x']),
    #         ('y', turtlebot4_1['y']),
    #         ('z', turtlebot4_1['z']),
    #         ('yaw', turtlebot4_1['yaw']),
    #         ]
    # )
    # spawn_turtlebot4_2_command = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([slam_robots_turtlebots_launch]),
    #     launch_arguments=[
    #         ('namespace', 'turtlebot2'),
    #         ('rviz', 'false'),
    #         ('use_sim_time', 'true'),
    #         ('model', 'standard'),
    #         ('localization', 'false'),
    #         ('slam', 'false'),
    #         ('nav2', 'false'),
    #         ('x', '1.0'),
    #         ('y', '0.0'),
    #         ('z', '0.0'),
    #         ('yaw', '0'),
    #         ]
    # )

    # execute the launch file called 'turtlebot4_spawn.launch.py' that's in turtlebot4 package which is responsible for spawning one turtlebot4

    # Corridor robot
    robot1_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_1['namespace']),
            # ('rviz', 'true'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'true'),
            # ('slam', 'true'),
            # ('nav2', 'true'),
            ('x', turtlebot4_1['x']),
            ('y', turtlebot4_1['y']),
            ('z', turtlebot4_1['z']),
            ('yaw', turtlebot4_1['yaw']),
            ]
    )

    # Fourth year robot 
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

    # Third year robot 
    robot3_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_3['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_3['x']),
            ('y', turtlebot4_3['y']),
            ('z', turtlebot4_3['z']),
            ('yaw', turtlebot4_3['yaw']),
            ]
    )

    # Second year robot
    robot4_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_4['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_4['x']),
            ('y', turtlebot4_4['y']),
            ('z', turtlebot4_4['z']),
            ('yaw', turtlebot4_4['yaw']),
            ]
    )

    # First year robot
    robot5_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_5['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_5['x']),
            ('y', turtlebot4_5['y']),
            ('z', turtlebot4_5['z']),
            ('yaw', turtlebot4_5['yaw']),
            ]
    )

    # Library robot
    robot6_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_6['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_6['x']),
            ('y', turtlebot4_6['y']),
            ('z', turtlebot4_6['z']),
            ('yaw', turtlebot4_6['yaw']),
            ]
    )

    # First Lab robot
    robot7_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_7['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_7['x']),
            ('y', turtlebot4_7['y']),
            ('z', turtlebot4_7['z']),
            ('yaw', turtlebot4_7['yaw']),
            ]
    )

    # Second Lab robot
    robot8_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_8['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_8['x']),
            ('y', turtlebot4_8['y']),
            ('z', turtlebot4_8['z']),
            ('yaw', turtlebot4_8['yaw']),
            ]
    )

    # Third Lab robot
    robot9_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_9['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_9['x']),
            ('y', turtlebot4_9['y']),
            ('z', turtlebot4_9['z']),
            ('yaw', turtlebot4_9['yaw']),
            ]
    )

    # Fourth Lab robot
    robot10_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([robot_spawn_launch]),
        launch_arguments=[
            ('namespace', turtlebot4_10['namespace']),
            ('rviz', 'false'),
            # ('use_sim_time', 'true'),
            # ('model', 'standard'),
            # ('localization', 'false'),
            # ('slam', 'false'),
            # ('nav2', 'false'),
            ('x', turtlebot4_10['x']),
            ('y', turtlebot4_10['y']),
            ('z', turtlebot4_10['z']),
            ('yaw', turtlebot4_10['yaw']),
            ]
    )

    # Clock bridge
    clock_bridge = Node(package='ros_gz_bridge', executable='parameter_bridge',
                        name='clock_bridge',
                        output='screen',
                        arguments=[
                            '/clock' + '@rosgraph_msgs/msg/Clock' + '[ignition.msgs.Clock'
                        ])
    



    # Create launch description and add actions
    ld = LaunchDescription(None)
    ld.add_action(ign_resource_path)
    ld.add_action(ignition_gazebo_command)
    ld.add_action(clock_bridge)

    # couldn't spawn more than 3 robots as There seems to be a hard limit of ~120 nodes. 
    ld.add_action(robot1_spawn)
    ld.add_action(robot2_spawn)
    # ld.add_action(robot3_spawn)
    # ld.add_action(robot4_spawn)
    # ld.add_action(robot5_spawn)
    ld.add_action(robot6_spawn)
    # ld.add_action(robot7_spawn)
    # ld.add_action(robot8_spawn)
    # ld.add_action(robot9_spawn)
    # ld.add_action(robot10_spawn)
    # ld.add_action(spawn_turtlebot4_1_command)
    # ld.add_action(spawn_turtlebot4_2_command)
    return ld