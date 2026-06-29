// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'action_parameters'
#include "vda5050_msgs/msg/detail/action_parameter_definition__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__AGVAction __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__AGVAction __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AGVAction_
{
  using Type = AGVAction_<ContainerAllocator>;

  explicit AGVAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_type = "";
      this->action_description = "";
      this->result_description = "";
    }
  }

  explicit AGVAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action_type(_alloc),
    action_description(_alloc),
    result_description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_type = "";
      this->action_description = "";
      this->result_description = "";
    }
  }

  // field types and members
  using _action_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_type_type action_type;
  using _action_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_description_type action_description;
  using _action_scopes_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _action_scopes_type action_scopes;
  using _action_parameters_type =
    std::vector<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>>;
  _action_parameters_type action_parameters;
  using _result_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_description_type result_description;

  // setters for named parameter idiom
  Type & set__action_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_type = _arg;
    return *this;
  }
  Type & set__action_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_description = _arg;
    return *this;
  }
  Type & set__action_scopes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->action_scopes = _arg;
    return *this;
  }
  Type & set__action_parameters(
    const std::vector<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::ActionParameterDefinition_<ContainerAllocator>>> & _arg)
  {
    this->action_parameters = _arg;
    return *this;
  }
  Type & set__result_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_description = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> INSTANT;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> NODE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EDGE;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::AGVAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::AGVAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::AGVAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__AGVAction
    std::shared_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__AGVAction
    std::shared_ptr<vda5050_msgs::msg::AGVAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AGVAction_ & other) const
  {
    if (this->action_type != other.action_type) {
      return false;
    }
    if (this->action_description != other.action_description) {
      return false;
    }
    if (this->action_scopes != other.action_scopes) {
      return false;
    }
    if (this->action_parameters != other.action_parameters) {
      return false;
    }
    if (this->result_description != other.result_description) {
      return false;
    }
    return true;
  }
  bool operator!=(const AGVAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AGVAction_

// alias to use template instance with default allocator
using AGVAction =
  vda5050_msgs::msg::AGVAction_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
AGVAction_<ContainerAllocator>::INSTANT = "INSTANT";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
AGVAction_<ContainerAllocator>::NODE = "NODE";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
AGVAction_<ContainerAllocator>::EDGE = "EDGE";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__STRUCT_HPP_
