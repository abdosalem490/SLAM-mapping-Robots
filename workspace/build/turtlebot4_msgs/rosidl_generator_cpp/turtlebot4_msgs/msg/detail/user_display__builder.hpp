// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__BUILDER_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlebot4_msgs/msg/detail/user_display__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlebot4_msgs
{

namespace msg
{

namespace builder
{

class Init_UserDisplay_selected_entry
{
public:
  explicit Init_UserDisplay_selected_entry(::turtlebot4_msgs::msg::UserDisplay & msg)
  : msg_(msg)
  {}
  ::turtlebot4_msgs::msg::UserDisplay selected_entry(::turtlebot4_msgs::msg::UserDisplay::_selected_entry_type arg)
  {
    msg_.selected_entry = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserDisplay msg_;
};

class Init_UserDisplay_entries
{
public:
  explicit Init_UserDisplay_entries(::turtlebot4_msgs::msg::UserDisplay & msg)
  : msg_(msg)
  {}
  Init_UserDisplay_selected_entry entries(::turtlebot4_msgs::msg::UserDisplay::_entries_type arg)
  {
    msg_.entries = std::move(arg);
    return Init_UserDisplay_selected_entry(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserDisplay msg_;
};

class Init_UserDisplay_battery
{
public:
  explicit Init_UserDisplay_battery(::turtlebot4_msgs::msg::UserDisplay & msg)
  : msg_(msg)
  {}
  Init_UserDisplay_entries battery(::turtlebot4_msgs::msg::UserDisplay::_battery_type arg)
  {
    msg_.battery = std::move(arg);
    return Init_UserDisplay_entries(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserDisplay msg_;
};

class Init_UserDisplay_ip
{
public:
  Init_UserDisplay_ip()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UserDisplay_battery ip(::turtlebot4_msgs::msg::UserDisplay::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_UserDisplay_battery(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserDisplay msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot4_msgs::msg::UserDisplay>()
{
  return turtlebot4_msgs::msg::builder::Init_UserDisplay_ip();
}

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__BUILDER_HPP_
