// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlebot4_msgs:msg/UserLed.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlebot4_msgs/msg/detail/user_led__rosidl_typesupport_introspection_c.h"
#include "turtlebot4_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlebot4_msgs/msg/detail/user_led__functions.h"
#include "turtlebot4_msgs/msg/detail/user_led__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlebot4_msgs__msg__UserLed__init(message_memory);
}

void turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_fini_function(void * message_memory)
{
  turtlebot4_msgs__msg__UserLed__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_member_array[4] = {
  {
    "led",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserLed, led),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserLed, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blink_period",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserLed, blink_period),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duty_cycle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot4_msgs__msg__UserLed, duty_cycle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_members = {
  "turtlebot4_msgs__msg",  // message namespace
  "UserLed",  // message name
  4,  // number of fields
  sizeof(turtlebot4_msgs__msg__UserLed),
  turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_member_array,  // message members
  turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_type_support_handle = {
  0,
  &turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlebot4_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlebot4_msgs, msg, UserLed)() {
  if (!turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_type_support_handle.typesupport_identifier) {
    turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlebot4_msgs__msg__UserLed__rosidl_typesupport_introspection_c__UserLed_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
