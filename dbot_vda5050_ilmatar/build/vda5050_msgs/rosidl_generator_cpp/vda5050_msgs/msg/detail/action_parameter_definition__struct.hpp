// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/ActionParameterDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__ActionParameterDefinition __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__ActionParameterDefinition __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActionParameterDefinition_
{
  using Type = ActionParameterDefinition_<ContainerAllocator>;

  explicit ActionParameterDefinition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->value_data_type = "";
      this->description = "";
      this->is_optional = false;
    }
  }

  explicit ActionParameterDefinition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : key(_alloc),
    value_data_type(_alloc),
    description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->value_data_type = "";
      this->description = "";
      this->is_optional = false;
    }
  }

  // field types and members
  using _key_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _key_type key;
  using _value_data_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _value_data_type_type value_data_type;
  using _description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _description_type description;
  using _is_optional_type =
    bool;
  _is_optional_type is_optional;

  // setters for named parameter idiom
  Type & set__key(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__value_data_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->value_data_type = _arg;
    return *this;
  }
  Type & set__description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->description = _arg;
    return *this;
  }
  Type & set__is_optional(
    const bool & _arg)
  {
    this->is_optional = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> BOOL;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> NUMBER;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> INTEGER;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FLOAT;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> STRING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> OBJECT;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> ARRAY;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__ActionParameterDefinition
    std::shared_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__ActionParameterDefinition
    std::shared_ptr<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActionParameterDefinition_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->value_data_type != other.value_data_type) {
      return false;
    }
    if (this->description != other.description) {
      return false;
    }
    if (this->is_optional != other.is_optional) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActionParameterDefinition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActionParameterDefinition_

// alias to use template instance with default allocator
using ActionParameterDefinition =
  vda5050_msgs::msg::ActionParameterDefinition_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::BOOL = "BOOL";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::NUMBER = "NUMBER";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::INTEGER = "INTEGER";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::FLOAT = "FLOAT";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::STRING = "STRING";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::OBJECT = "OBJECT";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
ActionParameterDefinition_<ContainerAllocator>::ARRAY = "ARRAY";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__STRUCT_HPP_
