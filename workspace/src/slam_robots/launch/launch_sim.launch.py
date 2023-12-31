import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node



def generate_launch_description():


    # Include the robot_state_publisher launch file, provided by our own package. Force sim time to be enabled
    # !!! MAKE SURE YOU SET THE PACKAGE NAME CORRECTLY !!!

    package_name='slam_robots'

    # Set ignition resource path
    pkg_slam_robots = get_package_share_directory(package_name) # get the share directory of the current packate ('slam_robots')
    slam_robots_world = PathJoinSubstitution([pkg_slam_robots, 'worlds', 'world_classic.sdf'])  # get the path of the world.sdf to run the robot on it


    # Set the path to the world file
    world_file_name = 'world_classic.sdf'
    world_path = os.path.join(pkg_slam_robots, 'worlds', world_file_name)
    
    # Set the path to the SDF model files.
    gazebo_models_path = os.path.join(pkg_slam_robots, 'worlds')


    declare_world_cmd = DeclareLaunchArgument(
        name='world',
        default_value=world_path,
        description='Full path to the world model file to load')


    gazebo_model_path = SetEnvironmentVariable(name='GAZEBO_MODEL_PATH', value=gazebo_models_path)

    robot1_launch = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    pkg_slam_robots, 'launch','robot_launch.launch.py'
                )]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'false'}.items()
    )

    # Run the spawner node from the gazebo_ros package. The entity name doesn't really matter if you only have a single robot.
    spawn1_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        # arguments=['-topic', 'robot_description',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'robot1',
                                   '-x', '4',
                                   '-y', '10'],
                        output='screen')
    
    robot2_launch = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    pkg_slam_robots, 'launch','robot_launch.launch.py'
                )]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'false', 'name': 'robot2'}.items()
    )

    # Run the spawner node from the gazebo_ros package. The entity name doesn't really matter if you only have a single robot.
    spawn2_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', '/robot2/robot_description',
                                   '-entity', 'robot2',
                                   '-x', '4',
                                   '-y', '10'],
                        output='screen')


    gazebo_params_file = os.path.join(pkg_slam_robots, 'config','gazebo_params.yaml')

    # Include the Gazebo launch file, provided by the gazebo_ros package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
                    launch_arguments={'extra_gazebo_args': '--ros-args --params-file ' + gazebo_params_file}.items()
             )

    
    # add the command 'rviz2 -d /home/abdosalm/Github_repos/SLAM-mapping-Robots/workspace/install/slam_robots/share/slam_robots/robot/rviz/final_config.rviz' that contains configuration for rviz
    rviz2_command = Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=[
                '-d', os.path.join(pkg_slam_robots, 'robot', 'rviz', 'final_config.rviz')
                ]
            )
                
    
    # add the command 'ros2 launch slam_toolbox online_async_launch.py slam_params_file:=./src/slam_robots/config/mapper_params_online_async.yaml use_sim_time:=true'
    slam_toolbox_launch =  IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(                
                    get_package_share_directory('slam_toolbox'), 'launch', 'online_async_launch.py'
                )]), launch_arguments={
                    'slam_params_file': os.path.join(pkg_slam_robots, 'config', 'mapper_params_online_async.yaml'), 
                    'use_sim_time': 'true'
                    }.items()
    )

    # add the command 'ros2 launch nav2_bringup navigation_launch.py use_sim_time:=true'
    robot_nav2_bringup =  IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(                
                    get_package_share_directory('nav2_bringup'), 'launch', 'navigation_launch.py'
                )]), launch_arguments={
                    'use_sim_time': 'true'
                    }.items()
    )    

    # add the command 'ros2 launch explore_lite explore.launch.py'
    robot_explore_launch =  IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(                
                    get_package_share_directory('explore_lite'), 'launch', 'explore.launch.py'
                )])
    )
    
    # Launch them all!
    return LaunchDescription([
        gazebo_model_path,
        slam_toolbox_launch,
        robot_nav2_bringup,
        robot_explore_launch,
        rviz2_command,
        declare_world_cmd,
        robot1_launch,
        spawn1_entity,
        # robot2_launch,
        # spawn2_entity,
        gazebo,
    ])