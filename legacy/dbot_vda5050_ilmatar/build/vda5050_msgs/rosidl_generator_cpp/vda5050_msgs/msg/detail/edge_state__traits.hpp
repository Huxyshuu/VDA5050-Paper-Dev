// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/edge_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
#include "vda5050_msgs/msg/detail/trajectory__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EdgeState & msg,
  std::ostream & out)
{
  out << "{";
  // member: edge_id
  {
    out << "edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_id, out);
    out << ", ";
  }

  // member: sequence_id
  {
    out << "sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_id, out);
    out << ", ";
  }

  // member: edge_description
  {
    out << "edge_description: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_description, out);
    out << ", ";
  }

  // member: released
  {
    out << "released: ";
    rosidl_generator_traits::value_to_yaml(msg.released, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EdgeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: edge_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_id, out);
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

  // member: edge_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "edge_description: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_description, out);
    out << "\n";
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

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EdgeState & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::EdgeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::EdgeState & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::EdgeState>()
{
  return "vda5050_msgs::msg::EdgeState";
}

template<>
inline const char * name<vda5050_msgs::msg::EdgeState>()
{
  return "vda5050_msgs/msg/EdgeState";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::EdgeState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::EdgeState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::EdgeState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__TRAITS_HPP_
