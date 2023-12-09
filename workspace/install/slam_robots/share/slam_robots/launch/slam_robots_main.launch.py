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
    # pkg_turtlebot4_ignition_bringup = get_package_share_directory('turtlebot4_ignition_bringup')
    # pkg_turtlebot4_description = get_package_share_directory('turtlebot4_description')
    
    # ------------------------------------------------------ Paths ------------------------------------------------------ #
    # used to extract the paths of the share files of different packages, as if any package wanted to allow anyone to     #
    # run it or configure it, that shall be done via package launch files where every launch file can have paramters to   #
    # configure paramters of the package.                                                                                 #
    # ------------------------------------------------------------------------------------------------------------------- #
    ign_gazebo_launch = PathJoinSubstitution([pkg_ros_ign_gazebo, 'launch', 'ign_gazebo.launch.py'])    # get the path of ignition gazebo launch file
    slam_robots_world = PathJoinSubstitution([pkg_slam_robots, 'worlds', 'world.sdf'])  # get the path of the world.sdf to run the robot on it
    # slam_robots_turtlebots_launch = PathJoinSubstitution([pkg_slam_robots, 'launch', 'slam_robots_turtlebots.launch.py'])    # get the path of another launch file in same project that's responsible for bringing up turtlebots to life 
    # robot_spawn_launch = PathJoinSubstitution([pkg_turtlebot4_ignition_bringup, 'launch', 'turtlebot4_spawn.launch.py'])
    # pkg_irobot_create_description = get_package_share_directory('irobot_create_description')


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
                os.path.join(pkg_slam_robots, 'worlds')
            ])

    # execute the command 'ign gazebo world.sdf'
    ignition_gazebo_command = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([ign_gazebo_launch]),
        launch_arguments=[
                ('ign_args', [slam_robots_world])
            ]
    )

    # ignition bridge which is used to make gazebo simulator topics seen be ROS2, refer to the end of file to know
    # what are the fields of each topic
    bridge = Node(
        package='ros_ign_bridge',
        executable='parameter_bridge',
        arguments=[
            # create odmetry bridges where the direction of each brdige is from gazebo to ros2
            # the odometry topic publishes how mush change happened to the robot pose
            '/model/robot1/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot2/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot3/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot4/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot5/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot6/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot7/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot8/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot9/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/model/robot10/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            # create cmd_vel bridges where the direction of each brdige is from ros2 to gazebo
            # ros2 will publish control command to control speed robot using cmd_vel topic
            '/model/robot1/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',            
            '/model/robot2/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot3/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot4/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot5/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot6/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot7/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot8/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot9/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist',           
            '/model/robot10/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist', 
            # create tf bridges where the direction of each brdige is from gazebo to ros2
            # gazebo will accumulate the odometry given only and only the actions to ease tracking theoretical place of the robot
            # note that: there are 2 publishers that publishes on tobic /tf where the 2 publishers publishes different types of messages
            # one is geometry_msgs/msg/Pose and the other is geometry_msgs/msg/PoseArray but we are only interested in the second one
            '/model/robot1/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot2/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot3/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot4/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot5/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot6/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot7/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot8/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot9/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            '/model/robot10/tf@geometry_msgs/msg/PoseArray[ignition.msgs.Pose_V',            
            # create lidar lidar bridges where the direction of each bridge is from gazebo to ros2
            # 
            '/model/robot1/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot2/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot3/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot4/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot5/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot6/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot7/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot8/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot9/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            
            '/model/robot10/lidar2@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',            

            ],
        output='screen'
    )



    # Create launch description and add actions
    ld = LaunchDescription(None)
    ld.add_action(ign_resource_path)
    ld.add_action(ignition_gazebo_command)
    ld.add_action(bridge)

    # ld.add_action(robot2_spawn)
    # ld.add_action(robot1_spawn)
    # ld.add_action(spawn_turtlebot4_1_command)
    # ld.add_action(spawn_turtlebot4_2_command)
    return ld




# ----------------------------------------------------- Topic fields ------------------------------------------------------ #
# know what are the fields of different topics to interface with them.                                                      #
# ------------------------------------------------------------------------------------------------------------------------- #


# --------------------------------- nav_msgs/msg/Odometry --------------------------------- #

# This represents an estimate of a position and velocity in free space.
# The pose in this message should be specified in the coordinate frame given by header.frame_id
# The twist in this message should be specified in the coordinate frame given by the child_frame_id

# # Includes the frame id of the pose parent.
# std_msgs/Header header
# 	builtin_interfaces/Time stamp
# 		int32 sec
# 		uint32 nanosec
# 	string frame_id

# # Frame id the pose points to. The twist is in this coordinate frame.
# string child_frame_id

# # Estimated pose that is typically relative to a fixed world frame.
# geometry_msgs/PoseWithCovariance pose
# 	Pose pose
# 		Point position
# 			float64 x
# 			float64 y
# 			float64 z
# 		Quaternion orientation
# 			float64 x 0
# 			float64 y 0
# 			float64 z 0
# 			float64 w 1
# 	float64[36] covariance

# # Estimated linear and angular velocity relative to child_frame_id.
# geometry_msgs/TwistWithCovariance twist
# 	Twist twist
# 		Vector3  linear
# 			float64 x
# 			float64 y
# 			float64 z
# 		Vector3  angular
# 			float64 x
# 			float64 y
# 			float64 z
# 	float64[36] covariance

# ----------------------------------------------------------------------------------------- #


# --------------------------------- nav_msgs/msg/Odometry --------------------------------- #

# # This expresses velocity in free space broken into its linear and angular parts.

# Vector3  linear
# 	float64 x
# 	float64 y
# 	float64 z
# Vector3  angular
# 	float64 x
# 	float64 y
# 	float64 z

# ----------------------------------------------------------------------------------------- #


# --------------------------------- geometry_msgs/msg/PoseArray --------------------------------- #


# # An array of poses with a header for global reference.

# std_msgs/Header header
# 	builtin_interfaces/Time stamp
# 		int32 sec
# 		uint32 nanosec
# 	string frame_id

# Pose[] poses
# 	Point position
# 		float64 x
# 		float64 y
# 		float64 z
# 	Quaternion orientation
# 		float64 x 0
# 		float64 y 0
# 		float64 z 0
# 		float64 w 1


# ----------------------------------------------------------------------------------------- #

# --------------------------------- sensor_msgs/msg/LaserScan --------------------------------- #

# # Single scan from a planar laser range-finder
# #
# # If you have another ranging device with different behavior (e.g. a sonar
# # array), please find or create a different message, since applications
# # will make fairly laser-specific assumptions about this data

# std_msgs/Header header # timestamp in the header is the acquisition time of
# 	builtin_interfaces/Time stamp
# 		int32 sec
# 		uint32 nanosec
# 	string frame_id
#                              # the first ray in the scan.
#                              #
#                              # in frame frame_id, angles are measured around
#                              # the positive Z axis (counterclockwise, if Z is up)
#                              # with zero angle being forward along the x axis

# float32 angle_min            # start angle of the scan [rad]
# float32 angle_max            # end angle of the scan [rad]
# float32 angle_increment      # angular distance between measurements [rad]

# float32 time_increment       # time between measurements [seconds] - if your scanner
#                              # is moving, this will be used in interpolating position
#                              # of 3d points
# float32 scan_time            # time between scans [seconds]

# float32 range_min            # minimum range value [m]
# float32 range_max            # maximum range value [m]

# float32[] ranges             # range data [m]
#                              # (Note: values < range_min or > range_max should be discarded)
# float32[] intensities        # intensity data [device-specific units].  If your
#                              # device does not provide intensities, please leave
#                              # the array empty.


# ----------------------------------------------------------------------------------------- #
