// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__BUILDER_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlebot4_msgs/msg/detail/user_button__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlebot4_msgs
{

namespace msg
{

namespace builder
{

class Init_UserButton_button
{
public:
  Init_UserButton_button()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlebot4_msgs::msg::UserButton button(::turtlebot4_msgs::msg::UserButton::_button_type arg)
  {
    msg_.button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserButton msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot4_msgs::msg::UserButton>()
{
  return turtlebot4_msgs::msg::builder::Init_UserButton_button();
}

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__BUILDER_HPP_
