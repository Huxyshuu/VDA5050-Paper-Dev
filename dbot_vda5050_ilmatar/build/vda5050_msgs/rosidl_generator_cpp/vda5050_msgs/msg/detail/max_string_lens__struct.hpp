// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__MaxStringLens __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__MaxStringLens __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MaxStringLens_
{
  using Type = MaxStringLens_<ContainerAllocator>;

  explicit MaxStringLens_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_len = 0ul;
      this->topic_serial_len = 0ul;
      this->topic_elem_len = 0ul;
      this->id_len = 0ul;
      this->id_numerical_only = false;
      this->enum_len = 0ul;
      this->load_id_len = 0ul;
    }
  }

  explicit MaxStringLens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_len = 0ul;
      this->topic_serial_len = 0ul;
      this->topic_elem_len = 0ul;
      this->id_len = 0ul;
      this->id_numerical_only = false;
      this->enum_len = 0ul;
      this->load_id_len = 0ul;
    }
  }

  // field types and members
  using _msg_len_type =
    uint32_t;
  _msg_len_type msg_len;
  using _topic_serial_len_type =
    uint32_t;
  _topic_serial_len_type topic_serial_len;
  using _topic_elem_len_type =
    uint32_t;
  _topic_elem_len_type topic_elem_len;
  using _id_len_type =
    uint32_t;
  _id_len_type id_len;
  using _id_numerical_only_type =
    bool;
  _id_numerical_only_type id_numerical_only;
  using _enum_len_type =
    uint32_t;
  _enum_len_type enum_len;
  using _load_id_len_type =
    uint32_t;
  _load_id_len_type load_id_len;

  // setters for named parameter idiom
  Type & set__msg_len(
    const uint32_t & _arg)
  {
    this->msg_len = _arg;
    return *this;
  }
  Type & set__topic_serial_len(
    const uint32_t & _arg)
  {
    this->topic_serial_len = _arg;
    return *this;
  }
  Type & set__topic_elem_len(
    const uint32_t & _arg)
  {
    this->topic_elem_len = _arg;
    return *this;
  }
  Type & set__id_len(
    const uint32_t & _arg)
  {
    this->id_len = _arg;
    return *this;
  }
  Type & set__id_numerical_only(
    const bool & _arg)
  {
    this->id_numerical_only = _arg;
    return *this;
  }
  Type & set__enum_len(
    const uint32_t & _arg)
  {
    this->enum_len = _arg;
    return *this;
  }
  Type & set__load_id_len(
    const uint32_t & _arg)
  {
    this->load_id_len = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__MaxStringLens
    std::shared_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__MaxStringLens
    std::shared_ptr<vda5050_msgs::msg::MaxStringLens_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MaxStringLens_ & other) const
  {
    if (this->msg_len != other.msg_len) {
      return false;
    }
    if (this->topic_serial_len != other.topic_serial_len) {
      return false;
    }
    if (this->topic_elem_len != other.topic_elem_len) {
      return false;
    }
    if (this->id_len != other.id_len) {
      return false;
    }
    if (this->id_numerical_only != other.id_numerical_only) {
      return false;
    }
    if (this->enum_len != other.enum_len) {
      return false;
    }
    if (this->load_id_len != other.load_id_len) {
      return false;
    }
    return true;
  }
  bool operator!=(const MaxStringLens_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MaxStringLens_

// alias to use template instance with default allocator
using MaxStringLens =
  vda5050_msgs::msg::MaxStringLens_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_HPP_
