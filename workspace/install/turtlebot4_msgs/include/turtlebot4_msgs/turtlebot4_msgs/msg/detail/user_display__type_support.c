// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlebot4_msgs/msg/detail/user_display__rosidl_typesupport_introspection_c.h"
#include "turtlebot4_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlebot4_msgs/msg/detail/user_display__functions.h"
#include "turtlebot4_msgs/msg/detail/user_display__struct.h"


// Include directives for member types
// Member `ip`
// Member `battery`
// Member `entries`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlebot4_msgs__msg__UserDisplay__init(message_memory);
}

void turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_fini_function(void * message_memory)
{
  turtlebot4_msgs__msg__UserDisplay__fini(message_memory);
}

size_t turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__size_function__UserDisplay__entries(
  const void * untyped_member)
{
  (void)untyped_member;
  return 5;
}

const void * turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_const_function__UserDisplay__entries(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String * member =
    (const rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void * turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_function__UserDisplay__entries(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String * member =
    (rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__fetch_function__UserDisplay__entries(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_const_function__UserDisplay__entries(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__assign_function__UserDisplay__entries(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_function__UserDisplay__entries(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_member_array[4] = {
  {
    "ip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserDisplay, ip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "battery",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserDisplay, battery),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "entries",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    5,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserDisplay, entries),  // bytes offset in struct
    NULL,  // default value
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__size_function__UserDisplay__entries,  // size() function pointer
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_const_function__UserDisplay__entries,  // get_const(index) function pointer
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__get_function__UserDisplay__entries,  // get(index) function pointer
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__fetch_function__UserDisplay__entries,  // fetch(index, &value) function pointer
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__assign_function__UserDisplay__entries,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "selected_entry",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserDisplay, selected_entry),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_members = {
  "turtlebot4_msgs__msg",  // message namespace
  "UserDisplay",  // message name
  4,  // number of fields
  sizeof(turtlebot4_msgs__msg__UserDisplay),
  turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_member_array,  // message members
  turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_type_support_handle = {
  0,
  &turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlebot4_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlebot4_msgs, msg, UserDisplay)() {
  if (!turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_type_support_handle.typesupport_identifier) {
    turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlebot4_msgs__msg__UserDisplay__rosidl_typesupport_introspection_c__UserDisplay_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
