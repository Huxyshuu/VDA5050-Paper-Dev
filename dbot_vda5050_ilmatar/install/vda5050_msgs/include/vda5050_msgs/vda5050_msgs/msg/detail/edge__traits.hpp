// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Edge.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/edge__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
#include "vda5050_msgs/msg/detail/trajectory__traits.hpp"
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Edge & msg,
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

  // member: start_node_id
  {
    out << "start_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.start_node_id, out);
    out << ", ";
  }

  // member: end_node_id
  {
    out << "end_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.end_node_id, out);
    out << ", ";
  }

  // member: max_speed
  {
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << ", ";
  }

  // member: max_height
  {
    out << "max_height: ";
    rosidl_generator_traits::value_to_yaml(msg.max_height, out);
    out << ", ";
  }

  // member: min_height
  {
    out << "min_height: ";
    rosidl_generator_traits::value_to_yaml(msg.min_height, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: rotation_allowed
  {
    out << "rotation_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation_allowed, out);
    out << ", ";
  }

  // member: max_rotation_speed
  {
    out << "max_rotation_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_rotation_speed, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
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
  const Edge & msg,
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

  // member: start_node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.start_node_id, out);
    out << "\n";
  }

  // member: end_node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.end_node_id, out);
    out << "\n";
  }

  // member: max_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << "\n";
  }

  // member: max_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_height: ";
    rosidl_generator_traits::value_to_yaml(msg.max_height, out);
    out << "\n";
  }

  // member: min_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_height: ";
    rosidl_generator_traits::value_to_yaml(msg.min_height, out);
    out << "\n";
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: rotation_allowed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation_allowed, out);
    out << "\n";
  }

  // member: max_rotation_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_rotation_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_rotation_speed, out);
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

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
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

inline std::string to_yaml(const Edge & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Edge & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Edge & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Edge>()
{
  return "vda5050_msgs::msg::Edge";
}

template<>
inline const char * name<vda5050_msgs::msg::Edge>()
{
  return "vda5050_msgs/msg/Edge";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Edge>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Edge>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Edge>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE__TRAITS_HPP_
