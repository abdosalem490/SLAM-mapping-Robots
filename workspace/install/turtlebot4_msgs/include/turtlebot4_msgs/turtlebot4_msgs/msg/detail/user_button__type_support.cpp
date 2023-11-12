// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlebot4_msgs/msg/detail/user_button__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace turtlebot4_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void UserButton_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) turtlebot4_msgs::msg::UserButton(_init);
}

void UserButton_fini_function(void * message_memory)
{
  auto typed_message = static_cast<turtlebot4_msgs::msg::UserButton *>(message_memory);
  typed_message->~UserButton();
}

size_t size_function__UserButton__button(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__UserButton__button(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__UserButton__button(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__UserButton__button(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__UserButton__button(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__UserButton__button(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__UserButton__button(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UserButton_message_member_array[1] = {
  {
    "button",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs::msg::UserButton, button),  // bytes offset in struct
    nullptr,  // default value
    size_function__UserButton__button,  // size() function pointer
    get_const_function__UserButton__button,  // get_const(index) function pointer
    get_function__UserButton__button,  // get(index) function pointer
    fetch_function__UserButton__button,  // fetch(index, &value) function pointer
    assign_function__UserButton__button,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UserButton_message_members = {
  "turtlebot4_msgs::msg",  // message namespace
  "UserButton",  // message name
  1,  // number of fields
  sizeof(turtlebot4_msgs::msg::UserButton),
  UserButton_message_member_array,  // message members
  UserButton_init_function,  // function to initialize message memory (memory has to be allocated)
  UserButton_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UserButton_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UserButton_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace turtlebot4_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtlebot4_msgs::msg::UserButton>()
{
  return &::turtlebot4_msgs::msg::rosidl_typesupport_introspection_cpp::UserButton_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtlebot4_msgs, msg, UserButton)() {
  return &::turtlebot4_msgs::msg::rosidl_typesupport_introspection_cpp::UserButton_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
