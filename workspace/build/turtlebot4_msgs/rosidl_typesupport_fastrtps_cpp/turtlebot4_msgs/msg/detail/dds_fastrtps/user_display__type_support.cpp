// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice
#include "turtlebot4_msgs/msg/detail/user_display__rosidl_typesupport_fastrtps_cpp.hpp"
#include "turtlebot4_msgs/msg/detail/user_display__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace turtlebot4_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_msgs
cdr_serialize(
  const turtlebot4_msgs::msg::UserDisplay & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ip
  cdr << ros_message.ip;
  // Member: battery
  cdr << ros_message.battery;
  // Member: entries
  {
    cdr << ros_message.entries;
  }
  // Member: selected_entry
  cdr << ros_message.selected_entry;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtlebot4_msgs::msg::UserDisplay & ros_message)
{
  // Member: ip
  cdr >> ros_message.ip;

  // Member: battery
  cdr >> ros_message.battery;

  // Member: entries
  {
    cdr >> ros_message.entries;
  }

  // Member: selected_entry
  cdr >> ros_message.selected_entry;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_msgs
get_serialized_size(
  const turtlebot4_msgs::msg::UserDisplay & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.ip.size() + 1);
  // Member: battery
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.battery.size() + 1);
  // Member: entries
  {
    size_t array_size = 5;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.entries[index].size() + 1);
    }
  }
  // Member: selected_entry
  {
    size_t item_size = sizeof(ros_message.selected_entry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlebot4_msgs
max_serialized_size_UserDisplay(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: ip
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: battery
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: entries
  {
    size_t array_size = 5;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: selected_entry
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _UserDisplay__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const turtlebot4_msgs::msg::UserDisplay *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UserDisplay__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<turtlebot4_msgs::msg::UserDisplay *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UserDisplay__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const turtlebot4_msgs::msg::UserDisplay *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UserDisplay__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UserDisplay(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UserDisplay__callbacks = {
  "turtlebot4_msgs::msg",
  "UserDisplay",
  _UserDisplay__cdr_serialize,
  _UserDisplay__cdr_deserialize,
  _UserDisplay__get_serialized_size,
  _UserDisplay__max_serialized_size
};

static rosidl_message_type_support_t _UserDisplay__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UserDisplay__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtlebot4_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_turtlebot4_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<turtlebot4_msgs::msg::UserDisplay>()
{
  return &turtlebot4_msgs::msg::typesupport_fastrtps_cpp::_UserDisplay__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtlebot4_msgs, msg, UserDisplay)() {
  return &turtlebot4_msgs::msg::typesupport_fastrtps_cpp::_UserDisplay__handle;
}

#ifdef __cplusplus
}
#endif
