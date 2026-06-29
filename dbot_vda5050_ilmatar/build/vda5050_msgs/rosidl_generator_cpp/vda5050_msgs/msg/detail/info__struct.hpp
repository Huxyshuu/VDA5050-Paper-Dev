// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'info_references'
#include "vda5050_msgs/msg/detail/info_reference__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__Info __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__Info __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Info_
{
  using Type = Info_<ContainerAllocator>;

  explicit Info_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->info_type = "";
      this->info_description = "";
      this->info_level = "";
    }
  }

  explicit Info_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info_type(_alloc),
    info_description(_alloc),
    info_level(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->info_type = "";
      this->info_description = "";
      this->info_level = "";
    }
  }

  // field types and members
  using _info_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_type_type info_type;
  using _info_references_type =
    std::vector<vda5050_msgs::msg::InfoReference_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::InfoReference_<ContainerAllocator>>>;
  _info_references_type info_references;
  using _info_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_description_type info_description;
  using _info_level_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_level_type info_level;

  // setters for named parameter idiom
  Type & set__info_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info_type = _arg;
    return *this;
  }
  Type & set__info_references(
    const std::vector<vda5050_msgs::msg::InfoReference_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::InfoReference_<ContainerAllocator>>> & _arg)
  {
    this->info_references = _arg;
    return *this;
  }
  Type & set__info_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info_description = _arg;
    return *this;
  }
  Type & set__info_level(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info_level = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DEBUG;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> INFO;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::Info_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::Info_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Info_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Info_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Info_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Info_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Info_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Info_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Info_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Info_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__Info
    std::shared_ptr<vda5050_msgs::msg::Info_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__Info
    std::shared_ptr<vda5050_msgs::msg::Info_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Info_ & other) const
  {
    if (this->info_type != other.info_type) {
      return false;
    }
    if (this->info_references != other.info_references) {
      return false;
    }
    if (this->info_description != other.info_description) {
      return false;
    }
    if (this->info_level != other.info_level) {
      return false;
    }
    return true;
  }
  bool operator!=(const Info_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Info_

// alias to use template instance with default allocator
using Info =
  vda5050_msgs::msg::Info_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
Info_<ContainerAllocator>::DEBUG = "DEBUG";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
Info_<ContainerAllocator>::INFO = "INFO";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO__STRUCT_HPP_
