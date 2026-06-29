// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__PhysicalParameters __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__PhysicalParameters __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PhysicalParameters_
{
  using Type = PhysicalParameters_<ContainerAllocator>;

  explicit PhysicalParameters_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_min = 0.0;
      this->speed_max = 0.0;
      this->acceleration_max = 0.0;
      this->deceleration_max = 0.0;
      this->height_min = 0.0;
      this->height_max = 0.0;
      this->width = 0.0;
      this->length = 0.0;
    }
  }

  explicit PhysicalParameters_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_min = 0.0;
      this->speed_max = 0.0;
      this->acceleration_max = 0.0;
      this->deceleration_max = 0.0;
      this->height_min = 0.0;
      this->height_max = 0.0;
      this->width = 0.0;
      this->length = 0.0;
    }
  }

  // field types and members
  using _speed_min_type =
    double;
  _speed_min_type speed_min;
  using _speed_max_type =
    double;
  _speed_max_type speed_max;
  using _acceleration_max_type =
    double;
  _acceleration_max_type acceleration_max;
  using _deceleration_max_type =
    double;
  _deceleration_max_type deceleration_max;
  using _height_min_type =
    double;
  _height_min_type height_min;
  using _height_max_type =
    double;
  _height_max_type height_max;
  using _width_type =
    double;
  _width_type width;
  using _length_type =
    double;
  _length_type length;

  // setters for named parameter idiom
  Type & set__speed_min(
    const double & _arg)
  {
    this->speed_min = _arg;
    return *this;
  }
  Type & set__speed_max(
    const double & _arg)
  {
    this->speed_max = _arg;
    return *this;
  }
  Type & set__acceleration_max(
    const double & _arg)
  {
    this->acceleration_max = _arg;
    return *this;
  }
  Type & set__deceleration_max(
    const double & _arg)
  {
    this->deceleration_max = _arg;
    return *this;
  }
  Type & set__height_min(
    const double & _arg)
  {
    this->height_min = _arg;
    return *this;
  }
  Type & set__height_max(
    const double & _arg)
  {
    this->height_max = _arg;
    return *this;
  }
  Type & set__width(
    const double & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__length(
    const double & _arg)
  {
    this->length = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__PhysicalParameters
    std::shared_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__PhysicalParameters
    std::shared_ptr<vda5050_msgs::msg::PhysicalParameters_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PhysicalParameters_ & other) const
  {
    if (this->speed_min != other.speed_min) {
      return false;
    }
    if (this->speed_max != other.speed_max) {
      return false;
    }
    if (this->acceleration_max != other.acceleration_max) {
      return false;
    }
    if (this->deceleration_max != other.deceleration_max) {
      return false;
    }
    if (this->height_min != other.height_min) {
      return false;
    }
    if (this->height_max != other.height_max) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    return true;
  }
  bool operator!=(const PhysicalParameters_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PhysicalParameters_

// alias to use template instance with default allocator
using PhysicalParameters =
  vda5050_msgs::msg::PhysicalParameters_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_HPP_
