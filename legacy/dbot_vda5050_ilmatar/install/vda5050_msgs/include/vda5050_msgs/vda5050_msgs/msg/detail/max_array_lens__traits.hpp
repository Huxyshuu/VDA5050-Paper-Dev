// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/max_array_lens__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MaxArrayLens & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_nodes
  {
    out << "order_nodes: ";
    rosidl_generator_traits::value_to_yaml(msg.order_nodes, out);
    out << ", ";
  }

  // member: order_edges
  {
    out << "order_edges: ";
    rosidl_generator_traits::value_to_yaml(msg.order_edges, out);
    out << ", ";
  }

  // member: node_actions
  {
    out << "node_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.node_actions, out);
    out << ", ";
  }

  // member: edge_actions
  {
    out << "edge_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_actions, out);
    out << ", ";
  }

  // member: actions_parameters
  {
    out << "actions_parameters: ";
    rosidl_generator_traits::value_to_yaml(msg.actions_parameters, out);
    out << ", ";
  }

  // member: instant_actions
  {
    out << "instant_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.instant_actions, out);
    out << ", ";
  }

  // member: trajectory_knot_vector
  {
    out << "trajectory_knot_vector: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_knot_vector, out);
    out << ", ";
  }

  // member: trajectory_control_points
  {
    out << "trajectory_control_points: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_control_points, out);
    out << ", ";
  }

  // member: state_node_states
  {
    out << "state_node_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_node_states, out);
    out << ", ";
  }

  // member: state_edge_states
  {
    out << "state_edge_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_edge_states, out);
    out << ", ";
  }

  // member: state_loads
  {
    out << "state_loads: ";
    rosidl_generator_traits::value_to_yaml(msg.state_loads, out);
    out << ", ";
  }

  // member: state_action_states
  {
    out << "state_action_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_action_states, out);
    out << ", ";
  }

  // member: state_errors
  {
    out << "state_errors: ";
    rosidl_generator_traits::value_to_yaml(msg.state_errors, out);
    out << ", ";
  }

  // member: state_information
  {
    out << "state_information: ";
    rosidl_generator_traits::value_to_yaml(msg.state_information, out);
    out << ", ";
  }

  // member: error_references
  {
    out << "error_references: ";
    rosidl_generator_traits::value_to_yaml(msg.error_references, out);
    out << ", ";
  }

  // member: info_references
  {
    out << "info_references: ";
    rosidl_generator_traits::value_to_yaml(msg.info_references, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MaxArrayLens & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_nodes: ";
    rosidl_generator_traits::value_to_yaml(msg.order_nodes, out);
    out << "\n";
  }

  // member: order_edges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_edges: ";
    rosidl_generator_traits::value_to_yaml(msg.order_edges, out);
    out << "\n";
  }

  // member: node_actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.node_actions, out);
    out << "\n";
  }

  // member: edge_actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "edge_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_actions, out);
    out << "\n";
  }

  // member: actions_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actions_parameters: ";
    rosidl_generator_traits::value_to_yaml(msg.actions_parameters, out);
    out << "\n";
  }

  // member: instant_actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "instant_actions: ";
    rosidl_generator_traits::value_to_yaml(msg.instant_actions, out);
    out << "\n";
  }

  // member: trajectory_knot_vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory_knot_vector: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_knot_vector, out);
    out << "\n";
  }

  // member: trajectory_control_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory_control_points: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_control_points, out);
    out << "\n";
  }

  // member: state_node_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_node_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_node_states, out);
    out << "\n";
  }

  // member: state_edge_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_edge_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_edge_states, out);
    out << "\n";
  }

  // member: state_loads
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_loads: ";
    rosidl_generator_traits::value_to_yaml(msg.state_loads, out);
    out << "\n";
  }

  // member: state_action_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_action_states: ";
    rosidl_generator_traits::value_to_yaml(msg.state_action_states, out);
    out << "\n";
  }

  // member: state_errors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_errors: ";
    rosidl_generator_traits::value_to_yaml(msg.state_errors, out);
    out << "\n";
  }

  // member: state_information
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_information: ";
    rosidl_generator_traits::value_to_yaml(msg.state_information, out);
    out << "\n";
  }

  // member: error_references
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_references: ";
    rosidl_generator_traits::value_to_yaml(msg.error_references, out);
    out << "\n";
  }

  // member: info_references
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info_references: ";
    rosidl_generator_traits::value_to_yaml(msg.info_references, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MaxArrayLens & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vda5050_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_msgs::msg::MaxArrayLens & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::MaxArrayLens & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::MaxArrayLens>()
{
  return "vda5050_msgs::msg::MaxArrayLens";
}

template<>
inline const char * name<vda5050_msgs::msg::MaxArrayLens>()
{
  return "vda5050_msgs/msg/MaxArrayLens";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::MaxArrayLens>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::MaxArrayLens>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::MaxArrayLens>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_ARRAY_LENS__TRAITS_HPP_
