// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'node_position'
#include "vda5050_msgs/msg/detail/node_position__traits.hpp"
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Node & msg,
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

  // member: released
  {
    out << "released: ";
    rosidl_generator_traits::value_to_yaml(msg.released, out);
    out << ", ";
  }

  // member: node_position
  {
    out << "node_position: ";
    to_flow_style_yaml(msg.node_position, out);
    out << ", ";
  }

  // member: actions
  {
    if (msg.actions.size() == 0) {
      out << "actions: []";
    } else {
      out << "actions: [";
      size_t pending_items = msg.actions.size();
      for (auto item : msg.actions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Node & msg,
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

  // member: released
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "released: ";
    rosidl_generator_traits::value_to_yaml(msg.released, out);
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

  // member: actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.actions.size() == 0) {
      out << "actions: []\n";
    } else {
      out << "actions:\n";
      for (auto item : msg.actions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Node & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Node & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Node & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Node>()
{
  return "vda5050_msgs::msg::Node";
}

template<>
inline const char * name<vda5050_msgs::msg::Node>()
{
  return "vda5050_msgs/msg/Node";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Node>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Node>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Node>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_
