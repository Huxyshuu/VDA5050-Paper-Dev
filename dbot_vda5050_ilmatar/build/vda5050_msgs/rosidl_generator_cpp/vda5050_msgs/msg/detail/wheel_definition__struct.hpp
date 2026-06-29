// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "vda5050_msgs/msg/detail/position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__WheelDefinition __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__WheelDefinition __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WheelDefinition_
{
  using Type = WheelDefinition_<ContainerAllocator>;

  explicit WheelDefinition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->is_active_driven = false;
      this->is_active_steered = false;
      this->diameter = 0.0;
      this->width = 0.0;
      this->center_displacement = 0.0;
      this->constraints = "";
    }
  }

  explicit WheelDefinition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    position(_alloc, _init),
    constraints(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->is_active_driven = false;
      this->is_active_steered = false;
      this->diameter = 0.0;
      this->width = 0.0;
      this->center_displacement = 0.0;
      this->constraints = "";
    }
  }

  // field types and members
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _is_active_driven_type =
    bool;
  _is_active_driven_type is_active_driven;
  using _is_active_steered_type =
    bool;
  _is_active_steered_type is_active_steered;
  using _position_type =
    vda5050_msgs::msg::Position_<ContainerAllocator>;
  _position_type position;
  using _diameter_type =
    double;
  _diameter_type diameter;
  using _width_type =
    double;
  _width_type width;
  using _center_displacement_type =
    double;
  _center_displacement_type center_displacement;
  using _constraints_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _constraints_type constraints;

  // setters for named parameter idiom
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__is_active_driven(
    const bool & _arg)
  {
    this->is_active_driven = _arg;
    return *this;
  }
  Type & set__is_active_steered(
    const bool & _arg)
  {
    this->is_active_steered = _arg;
    return *this;
  }
  Type & set__position(
    const vda5050_msgs::msg::Position_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__diameter(
    const double & _arg)
  {
    this->diameter = _arg;
    return *this;
  }
  Type & set__width(
    const double & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__center_displacement(
    const double & _arg)
  {
    this->center_displacement = _arg;
    return *this;
  }
  Type & set__constraints(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->constraints = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DRIVE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> CASTER;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FIXED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MECANUM;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__WheelDefinition
    std::shared_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__WheelDefinition
    std::shared_ptr<vda5050_msgs::msg::WheelDefinition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WheelDefinition_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->is_active_driven != other.is_active_driven) {
      return false;
    }
    if (this->is_active_steered != other.is_active_steered) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->diameter != other.diameter) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->center_displacement != other.center_displacement) {
      return false;
    }
    if (this->constraints != other.constraints) {
      return false;
    }
    return true;
  }
  bool operator!=(const WheelDefinition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WheelDefinition_

// alias to use template instance with default allocator
using WheelDefinition =
  vda5050_msgs::msg::WheelDefinition_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
WheelDefinition_<ContainerAllocator>::DRIVE = "DRIVE";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
WheelDefinition_<ContainerAllocator>::CASTER = "CASTER";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
WheelDefinition_<ContainerAllocator>::FIXED = "FIXED";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
WheelDefinition_<ContainerAllocator>::MECANUM = "MECANUM";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__STRUCT_HPP_
