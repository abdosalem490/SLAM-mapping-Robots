// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_H_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/UserButton in the package turtlebot4_msgs.
/**
  * This message relays the state of the user buttons
  * Each button is represented with a boolean, were True indicates the button is pressed
 */
typedef struct turtlebot4_msgs__msg__UserButton
{
  bool button[4];
} turtlebot4_msgs__msg__UserButton;

// Struct for a sequence of turtlebot4_msgs__msg__UserButton.
typedef struct turtlebot4_msgs__msg__UserButton__Sequence
{
  turtlebot4_msgs__msg__UserButton * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot4_msgs__msg__UserButton__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_H_
