// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice
#include "turtlebot4_msgs/msg/detail/user_display__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "turtlebot4_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtlebot4_msgs/msg/detail/user_display__struct.h"
#include "turtlebot4_msgs/msg/detail/user_display__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // battery, entries, ip
#include "rosidl_runtime_c/string_functions.h"  // battery, entries, ip

// forward declare type support functions


using _UserDisplay__ros_msg_type = turtlebot4_msgs__msg__UserDisplay;

static bool _UserDisplay__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _UserDisplay__ros_msg_type * ros_message = static_cast<const _UserDisplay__ros_msg_type *>(untyped_ros_message);
  // Field name: ip
  {
    const rosidl_runtime_c__String * str = &ros_message->ip;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: battery
  {
    const rosidl_runtime_c__String * str = &ros_message->battery;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: entries
  {
    size_t size = 5;
    auto array_ptr = ros_message->entries;
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: selected_entry
  {
    cdr << ros_message->selected_entry;
  }

  return true;
}

static bool _UserDisplay__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _UserDisplay__ros_msg_type * ros_message = static_cast<_UserDisplay__ros_msg_type *>(untyped_ros_message);
  // Field name: ip
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ip.data) {
      rosidl_runtime_c__String__init(&ros_message->ip);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ip,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ip'\n");
      return false;
    }
  }

  // Field name: battery
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->battery.data) {
      rosidl_runtime_c__String__init(&ros_message->battery);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->battery,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'battery'\n");
      return false;
    }
  }

  // Field name: entries
  {
    size_t size = 5;
    auto array_ptr = ros_message->entries;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'entries'\n");
        return false;
      }
    }
  }

  // Field name: selected_entry
  {
    cdr >> ros_message->selected_entry;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot4_msgs
size_t get_serialized_size_turtlebot4_msgs__msg__UserDisplay(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _UserDisplay__ros_msg_type * ros_message = static_cast<const _UserDisplay__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ip.size + 1);
  // field.name battery
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->battery.size + 1);
  // field.name entries
  {
    size_t array_size = 5;
    auto array_ptr = ros_message->entries;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name selected_entry
  {
    size_t item_size = sizeof(ros_message->selected_entry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _UserDisplay__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_turtlebot4_msgs__msg__UserDisplay(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot4_msgs
size_t max_serialized_size_turtlebot4_msgs__msg__UserDisplay(
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

  // member: ip
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
  // member: battery
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
  // member: entries
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
  // member: selected_entry
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _UserDisplay__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_turtlebot4_msgs__msg__UserDisplay(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_UserDisplay = {
  "turtlebot4_msgs::msg",
  "UserDisplay",
  _UserDisplay__cdr_serialize,
  _UserDisplay__cdr_deserialize,
  _UserDisplay__get_serialized_size,
  _UserDisplay__max_serialized_size
};

static rosidl_message_type_support_t _UserDisplay__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_UserDisplay,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtlebot4_msgs, msg, UserDisplay)() {
  return &_UserDisplay__type_support;
}

#if defined(__cplusplus)
}
#endif
