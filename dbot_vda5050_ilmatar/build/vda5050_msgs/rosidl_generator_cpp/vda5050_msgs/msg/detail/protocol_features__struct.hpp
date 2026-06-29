// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'optional_parameters'
#include "vda5050_msgs/msg/detail/optional_parameter__struct.hpp"
// Member 'agv_actions'
#include "vda5050_msgs/msg/detail/agv_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__ProtocolFeatures __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__ProtocolFeatures __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProtocolFeatures_
{
  using Type = ProtocolFeatures_<ContainerAllocator>;

  explicit ProtocolFeatures_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ProtocolFeatures_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _optional_parameters_type =
    std::vector<vda5050_msgs::msg::OptionalParameter_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::OptionalParameter_<ContainerAllocator>>>;
  _optional_parameters_type optional_parameters;
  using _agv_actions_type =
    std::vector<vda5050_msgs::msg::AGVAction_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::AGVAction_<ContainerAllocator>>>;
  _agv_actions_type agv_actions;

  // setters for named parameter idiom
  Type & set__optional_parameters(
    const std::vector<vda5050_msgs::msg::OptionalParameter_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::OptionalParameter_<ContainerAllocator>>> & _arg)
  {
    this->optional_parameters = _arg;
    return *this;
  }
  Type & set__agv_actions(
    const std::vector<vda5050_msgs::msg::AGVAction_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::AGVAction_<ContainerAllocator>>> & _arg)
  {
    this->agv_actions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__ProtocolFeatures
    std::shared_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__ProtocolFeatures
    std::shared_ptr<vda5050_msgs::msg::ProtocolFeatures_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProtocolFeatures_ & other) const
  {
    if (this->optional_parameters != other.optional_parameters) {
      return false;
    }
    if (this->agv_actions != other.agv_actions) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProtocolFeatures_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProtocolFeatures_

// alias to use template instance with default allocator
using ProtocolFeatures =
  vda5050_msgs::msg::ProtocolFeatures_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__STRUCT_HPP_
