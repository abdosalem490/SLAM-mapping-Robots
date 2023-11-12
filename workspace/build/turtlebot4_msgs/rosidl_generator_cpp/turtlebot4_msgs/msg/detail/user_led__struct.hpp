// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlebot4_msgs:msg/UserLed.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtlebot4_msgs__msg__UserLed __attribute__((deprecated))
#else
# define DEPRECATED__turtlebot4_msgs__msg__UserLed __declspec(deprecated)
#endif

namespace turtlebot4_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserLed_
{
  using Type = UserLed_<ContainerAllocator>;

  explicit UserLed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led = 0;
      this->color = 0;
      this->blink_period = 0ul;
      this->duty_cycle = 0.0;
    }
  }

  explicit UserLed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led = 0;
      this->color = 0;
      this->blink_period = 0ul;
      this->duty_cycle = 0.0;
    }
  }

  // field types and members
  using _led_type =
    uint8_t;
  _led_type led;
  using _color_type =
    uint8_t;
  _color_type color;
  using _blink_period_type =
    uint32_t;
  _blink_period_type blink_period;
  using _duty_cycle_type =
    double;
  _duty_cycle_type duty_cycle;

  // setters for named parameter idiom
  Type & set__led(
    const uint8_t & _arg)
  {
    this->led = _arg;
    return *this;
  }
  Type & set__color(
    const uint8_t & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__blink_period(
    const uint32_t & _arg)
  {
    this->blink_period = _arg;
    return *this;
  }
  Type & set__duty_cycle(
    const double & _arg)
  {
    this->duty_cycle = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t USER_LED_1 =
    0u;
  static constexpr uint8_t USER_LED_2 =
    1u;
  static constexpr uint8_t COLOR_OFF =
    0u;
  static constexpr uint8_t COLOR_GREEN =
    1u;
  static constexpr uint8_t COLOR_RED =
    2u;
  static constexpr uint8_t COLOR_YELLOW =
    3u;

  // pointer types
  using RawPtr =
    turtlebot4_msgs::msg::UserLed_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlebot4_msgs::msg::UserLed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserLed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserLed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlebot4_msgs__msg__UserLed
    std::shared_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlebot4_msgs__msg__UserLed
    std::shared_ptr<turtlebot4_msgs::msg::UserLed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserLed_ & other) const
  {
    if (this->led != other.led) {
      return false;
    }
    if (this->color != other.color) {
      return false;
    }
    if (this->blink_period != other.blink_period) {
      return false;
    }
    if (this->duty_cycle != other.duty_cycle) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserLed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserLed_

// alias to use template instance with default allocator
using UserLed =
  turtlebot4_msgs::msg::UserLed_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::USER_LED_1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::USER_LED_2;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::COLOR_OFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::COLOR_GREEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::COLOR_RED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserLed_<ContainerAllocator>::COLOR_YELLOW;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_LED__STRUCT_HPP_
