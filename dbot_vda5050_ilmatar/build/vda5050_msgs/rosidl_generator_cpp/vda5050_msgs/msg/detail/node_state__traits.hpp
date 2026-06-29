// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/NodeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE_STATE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__NODE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/node_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'node_position'
#include "vda5050_msgs/msg/detail/node_position__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodeState & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_id
  {
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << ", ";
  }

  // member: sequence_id
  {
    out << "sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_id, out);
    out << ", ";
  }

  // member: node_description
  {
    out << "node_description: ";
    rosidl_generator_traits::value_to_yaml(msg.node_description, out);
    out << ", ";
  }

  // member: node_position
  {
    out << "node_position: ";
    to_flow_style_yaml(msg.node_position, out);
    out << ", ";
  }

  // member: released
  {
    out << "released: ";
    rosidl_generator_traits::value_to_yaml(msg.released, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << "\n";
  }

  // member: sequence_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_id, out);
    out << "\n";
  }

  // member: node_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_description: ";
    rosidl_generator_traits::value_to_yaml(msg.node_description, out);
    out << "\n";
  }

  // member: node_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_position:\n";
    to_block_style_yaml(msg.node_position, out, indentation + 2);
  }

  // member: released
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "released: ";
    rosidl_generator_traits::value_to_yaml(msg.released, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodeState & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::NodeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::NodeState & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::NodeState>()
{
  return "vda5050_msgs::msg::NodeState";
}

template<>
inline const char * name<vda5050_msgs::msg::NodeState>()
{
  return "vda5050_msgs/msg/NodeState";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::NodeState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::NodeState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::NodeState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE_STATE__TRAITS_HPP_
