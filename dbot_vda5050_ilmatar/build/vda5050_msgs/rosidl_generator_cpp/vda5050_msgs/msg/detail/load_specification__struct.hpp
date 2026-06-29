// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'load_sets'
#include "vda5050_msgs/msg/detail/load_set__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__LoadSpecification __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__LoadSpecification __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LoadSpecification_
{
  using Type = LoadSpecification_<ContainerAllocator>;

  explicit LoadSpecification_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit LoadSpecification_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _load_positions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _load_positions_type load_positions;
  using _load_sets_type =
    std::vector<vda5050_msgs::msg::LoadSet_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::LoadSet_<ContainerAllocator>>>;
  _load_sets_type load_sets;

  // setters for named parameter idiom
  Type & set__load_positions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->load_positions = _arg;
    return *this;
  }
  Type & set__load_sets(
    const std::vector<vda5050_msgs::msg::LoadSet_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::LoadSet_<ContainerAllocator>>> & _arg)
  {
    this->load_sets = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__LoadSpecification
    std::shared_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__LoadSpecification
    std::shared_ptr<vda5050_msgs::msg::LoadSpecification_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadSpecification_ & other) const
  {
    if (this->load_positions != other.load_positions) {
      return false;
    }
    if (this->load_sets != other.load_sets) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadSpecification_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadSpecification_

// alias to use template instance with default allocator
using LoadSpecification =
  vda5050_msgs::msg::LoadSpecification_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__STRUCT_HPP_
