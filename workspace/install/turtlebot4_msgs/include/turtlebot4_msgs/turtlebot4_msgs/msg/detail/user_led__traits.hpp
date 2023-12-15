// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlebot4_msgs:msg/UserLed.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__TRAITS_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlebot4_msgs/msg/detail/user_led__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlebot4_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UserLed & msg,
  std::ostream & out)
{
  out << "{";
  // member: led
  {
    out << "led: ";
    rosidl_generator_traits::value_to_yaml(msg.led, out);
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: blink_period
  {
    out << "blink_period: ";
    rosidl_generator_traits::value_to_yaml(msg.blink_period, out);
    out << ", ";
  }

  // member: duty_cycle
  {
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UserLed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: led
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led: ";
    rosidl_generator_traits::value_to_yaml(msg.led, out);
    out << "\n";
  }

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: blink_period
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blink_period: ";
    rosidl_generator_traits::value_to_yaml(msg.blink_period, out);
    out << "\n";
  }

  // member: duty_cycle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UserLed & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtlebot4_msgs

namespace rosidl_generator_traits
{

[[deprecated("use turtlebot4_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlebot4_msgs::msg::UserLed & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlebot4_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlebot4_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtlebot4_msgs::msg::UserLed & msg)
{
  return turtlebot4_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtlebot4_msgs::msg::UserLed>()
{
  return "turtlebot4_msgs::msg::UserLed";
}

template<>
inline const char * name<turtlebot4_msgs::msg::UserLed>()
{
  return "turtlebot4_msgs/msg/UserLed";
}

template<>
struct has_fixed_size<turtlebot4_msgs::msg::UserLed>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlebot4_msgs::msg::UserLed>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlebot4_msgs::msg::UserLed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__TRAITS_HPP_
