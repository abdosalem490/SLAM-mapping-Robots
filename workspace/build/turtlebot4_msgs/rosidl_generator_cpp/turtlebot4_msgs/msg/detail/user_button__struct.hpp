// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlebot4_msgs:msg/UserButton.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtlebot4_msgs__msg__UserButton __attribute__((deprecated))
#else
# define DEPRECATED__turtlebot4_msgs__msg__UserButton __declspec(deprecated)
#endif

namespace turtlebot4_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserButton_
{
  using Type = UserButton_<ContainerAllocator>;

  explicit UserButton_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->button.begin(), this->button.end(), false);
    }
  }

  explicit UserButton_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : button(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->button.begin(), this->button.end(), false);
    }
  }

  // field types and members
  using _button_type =
    std::array<bool, 4>;
  _button_type button;

  // setters for named parameter idiom
  Type & set__button(
    const std::array<bool, 4> & _arg)
  {
    this->button = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtlebot4_msgs::msg::UserButton_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlebot4_msgs::msg::UserButton_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserButton_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserButton_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlebot4_msgs__msg__UserButton
    std::shared_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlebot4_msgs__msg__UserButton
    std::shared_ptr<turtlebot4_msgs::msg::UserButton_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserButton_ & other) const
  {
    if (this->button != other.button) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserButton_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserButton_

// alias to use template instance with default allocator
using UserButton =
  turtlebot4_msgs::msg::UserButton_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_BUTTON__STRUCT_HPP_
