// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__MaxArrayLens __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__MaxArrayLens __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MaxArrayLens_
{
  using Type = MaxArrayLens_<ContainerAllocator>;

  explicit MaxArrayLens_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_nodes = 0ul;
      this->order_edges = 0ul;
      this->node_actions = 0ul;
      this->edge_actions = 0ul;
      this->actions_parameters = 0ul;
      this->instant_actions = 0ul;
      this->trajectory_knot_vector = 0ul;
      this->trajectory_control_points = 0ul;
      this->state_node_states = 0ul;
      this->state_edge_states = 0ul;
      this->state_loads = 0ul;
      this->state_action_states = 0ul;
      this->state_errors = 0ul;
      this->state_information = 0ul;
      this->error_references = 0ul;
      this->info_references = 0ul;
    }
  }

  explicit MaxArrayLens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_nodes = 0ul;
      this->order_edges = 0ul;
      this->node_actions = 0ul;
      this->edge_actions = 0ul;
      this->actions_parameters = 0ul;
      this->instant_actions = 0ul;
      this->trajectory_knot_vector = 0ul;
      this->trajectory_control_points = 0ul;
      this->state_node_states = 0ul;
      this->state_edge_states = 0ul;
      this->state_loads = 0ul;
      this->state_action_states = 0ul;
      this->state_errors = 0ul;
      this->state_information = 0ul;
      this->error_references = 0ul;
      this->info_references = 0ul;
    }
  }

  // field types and members
  using _order_nodes_type =
    uint32_t;
  _order_nodes_type order_nodes;
  using _order_edges_type =
    uint32_t;
  _order_edges_type order_edges;
  using _node_actions_type =
    uint32_t;
  _node_actions_type node_actions;
  using _edge_actions_type =
    uint32_t;
  _edge_actions_type edge_actions;
  using _actions_parameters_type =
    uint32_t;
  _actions_parameters_type actions_parameters;
  using _instant_actions_type =
    uint32_t;
  _instant_actions_type instant_actions;
  using _trajectory_knot_vector_type =
    uint32_t;
  _trajectory_knot_vector_type trajectory_knot_vector;
  using _trajectory_control_points_type =
    uint32_t;
  _trajectory_control_points_type trajectory_control_points;
  using _state_node_states_type =
    uint32_t;
  _state_node_states_type state_node_states;
  using _state_edge_states_type =
    uint32_t;
  _state_edge_states_type state_edge_states;
  using _state_loads_type =
    uint32_t;
  _state_loads_type state_loads;
  using _state_action_states_type =
    uint32_t;
  _state_action_states_type state_action_states;
  using _state_errors_type =
    uint32_t;
  _state_errors_type state_errors;
  using _state_information_type =
    uint32_t;
  _state_information_type state_information;
  using _error_references_type =
    uint32_t;
  _error_references_type error_references;
  using _info_references_type =
    uint32_t;
  _info_references_type info_references;

  // setters for named parameter idiom
  Type & set__order_nodes(
    const uint32_t & _arg)
  {
    this->order_nodes = _arg;
    return *this;
  }
  Type & set__order_edges(
    const uint32_t & _arg)
  {
    this->order_edges = _arg;
    return *this;
  }
  Type & set__node_actions(
    const uint32_t & _arg)
  {
    this->node_actions = _arg;
    return *this;
  }
  Type & set__edge_actions(
    const uint32_t & _arg)
  {
    this->edge_actions = _arg;
    return *this;
  }
  Type & set__actions_parameters(
    const uint32_t & _arg)
  {
    this->actions_parameters = _arg;
    return *this;
  }
  Type & set__instant_actions(
    const uint32_t & _arg)
  {
    this->instant_actions = _arg;
    return *this;
  }
  Type & set__trajectory_knot_vector(
    const uint32_t & _arg)
  {
    this->trajectory_knot_vector = _arg;
    return *this;
  }
  Type & set__trajectory_control_points(
    const uint32_t & _arg)
  {
    this->trajectory_control_points = _arg;
    return *this;
  }
  Type & set__state_node_states(
    const uint32_t & _arg)
  {
    this->state_node_states = _arg;
    return *this;
  }
  Type & set__state_edge_states(
    const uint32_t & _arg)
  {
    this->state_edge_states = _arg;
    return *this;
  }
  Type & set__state_loads(
    const uint32_t & _arg)
  {
    this->state_loads = _arg;
    return *this;
  }
  Type & set__state_action_states(
    const uint32_t & _arg)
  {
    this->state_action_states = _arg;
    return *this;
  }
  Type & set__state_errors(
    const uint32_t & _arg)
  {
    this->state_errors = _arg;
    return *this;
  }
  Type & set__state_information(
    const uint32_t & _arg)
  {
    this->state_information = _arg;
    return *this;
  }
  Type & set__error_references(
    const uint32_t & _arg)
  {
    this->error_references = _arg;
    return *this;
  }
  Type & set__info_references(
    const uint32_t & _arg)
  {
    this->info_references = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__MaxArrayLens
    std::shared_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__MaxArrayLens
    std::shared_ptr<vda5050_msgs::msg::MaxArrayLens_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MaxArrayLens_ & other) const
  {
    if (this->order_nodes != other.order_nodes) {
      return false;
    }
    if (this->order_edges != other.order_edges) {
      return false;
    }
    if (this->node_actions != other.node_actions) {
      return false;
    }
    if (this->edge_actions != other.edge_actions) {
      return false;
    }
    if (this->actions_parameters != other.actions_parameters) {
      return false;
    }
    if (this->instant_actions != other.instant_actions) {
      return false;
    }
    if (this->trajectory_knot_vector != other.trajectory_knot_vector) {
      return false;
    }
    if (this->trajectory_control_points != other.trajectory_control_points) {
      return false;
    }
    if (this->state_node_states != other.state_node_states) {
      return false;
    }
    if (this->state_edge_states != other.state_edge_states) {
      return false;
    }
    if (this->state_loads != other.state_loads) {
      return false;
    }
    if (this->state_action_states != other.state_action_states) {
      return false;
    }
    if (this->state_errors != other.state_errors) {
      return false;
    }
    if (this->state_information != other.state_information) {
      return false;
    }
    if (this->error_references != other.error_references) {
      return false;
    }
    if (this->info_references != other.info_references) {
      return false;
    }
    return true;
  }
  bool operator!=(const MaxArrayLens_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MaxArrayLens_

// alias to use template instance with default allocator
using MaxArrayLens =
  vda5050_msgs::msg::MaxArrayLens_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__STRUCT_HPP_
