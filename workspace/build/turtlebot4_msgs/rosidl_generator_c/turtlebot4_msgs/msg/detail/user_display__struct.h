// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_H_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ip'
// Member 'battery'
// Member 'entries'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/UserDisplay in the package turtlebot4_msgs.
/**
  * This message represents the header and 5 entries 
  * that are displayed on the Turtlebot4 display
  * selected_entry indicates which menu entry is currently selected
 */
typedef struct turtlebot4_msgs__msg__UserDisplay
{
  rosidl_runtime_c__String ip;
  rosidl_runtime_c__String battery;
  rosidl_runtime_c__String entries[5];
  int32_t selected_entry;
} turtlebot4_msgs__msg__UserDisplay;

// Struct for a sequence of turtlebot4_msgs__msg__UserDisplay.
typedef struct turtlebot4_msgs__msg__UserDisplay__Sequence
{
  turtlebot4_msgs__msg__UserDisplay * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot4_msgs__msg__UserDisplay__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_H_
