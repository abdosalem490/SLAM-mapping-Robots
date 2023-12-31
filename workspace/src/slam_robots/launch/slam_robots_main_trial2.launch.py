# OS lib for getting paths of files
import os

# helpful to the get the 'share' directory in which launch files are stored"
from ament_index_python.packages import get_package_share_directory

from pathlib import Path

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess, SetEnvironmentVariable
from launch.actions import IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import PushRosNamespace

# this function is called later by ros2 launch with same return type
def generate_launch_description():
    
    pkg_slam_robots = get_package_share_directory('slam_robots') # get the share directory of the current packate ('slam_robots')
    
    # Set the path to the world file
    world_file_name = 'world_classic.sdf'
    world_path = os.path.join(pkg_slam_robots, 'worlds', world_file_name)

    # Set the path to the SDF model files.
    gazebo_models_path = os.path.join(pkg_slam_robots, 'worlds')
    gazebo_model_path = SetEnvironmentVariable(name='GAZEBO_MODEL_PATH', value=gazebo_models_path)
    # os.environ["GAZEBO_MODEL_PATH"] = gazebo_models_path


    declare_world_cmd = DeclareLaunchArgument(
        name='world',
        default_value=world_path,
        description='Full path to the world model file to load')


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

    # launch robot spawn file
    robot1_spawn = GroupAction(
            actions=[  
                # PushRosNamespace('robot1'),
                IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    pkg_slam_robots, 'launch', 'entity_spawn.launch.py')]),
                    launch_arguments={
                        'name': 'robot1'
                    }.items()
                )
            ]
    )
                
    
    # Create launch description and add actions
    ld = LaunchDescription(None)
    # ld.add_action(gazebo)
    # ld.add_action(gazebo_model_path)
    # ld.add_action(rviz2_command)
    # ld.add_action(declare_world_cmd)
    ld.add_action(robot1_spawn)
    return ld

