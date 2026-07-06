// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/agv_geometry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'wheel_definitions'
#include "vda5050_msgs/msg/detail/wheel_definition__traits.hpp"
// Member 'envelopes2d'
#include "vda5050_msgs/msg/detail/envelope2_d__traits.hpp"
// Member 'envelopes3d'
#include "vda5050_msgs/msg/detail/envelope3_d__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AGVGeometry & msg,
  std::ostream & out)
{
  out << "{";
  // member: wheel_definitions
  {
    if (msg.wheel_definitions.size() == 0) {
      out << "wheel_definitions: []";
    } else {
      out << "wheel_definitions: [";
      size_t pending_items = msg.wheel_definitions.size();
      for (auto item : msg.wheel_definitions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: envelopes2d
  {
    if (msg.envelopes2d.size() == 0) {
      out << "envelopes2d: []";
    } else {
      out << "envelopes2d: [";
      size_t pending_items = msg.envelopes2d.size();
      for (auto item : msg.envelopes2d) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: envelopes3d
  {
    if (msg.envelopes3d.size() == 0) {
      out << "envelopes3d: []";
    } else {
      out << "envelopes3d: [";
      size_t pending_items = msg.envelopes3d.size();
      for (auto item : msg.envelopes3d) {
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
  const AGVGeometry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: wheel_definitions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wheel_definitions.size() == 0) {
      out << "wheel_definitions: []\n";
    } else {
      out << "wheel_definitions:\n";
      for (auto item : msg.wheel_definitions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: envelopes2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.envelopes2d.size() == 0) {
      out << "envelopes2d: []\n";
    } else {
      out << "envelopes2d:\n";
      for (auto item : msg.envelopes2d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: envelopes3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.envelopes3d.size() == 0) {
      out << "envelopes3d: []\n";
    } else {
      out << "envelopes3d:\n";
      for (auto item : msg.envelopes3d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AGVGeometry & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::AGVGeometry & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::AGVGeometry & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::AGVGeometry>()
{
  return "vda5050_msgs::msg::AGVGeometry";
}

template<>
inline const char * name<vda5050_msgs::msg::AGVGeometry>()
{
  return "vda5050_msgs/msg/AGVGeometry";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::AGVGeometry>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::AGVGeometry>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::AGVGeometry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__TRAITS_HPP_
