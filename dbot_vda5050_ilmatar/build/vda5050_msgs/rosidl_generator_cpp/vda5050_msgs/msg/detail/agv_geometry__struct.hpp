// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'wheel_definitions'
#include "vda5050_msgs/msg/detail/wheel_definition__struct.hpp"
// Member 'envelopes2d'
#include "vda5050_msgs/msg/detail/envelope2_d__struct.hpp"
// Member 'envelopes3d'
#include "vda5050_msgs/msg/detail/envelope3_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__AGVGeometry __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__AGVGeometry __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AGVGeometry_
{
  using Type = AGVGeometry_<ContainerAllocator>;

  explicit AGVGeometry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit AGVGeometry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _wheel_definitions_type =
    std::vector<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>>;
  _wheel_definitions_type wheel_definitions;
  using _envelopes2d_type =
    std::vector<vda5050_msgs::msg::Envelope2D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Envelope2D_<ContainerAllocator>>>;
  _envelopes2d_type envelopes2d;
  using _envelopes3d_type =
    std::vector<vda5050_msgs::msg::Envelope3D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Envelope3D_<ContainerAllocator>>>;
  _envelopes3d_type envelopes3d;

  // setters for named parameter idiom
  Type & set__wheel_definitions(
    const std::vector<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>> & _arg)
  {
    this->wheel_definitions = _arg;
    return *this;
  }
  Type & set__envelopes2d(
    const std::vector<vda5050_msgs::msg::Envelope2D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Envelope2D_<ContainerAllocator>>> & _arg)
  {
    this->envelopes2d = _arg;
    return *this;
  }
  Type & set__envelopes3d(
    const std::vector<vda5050_msgs::msg::Envelope3D_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Envelope3D_<ContainerAllocator>>> & _arg)
  {
    this->envelopes3d = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__AGVGeometry
    std::shared_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__AGVGeometry
    std::shared_ptr<vda5050_msgs::msg::AGVGeometry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AGVGeometry_ & other) const
  {
    if (this->wheel_definitions != other.wheel_definitions) {
      return false;
    }
    if (this->envelopes2d != other.envelopes2d) {
      return false;
    }
    if (this->envelopes3d != other.envelopes3d) {
      return false;
    }
    return true;
  }
  bool operator!=(const AGVGeometry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AGVGeometry_

// alias to use template instance with default allocator
using AGVGeometry =
  vda5050_msgs::msg::AGVGeometry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_HPP_
