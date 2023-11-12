// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlebot4_msgs/msg/detail/user_button__rosidl_typesupport_introspection_c.h"
#include "turtlebot4_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlebot4_msgs/msg/detail/user_button__functions.h"
#include "turtlebot4_msgs/msg/detail/user_button__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlebot4_msgs__msg__UserButton__init(message_memory);
}

void turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_fini_function(void * message_memory)
{
  turtlebot4_msgs__msg__UserButton__fini(message_memory);
}

size_t turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__size_function__UserButton__button(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_const_function__UserButton__button(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_function__UserButton__button(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__fetch_function__UserButton__button(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_const_function__UserButton__button(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__assign_function__UserButton__button(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_function__UserButton__button(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_member_array[1] = {
  {
    "button",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserButton, button),  // bytes offset in struct
    NULL,  // default value
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__size_function__UserButton__button,  // size() function pointer
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_const_function__UserButton__button,  // get_const(index) function pointer
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__get_function__UserButton__button,  // get(index) function pointer
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__fetch_function__UserButton__button,  // fetch(index, &value) function pointer
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__assign_function__UserButton__button,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_members = {
  "turtlebot4_msgs__msg",  // message namespace
  "UserButton",  // message name
  1,  // number of fields
  sizeof(turtlebot4_msgs__msg__UserButton),
  turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_member_array,  // message members
  turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_type_support_handle = {
  0,
  &turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlebot4_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlebot4_msgs, msg, UserButton)() {
  if (!turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_type_support_handle.typesupport_identifier) {
    turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlebot4_msgs__msg__UserButton__rosidl_typesupport_introspection_c__UserButton_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
