// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__TRAITS_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlebot4_msgs/msg/detail/user_button__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlebot4_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UserButton & msg,
  std::ostream & out)
{
  out << "{";
  // member: button
  {
    if (msg.button.size() == 0) {
      out << "button: []";
    } else {
      out << "button: [";
      size_t pending_items = msg.button.size();
      for (auto item : msg.button) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UserButton & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.button.size() == 0) {
      out << "button: []\n";
    } else {
      out << "button:\n";
      for (auto item : msg.button) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UserButton & msg, bool use_flow_style = false)
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
  const turtlebot4_msgs::msg::UserButton & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlebot4_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlebot4_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtlebot4_msgs::msg::UserButton & msg)
{
  return turtlebot4_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtlebot4_msgs::msg::UserButton>()
{
  return "turtlebot4_msgs::msg::UserButton";
}

template<>
inline const char * name<turtlebot4_msgs::msg::UserButton>()
{
  return "turtlebot4_msgs/msg/UserButton";
}

template<>
struct has_fixed_size<turtlebot4_msgs::msg::UserButton>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlebot4_msgs::msg::UserButton>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlebot4_msgs::msg::UserButton>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__TRAITS_HPP_
