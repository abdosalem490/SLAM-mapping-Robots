// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_HPP_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtlebot4_msgs__msg__UserDisplay __attribute__((deprecated))
#else
# define DEPRECATED__turtlebot4_msgs__msg__UserDisplay __declspec(deprecated)
#endif

namespace turtlebot4_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserDisplay_
{
  using Type = UserDisplay_<ContainerAllocator>;

  explicit UserDisplay_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ip = "";
      this->battery = "";
      std::fill<typename std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5>::iterator, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>(this->entries.begin(), this->entries.end(), "");
      this->selected_entry = 0l;
    }
  }

  explicit UserDisplay_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ip(_alloc),
    battery(_alloc),
    entries(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ip = "";
      this->battery = "";
      std::fill<typename std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5>::iterator, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>(this->entries.begin(), this->entries.end(), "");
      this->selected_entry = 0l;
    }
  }

  // field types and members
  using _ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_type ip;
  using _battery_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _battery_type battery;
  using _entries_type =
    std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5>;
  _entries_type entries;
  using _selected_entry_type =
    int32_t;
  _selected_entry_type selected_entry;

  // setters for named parameter idiom
  Type & set__ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip = _arg;
    return *this;
  }
  Type & set__battery(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->battery = _arg;
    return *this;
  }
  Type & set__entries(
    const std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5> & _arg)
  {
    this->entries = _arg;
    return *this;
  }
  Type & set__selected_entry(
    const int32_t & _arg)
  {
    this->selected_entry = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlebot4_msgs__msg__UserDisplay
    std::shared_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlebot4_msgs__msg__UserDisplay
    std::shared_ptr<turtlebot4_msgs::msg::UserDisplay_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserDisplay_ & other) const
  {
    if (this->ip != other.ip) {
      return false;
    }
    if (this->battery != other.battery) {
      return false;
    }
    if (this->entries != other.entries) {
      return false;
    }
    if (this->selected_entry != other.selected_entry) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserDisplay_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserDisplay_

// alias to use template instance with default allocator
using UserDisplay =
  turtlebot4_msgs::msg::UserDisplay_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtlebot4_msgs

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__STRUCT_HPP_
