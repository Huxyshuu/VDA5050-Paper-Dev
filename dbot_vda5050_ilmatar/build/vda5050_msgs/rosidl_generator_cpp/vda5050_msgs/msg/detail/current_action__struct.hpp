// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/CurrentAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__CurrentAction __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__CurrentAction __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CurrentAction_
{
  using Type = CurrentAction_<ContainerAllocator>;

  explicit CurrentAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = "";
      this->action_type = "";
      this->action_description = "";
      this->action_status = "";
      this->result_description = "";
    }
  }

  explicit CurrentAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action_id(_alloc),
    action_type(_alloc),
    action_description(_alloc),
    action_status(_alloc),
    result_description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = "";
      this->action_type = "";
      this->action_description = "";
      this->action_status = "";
      this->result_description = "";
    }
  }

  // field types and members
  using _action_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_id_type action_id;
  using _action_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_type_type action_type;
  using _action_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_description_type action_description;
  using _action_status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_status_type action_status;
  using _result_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_description_type result_description;

  // setters for named parameter idiom
  Type & set__action_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_id = _arg;
    return *this;
  }
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
  Type & set__action_status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_status = _arg;
    return *this;
  }
  Type & set__result_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_description = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> WAITING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> INITIALIZING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> RUNNING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> PAUSED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FINISHED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FAILED;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::CurrentAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::CurrentAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__CurrentAction
    std::shared_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__CurrentAction
    std::shared_ptr<vda5050_msgs::msg::CurrentAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CurrentAction_ & other) const
  {
    if (this->action_id != other.action_id) {
      return false;
    }
    if (this->action_type != other.action_type) {
      return false;
    }
    if (this->action_description != other.action_description) {
      return false;
    }
    if (this->action_status != other.action_status) {
      return false;
    }
    if (this->result_description != other.result_description) {
      return false;
    }
    return true;
  }
  bool operator!=(const CurrentAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CurrentAction_

// alias to use template instance with default allocator
using CurrentAction =
  vda5050_msgs::msg::CurrentAction_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::WAITING = "WAITING";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::INITIALIZING = "INITIALIZING";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::RUNNING = "RUNNING";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::PAUSED = "PAUSED";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::FINISHED = "FINISHED";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
CurrentAction_<ContainerAllocator>::FAILED = "FAILED";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__STRUCT_HPP_
