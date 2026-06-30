// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/max_array_lens__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_MaxArrayLens_info_references
{
public:
  explicit Init_MaxArrayLens_info_references(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::MaxArrayLens info_references(::vda5050_msgs::msg::MaxArrayLens::_info_references_type arg)
  {
    msg_.info_references = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_error_references
{
public:
  explicit Init_MaxArrayLens_error_references(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_info_references error_references(::vda5050_msgs::msg::MaxArrayLens::_error_references_type arg)
  {
    msg_.error_references = std::move(arg);
    return Init_MaxArrayLens_info_references(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_information
{
public:
  explicit Init_MaxArrayLens_state_information(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_error_references state_information(::vda5050_msgs::msg::MaxArrayLens::_state_information_type arg)
  {
    msg_.state_information = std::move(arg);
    return Init_MaxArrayLens_error_references(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_errors
{
public:
  explicit Init_MaxArrayLens_state_errors(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_information state_errors(::vda5050_msgs::msg::MaxArrayLens::_state_errors_type arg)
  {
    msg_.state_errors = std::move(arg);
    return Init_MaxArrayLens_state_information(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_action_states
{
public:
  explicit Init_MaxArrayLens_state_action_states(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_errors state_action_states(::vda5050_msgs::msg::MaxArrayLens::_state_action_states_type arg)
  {
    msg_.state_action_states = std::move(arg);
    return Init_MaxArrayLens_state_errors(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_loads
{
public:
  explicit Init_MaxArrayLens_state_loads(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_action_states state_loads(::vda5050_msgs::msg::MaxArrayLens::_state_loads_type arg)
  {
    msg_.state_loads = std::move(arg);
    return Init_MaxArrayLens_state_action_states(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_edge_states
{
public:
  explicit Init_MaxArrayLens_state_edge_states(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_loads state_edge_states(::vda5050_msgs::msg::MaxArrayLens::_state_edge_states_type arg)
  {
    msg_.state_edge_states = std::move(arg);
    return Init_MaxArrayLens_state_loads(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_state_node_states
{
public:
  explicit Init_MaxArrayLens_state_node_states(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_edge_states state_node_states(::vda5050_msgs::msg::MaxArrayLens::_state_node_states_type arg)
  {
    msg_.state_node_states = std::move(arg);
    return Init_MaxArrayLens_state_edge_states(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_trajectory_control_points
{
public:
  explicit Init_MaxArrayLens_trajectory_control_points(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_state_node_states trajectory_control_points(::vda5050_msgs::msg::MaxArrayLens::_trajectory_control_points_type arg)
  {
    msg_.trajectory_control_points = std::move(arg);
    return Init_MaxArrayLens_state_node_states(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_trajectory_knot_vector
{
public:
  explicit Init_MaxArrayLens_trajectory_knot_vector(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_trajectory_control_points trajectory_knot_vector(::vda5050_msgs::msg::MaxArrayLens::_trajectory_knot_vector_type arg)
  {
    msg_.trajectory_knot_vector = std::move(arg);
    return Init_MaxArrayLens_trajectory_control_points(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_instant_actions
{
public:
  explicit Init_MaxArrayLens_instant_actions(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_trajectory_knot_vector instant_actions(::vda5050_msgs::msg::MaxArrayLens::_instant_actions_type arg)
  {
    msg_.instant_actions = std::move(arg);
    return Init_MaxArrayLens_trajectory_knot_vector(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_actions_parameters
{
public:
  explicit Init_MaxArrayLens_actions_parameters(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_instant_actions actions_parameters(::vda5050_msgs::msg::MaxArrayLens::_actions_parameters_type arg)
  {
    msg_.actions_parameters = std::move(arg);
    return Init_MaxArrayLens_instant_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_edge_actions
{
public:
  explicit Init_MaxArrayLens_edge_actions(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_actions_parameters edge_actions(::vda5050_msgs::msg::MaxArrayLens::_edge_actions_type arg)
  {
    msg_.edge_actions = std::move(arg);
    return Init_MaxArrayLens_actions_parameters(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_node_actions
{
public:
  explicit Init_MaxArrayLens_node_actions(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_edge_actions node_actions(::vda5050_msgs::msg::MaxArrayLens::_node_actions_type arg)
  {
    msg_.node_actions = std::move(arg);
    return Init_MaxArrayLens_edge_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_order_edges
{
public:
  explicit Init_MaxArrayLens_order_edges(::vda5050_msgs::msg::MaxArrayLens & msg)
  : msg_(msg)
  {}
  Init_MaxArrayLens_node_actions order_edges(::vda5050_msgs::msg::MaxArrayLens::_order_edges_type arg)
  {
    msg_.order_edges = std::move(arg);
    return Init_MaxArrayLens_node_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

class Init_MaxArrayLens_order_nodes
{
public:
  Init_MaxArrayLens_order_nodes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MaxArrayLens_order_edges order_nodes(::vda5050_msgs::msg::MaxArrayLens::_order_nodes_type arg)
  {
    msg_.order_nodes = std::move(arg);
    return Init_MaxArrayLens_order_edges(msg_);
  }

private:
  ::vda5050_msgs::msg::MaxArrayLens msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::MaxArrayLens>()
{
  return vda5050_msgs::msg::builder::Init_MaxArrayLens_order_nodes();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__BUILDER_HPP_
