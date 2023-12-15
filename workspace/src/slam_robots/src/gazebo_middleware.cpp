#include <memory>
#include <string>
#include <boost/filesystem.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// type of messages published published by gazebo, in order to know what are the members of each, refer to the launch file 
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"


// _1 defines the number of arguments for the call back function which is 1
using std::placeholders::_1;

class GazeboMiddleware : public rclcpp::Node
{
  
  private:
    // 
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_change_subscription_;
    void odomerty_callback(const nav_msgs::msg::Odometry & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: %f", msg.pose.pose.position.x);
    }
  
  public:
    GazeboMiddleware(): Node("gazebo_middleware_listener")
    {
      // subscribe to a topic called /model/robot2/odometry where the depth of topic is 10, type of message is nav_msgs::msg::odometry and bind a callback
      auto odometryCallback = std::bind(&GazeboMiddleware::odomerty_callback, this, _1);
      odometry_change_subscription_ = this->create_subscription<nav_msgs::msg::Odometry>("/model/robot2/odometry", 10, odometryCallback);
    }


};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GazeboMiddleware>());
  rclcpp::shutdown();
  return 0;
}
