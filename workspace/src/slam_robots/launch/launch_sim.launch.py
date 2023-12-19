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

    package_name='slam_robots' #<--- CHANGE ME

    # Set ignition resource path
    pkg_slam_robots = get_package_share_directory('slam_robots') # get the share directory of the current packate ('slam_robots')
    slam_robots_world = PathJoinSubstitution([pkg_slam_robots, 'worlds', 'world_classic.sdf'])  # get the path of the world.sdf to run the robot on it


    # Set the path to the world file
    world_file_name = 'world_classic.sdf'
    world_path = os.path.join(pkg_slam_robots, 'worlds', world_file_name)
    
    # Set the path to the SDF model files.
    gazebo_models_path = os.path.join(pkg_slam_robots, 'worlds')
    os.environ["GAZEBO_MODEL_PATH"] = gazebo_models_path


    declare_world_cmd = DeclareLaunchArgument(
        name='world',
        default_value=world_path,
        description='Full path to the world model file to load')

    # ign_resource_path = SetEnvironmentVariable(
    #     name='IGN_GAZEBO_RESOURCE_PATH',
    #     value=[
    #             os.path.join(pkg_slam_robots, 'worlds')
    #         ])
    
    # ign_resource_path = SetEnvironmentVariable(
    #     name='GAZEBO_MODEL_PATH',
    #     value=[
    #             os.path.join(pkg_slam_robots, 'worlds')
    #         ])

    # gazebo_resource_path = SetEnvironmentVariable(
    #     name='GAZEBO_RESOURCE_PATH',
    #     value=[
    #             os.path.join(pkg_slam_robots, 'worlds')
    #         ])
    # gazebo_model_path = SetEnvironmentVariable(
    #     name='GAZEBO_MODEL_PATH',
    #     value=[
    #             os.path.join(pkg_slam_robots, 'worlds')
    #         ])
    
    # os.environ['GAZEBO_RESOURCE_PATH'] = os.environ['HOME']+'/Github_repos/SLAM-mapping-Robots/workspace/install/slam_robots/share/slam_robots/worlds'
    # os.environ['GAZEBO_MODEL_PATH'] = os.environ['HOME']+'/Github_repos/SLAM-mapping-Robots/workspace/install/slam_robots/share/slam_robots/worlds'



    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','robot_launch.launch.py'
                )]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'false'}.items()
    )

    # joystick = IncludeLaunchDescription(
    #             PythonLaunchDescriptionSource([os.path.join(
    #                 get_package_share_directory(package_name),'launch','joystick.launch.py'
    #             )]), launch_arguments={'use_sim_time': 'true'}.items()
    # )

    # twist_mux_params = os.path.join(get_package_share_directory(package_name),'config','twist_mux.yaml')
    # twist_mux = Node(
    #         package="twist_mux",
    #         executable="twist_mux",
    #         parameters=[twist_mux_params, {'use_sim_time': True}],
    #         remappings=[('/cmd_vel_out','/diff_cont/cmd_vel_unstamped')]
    #     )




    gazebo_params_file = os.path.join(get_package_share_directory(package_name),'config','gazebo_params.yaml')

    # Include the Gazebo launch file, provided by the gazebo_ros package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
                    launch_arguments={'extra_gazebo_args': '--ros-args --params-file ' + gazebo_params_file}.items()
             )
    #'world': 'world_classic.sdf',

    # pkg_ros_ign_gazebo = get_package_share_directory('ros_ign_gazebo'); # get gazebo share directory through which we can run gazebo
    # ign_gazebo_launch = PathJoinSubstitution([pkg_ros_ign_gazebo, 'launch', 'ign_gazebo.launch.py'])    # get the path of ignition gazebo launch file
    # gazebo = IncludeLaunchDescription(
    #             PythonLaunchDescriptionSource([ign_gazebo_launch]),
    #                 launch_arguments=[('ign_args', [slam_robots_world])] #, '--ros-args --params-file ' + gazebo_params_file])]
    #          )
    
    # gazebo = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([ign_gazebo_launch]),
    #     launch_arguments=[
    #             ('ign_args', [slam_robots_world])
    #         ]
    # )

    # Run the spawner node from the gazebo_ros package. The entity name doesn't really matter if you only have a single robot.
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'my_bot',
                                   '-x', '4',
                                   '-y', '10'],
                        output='screen')


    # spawn_entity = Node(package='ros_ign_gazebo', executable='create',
    #                     arguments=['-topic', 'robot_description',
    #                                '-entity', 'my_bot'],
    #                     output='screen')

    # spawn_entity = Node( package='ros_gz_sim', executable='create', arguments=[ '-name', 'ROBOT_NAME', '-topic', 'robot_description', ], output='screen', ) 

    # diff_drive_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner.py",
    #     arguments=["diff_cont"],
    # )

    # joint_broad_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner.py",
    #     arguments=["joint_broad"],
    # )


    # Code for delaying a node (I haven't tested how effective it is)
    # 
    # First add the below lines to imports
    # from launch.actions import RegisterEventHandler
    # from launch.event_handlers import OnProcessExit
    #
    # Then add the following below the current diff_drive_spawner
    # delayed_diff_drive_spawner = RegisterEventHandler(
    #     event_handler=OnProcessExit(
    #         target_action=spawn_entity,
    #         on_exit=[diff_drive_spawner],
    #     )
    # )
    #
    # Replace the diff_drive_spawner in the final return with delayed_diff_drive_spawner



    # Launch them all!
    return LaunchDescription([
        # gazebo_resource_path,
        # gazebo_model_path,
        declare_world_cmd,
        rsp,
        # joystick,
        # twist_mux,
        gazebo,
        spawn_entity,
        # diff_drive_spawner,
        # joint_broad_spawner
    ])
