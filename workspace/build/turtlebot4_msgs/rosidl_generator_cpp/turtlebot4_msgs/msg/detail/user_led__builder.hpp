// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot4_msgs:msg/UserLed.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__BUILDER_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlebot4_msgs/msg/detail/user_led__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlebot4_msgs
{

namespace msg
{

namespace builder
{

class Init_UserLed_duty_cycle
{
public:
  explicit Init_UserLed_duty_cycle(::turtlebot4_msgs::msg::UserLed & msg)
  : msg_(msg)
  {}
  ::turtlebot4_msgs::msg::UserLed duty_cycle(::turtlebot4_msgs::msg::UserLed::_duty_cycle_type arg)
  {
    msg_.duty_cycle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserLed msg_;
};

class Init_UserLed_blink_period
{
public:
  explicit Init_UserLed_blink_period(::turtlebot4_msgs::msg::UserLed & msg)
  : msg_(msg)
  {}
  Init_UserLed_duty_cycle blink_period(::turtlebot4_msgs::msg::UserLed::_blink_period_type arg)
  {
    msg_.blink_period = std::move(arg);
    return Init_UserLed_duty_cycle(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserLed msg_;
};

class Init_UserLed_color
{
public:
  explicit Init_UserLed_color(::turtlebot4_msgs::msg::UserLed & msg)
  : msg_(msg)
  {}
  Init_UserLed_blink_period color(::turtlebot4_msgs::msg::UserLed::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_UserLed_blink_period(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserLed msg_;
};

class Init_UserLed_led
{
public:
  Init_UserLed_led()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UserLed_color led(::turtlebot4_msgs::msg::UserLed::_led_type arg)
  {
    msg_.led = std::move(arg);
    return Init_UserLed_color(msg_);
  }

private:
  ::turtlebot4_msgs::msg::UserLed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot4_msgs::msg::UserLed>()
{
  return turtlebot4_msgs::msg::builder::Init_UserLed_led();
}

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__BUILDER_HPP_
