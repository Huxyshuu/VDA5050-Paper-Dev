// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/InstantActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__InstantActions __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__InstantActions __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InstantActions_
{
  using Type = InstantActions_<ContainerAllocator>;

  explicit InstantActions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
    }
  }

  explicit InstantActions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc),
    version(_alloc),
    manufacturer(_alloc),
    serial_number(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
    }
  }

  // field types and members
  using _header_id_type =
    uint32_t;
  _header_id_type header_id;
  using _timestamp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_type timestamp;
  using _version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _version_type version;
  using _manufacturer_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _manufacturer_type manufacturer;
  using _serial_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _serial_number_type serial_number;
  using _actions_type =
    std::vector<vda5050_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Action_<ContainerAllocator>>>;
  _actions_type actions;

  // setters for named parameter idiom
  Type & set__header_id(
    const uint32_t & _arg)
  {
    this->header_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__manufacturer(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->manufacturer = _arg;
    return *this;
  }
  Type & set__serial_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }
  Type & set__actions(
    const std::vector<vda5050_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Action_<ContainerAllocator>>> & _arg)
  {
    this->actions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::InstantActions_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::InstantActions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::InstantActions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::InstantActions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__InstantActions
    std::shared_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__InstantActions
    std::shared_ptr<vda5050_msgs::msg::InstantActions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InstantActions_ & other) const
  {
    if (this->header_id != other.header_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->manufacturer != other.manufacturer) {
      return false;
    }
    if (this->serial_number != other.serial_number) {
      return false;
    }
    if (this->actions != other.actions) {
      return false;
    }
    return true;
  }
  bool operator!=(const InstantActions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InstantActions_

// alias to use template instance with default allocator
using InstantActions =
  vda5050_msgs::msg::InstantActions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__STRUCT_HPP_
