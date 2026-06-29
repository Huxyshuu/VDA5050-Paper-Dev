// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/Edge.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_HPP_

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
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__Edge __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__Edge __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Edge_
{
  using Type = Edge_<ContainerAllocator>;

  explicit Edge_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_id = "";
      this->sequence_id = 0ul;
      this->edge_description = "";
      this->released = false;
      this->start_node_id = "";
      this->end_node_id = "";
      this->max_speed = 0.0;
      this->max_height = 0.0;
      this->min_height = 0.0;
      this->orientation = 0.0;
      this->direction = "";
      this->rotation_allowed = false;
      this->max_rotation_speed = 0.0;
      this->length = 0.0;
    }
  }

  explicit Edge_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : edge_id(_alloc),
    edge_description(_alloc),
    start_node_id(_alloc),
    end_node_id(_alloc),
    direction(_alloc),
    trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_id = "";
      this->sequence_id = 0ul;
      this->edge_description = "";
      this->released = false;
      this->start_node_id = "";
      this->end_node_id = "";
      this->max_speed = 0.0;
      this->max_height = 0.0;
      this->min_height = 0.0;
      this->orientation = 0.0;
      this->direction = "";
      this->rotation_allowed = false;
      this->max_rotation_speed = 0.0;
      this->length = 0.0;
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
  using _start_node_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _start_node_id_type start_node_id;
  using _end_node_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _end_node_id_type end_node_id;
  using _max_speed_type =
    double;
  _max_speed_type max_speed;
  using _max_height_type =
    double;
  _max_height_type max_height;
  using _min_height_type =
    double;
  _min_height_type min_height;
  using _orientation_type =
    double;
  _orientation_type orientation;
  using _direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direction_type direction;
  using _rotation_allowed_type =
    bool;
  _rotation_allowed_type rotation_allowed;
  using _max_rotation_speed_type =
    double;
  _max_rotation_speed_type max_rotation_speed;
  using _trajectory_type =
    vda5050_msgs::msg::Trajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _length_type =
    double;
  _length_type length;
  using _actions_type =
    std::vector<vda5050_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Action_<ContainerAllocator>>>;
  _actions_type actions;

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
  Type & set__start_node_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->start_node_id = _arg;
    return *this;
  }
  Type & set__end_node_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->end_node_id = _arg;
    return *this;
  }
  Type & set__max_speed(
    const double & _arg)
  {
    this->max_speed = _arg;
    return *this;
  }
  Type & set__max_height(
    const double & _arg)
  {
    this->max_height = _arg;
    return *this;
  }
  Type & set__min_height(
    const double & _arg)
  {
    this->min_height = _arg;
    return *this;
  }
  Type & set__orientation(
    const double & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__rotation_allowed(
    const bool & _arg)
  {
    this->rotation_allowed = _arg;
    return *this;
  }
  Type & set__max_rotation_speed(
    const double & _arg)
  {
    this->max_rotation_speed = _arg;
    return *this;
  }
  Type & set__trajectory(
    const vda5050_msgs::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__length(
    const double & _arg)
  {
    this->length = _arg;
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
    vda5050_msgs::msg::Edge_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::Edge_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Edge_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::Edge_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__Edge
    std::shared_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__Edge
    std::shared_ptr<vda5050_msgs::msg::Edge_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Edge_ & other) const
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
    if (this->start_node_id != other.start_node_id) {
      return false;
    }
    if (this->end_node_id != other.end_node_id) {
      return false;
    }
    if (this->max_speed != other.max_speed) {
      return false;
    }
    if (this->max_height != other.max_height) {
      return false;
    }
    if (this->min_height != other.min_height) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->rotation_allowed != other.rotation_allowed) {
      return false;
    }
    if (this->max_rotation_speed != other.max_rotation_speed) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->actions != other.actions) {
      return false;
    }
    return true;
  }
  bool operator!=(const Edge_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Edge_

// alias to use template instance with default allocator
using Edge =
  vda5050_msgs::msg::Edge_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_HPP_
