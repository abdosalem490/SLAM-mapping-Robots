// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot4_msgs:msg/UserLed.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_H_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'USER_LED_1'.
/**
  * Available LEDs
 */
enum
{
  turtlebot4_msgs__msg__UserLed__USER_LED_1 = 0
};

/// Constant 'USER_LED_2'.
enum
{
  turtlebot4_msgs__msg__UserLed__USER_LED_2 = 1
};

/// Constant 'COLOR_OFF'.
/**
  * Available colors
 */
enum
{
  turtlebot4_msgs__msg__UserLed__COLOR_OFF = 0
};

/// Constant 'COLOR_GREEN'.
enum
{
  turtlebot4_msgs__msg__UserLed__COLOR_GREEN = 1
};

/// Constant 'COLOR_RED'.
enum
{
  turtlebot4_msgs__msg__UserLed__COLOR_RED = 2
};

/// Constant 'COLOR_YELLOW'.
enum
{
  turtlebot4_msgs__msg__UserLed__COLOR_YELLOW = 3
};

/// Struct defined in msg/UserLed in the package turtlebot4_msgs.
/**
  * This message sets the state of the user LEDs
  * Blink period is the time in milliseconds during which the ON/OFF cycle occurs
  * The duty cycle represents the percentage of the blink period that the LED is ON
  * A duty cycle of 1.0 would set the LED to always be ON, whereas a duty cycle of 0.0 is always OFF
  * A blink period of 1000ms with a duty cycle of 0.6 will have the LED turn ON for 600ms, 
  * then OFF for 400ms
 */
typedef struct turtlebot4_msgs__msg__UserLed
{
  /// Which available LED to use
  uint8_t led;
  /// Which color to set the LED to
  uint8_t color;
  /// Blink period in ms
  uint32_t blink_period;
  /// Duty cycle (0.0 to 1.0)
  double duty_cycle;
} turtlebot4_msgs__msg__UserLed;

// Struct for a sequence of turtlebot4_msgs__msg__UserLed.
typedef struct turtlebot4_msgs__msg__UserLed__Sequence
{
  turtlebot4_msgs__msg__UserLed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot4_msgs__msg__UserLed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_H_
