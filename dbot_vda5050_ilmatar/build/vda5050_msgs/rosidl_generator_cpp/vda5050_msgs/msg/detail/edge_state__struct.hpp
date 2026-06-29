// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory'
#include "vda5050_msgs/msg/detail/trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__EdgeState __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__EdgeState __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EdgeState_
{
  using Type = EdgeState_<ContainerAllocator>;

  explicit EdgeState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_id = "";
      this->sequence_id = 0ul;
      this->edge_description = "";
      this->released = false;
    }
  }

  explicit EdgeState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : edge_id(_alloc),
    edge_description(_alloc),
    trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_id = "";
      this->sequence_id = 0ul;
      this->edge_description = "";
      this->released = false;
    }
  }

  // field types and members
  using _edge_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _edge_id_type edge_id;
  using _sequence_id_type =
    uint32_t;
  _sequence_id_type sequence_id;
  using _edge_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _edge_description_type edge_description;
  using _released_type =
    bool;
  _released_type released;
  using _trajectory_type =
    vda5050_msgs::msg::Trajectory_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__edge_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->edge_id = _arg;
    return *this;
  }
  Type & set__sequence_id(
    const uint32_t & _arg)
  {
    this->sequence_id = _arg;
    return *this;
  }
  Type & set__edge_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->edge_description = _arg;
    return *this;
  }
  Type & set__released(
    const bool & _arg)
  {
    this->released = _arg;
    return *this;
  }
  Type & set__trajectory(
    const vda5050_msgs::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::EdgeState_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::EdgeState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::EdgeState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::EdgeState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__EdgeState
    std::shared_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__EdgeState
    std::shared_ptr<vda5050_msgs::msg::EdgeState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EdgeState_ & other) const
  {
    if (this->edge_id != other.edge_id) {
      return false;
    }
    if (this->sequence_id != other.sequence_id) {
      return false;
    }
    if (this->edge_description != other.edge_description) {
      return false;
    }
    if (this->released != other.released) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const EdgeState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EdgeState_

// alias to use template instance with default allocator
using EdgeState =
  vda5050_msgs::msg::EdgeState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_HPP_
