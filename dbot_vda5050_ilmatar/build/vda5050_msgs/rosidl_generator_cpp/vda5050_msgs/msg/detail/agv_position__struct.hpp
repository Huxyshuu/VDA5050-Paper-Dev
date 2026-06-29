// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/AGVPosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__AGVPosition __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__AGVPosition __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AGVPosition_
{
  using Type = AGVPosition_<ContainerAllocator>;

  explicit AGVPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position_initialized = false;
      this->localization_score = 0.0;
      this->deviation_range = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->map_id = "";
      this->map_description = "";
    }
  }

  explicit AGVPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : map_id(_alloc),
    map_description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position_initialized = false;
      this->localization_score = 0.0;
      this->deviation_range = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->map_id = "";
      this->map_description = "";
    }
  }

  // field types and members
  using _position_initialized_type =
    bool;
  _position_initialized_type position_initialized;
  using _localization_score_type =
    double;
  _localization_score_type localization_score;
  using _deviation_range_type =
    double;
  _deviation_range_type deviation_range;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;
  using _map_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _map_id_type map_id;
  using _map_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _map_description_type map_description;

  // setters for named parameter idiom
  Type & set__position_initialized(
    const bool & _arg)
  {
    this->position_initialized = _arg;
    return *this;
  }
  Type & set__localization_score(
    const double & _arg)
  {
    this->localization_score = _arg;
    return *this;
  }
  Type & set__deviation_range(
    const double & _arg)
  {
    this->deviation_range = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__map_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->map_id = _arg;
    return *this;
  }
  Type & set__map_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->map_description = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::AGVPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::AGVPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__AGVPosition
    std::shared_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__AGVPosition
    std::shared_ptr<vda5050_msgs::msg::AGVPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AGVPosition_ & other) const
  {
    if (this->position_initialized != other.position_initialized) {
      return false;
    }
    if (this->localization_score != other.localization_score) {
      return false;
    }
    if (this->deviation_range != other.deviation_range) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->map_id != other.map_id) {
      return false;
    }
    if (this->map_description != other.map_description) {
      return false;
    }
    return true;
  }
  bool operator!=(const AGVPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AGVPosition_

// alias to use template instance with default allocator
using AGVPosition =
  vda5050_msgs::msg::AGVPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_HPP_
