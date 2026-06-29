// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/Timing.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__Timing __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__Timing __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Timing_
{
  using Type = Timing_<ContainerAllocator>;

  explicit Timing_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_order_interval = 0.0f;
      this->min_state_interval = 0.0f;
      this->default_state_interval = 0.0f;
      this->visualization_interval = 0.0f;
    }
  }

  explicit Timing_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_order_interval = 0.0f;
      this->min_state_interval = 0.0f;
      this->default_state_interval = 0.0f;
      this->visualization_interval = 0.0f;
    }
  }

  // field types and members
  using _min_order_interval_type =
    float;
  _min_order_interval_type min_order_interval;
  using _min_state_interval_type =
    float;
  _min_state_interval_type min_state_interval;
  using _default_state_interval_type =
    float;
  _default_state_interval_type default_state_interval;
  using _visualization_interval_type =
    float;
  _visualization_interval_type visualization_interval;

  // setters for named parameter idiom
  Type & set__min_order_interval(
    const float & _arg)
  {
    this->min_order_interval = _arg;
    return *this;
  }
  Type & set__min_state_interval(
    const float & _arg)
  {
    this->min_state_interval = _arg;
    return *this;
  }
  Type & set__default_state_interval(
    const float & _arg)
  {
    this->default_state_interval = _arg;
    return *this;
  }
  Type & set__visualization_interval(
    const float & _arg)
  {
    this->visualization_interval = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::Timing_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::Timing_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Timing_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Timing_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__Timing
    std::shared_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__Timing
    std::shared_ptr<vda5050_msgs::msg::Timing_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Timing_ & other) const
  {
    if (this->min_order_interval != other.min_order_interval) {
      return false;
    }
    if (this->min_state_interval != other.min_state_interval) {
      return false;
    }
    if (this->default_state_interval != other.default_state_interval) {
      return false;
    }
    if (this->visualization_interval != other.visualization_interval) {
      return false;
    }
    return true;
  }
  bool operator!=(const Timing_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Timing_

// alias to use template instance with default allocator
using Timing =
  vda5050_msgs::msg::Timing_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_HPP_
