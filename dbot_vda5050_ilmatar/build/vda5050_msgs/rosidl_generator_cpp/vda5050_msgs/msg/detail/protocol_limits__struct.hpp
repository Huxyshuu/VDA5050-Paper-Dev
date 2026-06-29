// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'max_string_lens'
#include "vda5050_msgs/msg/detail/max_string_lens__struct.hpp"
// Member 'max_array_lens'
#include "vda5050_msgs/msg/detail/max_array_lens__struct.hpp"
// Member 'timing'
#include "vda5050_msgs/msg/detail/timing__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__ProtocolLimits __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__ProtocolLimits __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProtocolLimits_
{
  using Type = ProtocolLimits_<ContainerAllocator>;

  explicit ProtocolLimits_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : max_string_lens(_init),
    max_array_lens(_init),
    timing(_init)
  {
    (void)_init;
  }

  explicit ProtocolLimits_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : max_string_lens(_alloc, _init),
    max_array_lens(_alloc, _init),
    timing(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _max_string_lens_type =
    vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>;
  _max_string_lens_type max_string_lens;
  using _max_array_lens_type =
    vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>;
  _max_array_lens_type max_array_lens;
  using _timing_type =
    vda5050_msgs::msg::Timing_<ContainerAllocator>;
  _timing_type timing;

  // setters for named parameter idiom
  Type & set__max_string_lens(
    const vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> & _arg)
  {
    this->max_string_lens = _arg;
    return *this;
  }
  Type & set__max_array_lens(
    const vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> & _arg)
  {
    this->max_array_lens = _arg;
    return *this;
  }
  Type & set__timing(
    const vda5050_msgs::msg::Timing_<ContainerAllocator> & _arg)
  {
    this->timing = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__ProtocolLimits
    std::shared_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__ProtocolLimits
    std::shared_ptr<vda5050_msgs::msg::ProtocolLimits_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProtocolLimits_ & other) const
  {
    if (this->max_string_lens != other.max_string_lens) {
      return false;
    }
    if (this->max_array_lens != other.max_array_lens) {
      return false;
    }
    if (this->timing != other.timing) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProtocolLimits_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProtocolLimits_

// alias to use template instance with default allocator
using ProtocolLimits =
  vda5050_msgs::msg::ProtocolLimits_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_HPP_
