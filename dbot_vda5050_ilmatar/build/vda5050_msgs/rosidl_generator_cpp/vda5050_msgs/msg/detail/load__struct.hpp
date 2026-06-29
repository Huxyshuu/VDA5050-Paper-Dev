// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bounding_box_reference'
#include "vda5050_msgs/msg/detail/bounding_box_reference__struct.hpp"
// Member 'load_dimensions'
#include "vda5050_msgs/msg/detail/load_dimensions__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__Load __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__Load __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Load_
{
  using Type = Load_<ContainerAllocator>;

  explicit Load_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bounding_box_reference(_init),
    load_dimensions(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->load_id = "";
      this->load_type = "";
      this->load_position = "";
      this->weight = 0.0;
    }
  }

  explicit Load_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : load_id(_alloc),
    load_type(_alloc),
    load_position(_alloc),
    bounding_box_reference(_alloc, _init),
    load_dimensions(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->load_id = "";
      this->load_type = "";
      this->load_position = "";
      this->weight = 0.0;
    }
  }

  // field types and members
  using _load_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _load_id_type load_id;
  using _load_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _load_type_type load_type;
  using _load_position_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _load_position_type load_position;
  using _bounding_box_reference_type =
    vda5050_msgs::msg::BoundingBoxReference_<ContainerAllocator>;
  _bounding_box_reference_type bounding_box_reference;
  using _load_dimensions_type =
    vda5050_msgs::msg::LoadDimensions_<ContainerAllocator>;
  _load_dimensions_type load_dimensions;
  using _weight_type =
    double;
  _weight_type weight;

  // setters for named parameter idiom
  Type & set__load_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->load_id = _arg;
    return *this;
  }
  Type & set__load_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->load_type = _arg;
    return *this;
  }
  Type & set__load_position(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->load_position = _arg;
    return *this;
  }
  Type & set__bounding_box_reference(
    const vda5050_msgs::msg::BoundingBoxReference_<ContainerAllocator> & _arg)
  {
    this->bounding_box_reference = _arg;
    return *this;
  }
  Type & set__load_dimensions(
    const vda5050_msgs::msg::LoadDimensions_<ContainerAllocator> & _arg)
  {
    this->load_dimensions = _arg;
    return *this;
  }
  Type & set__weight(
    const double & _arg)
  {
    this->weight = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::Load_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::Load_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Load_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Load_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Load_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Load_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Load_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Load_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Load_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Load_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__Load
    std::shared_ptr<vda5050_msgs::msg::Load_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__Load
    std::shared_ptr<vda5050_msgs::msg::Load_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Load_ & other) const
  {
    if (this->load_id != other.load_id) {
      return false;
    }
    if (this->load_type != other.load_type) {
      return false;
    }
    if (this->load_position != other.load_position) {
      return false;
    }
    if (this->bounding_box_reference != other.bounding_box_reference) {
      return false;
    }
    if (this->load_dimensions != other.load_dimensions) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    return true;
  }
  bool operator!=(const Load_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Load_

// alias to use template instance with default allocator
using Load =
  vda5050_msgs::msg::Load_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD__STRUCT_HPP_
