// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/protocol_features__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'optional_parameters'
#include "vda5050_msgs/msg/detail/optional_parameter__traits.hpp"
// Member 'agv_actions'
#include "vda5050_msgs/msg/detail/agv_action__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProtocolFeatures & msg,
  std::ostream & out)
{
  out << "{";
  // member: optional_parameters
  {
    if (msg.optional_parameters.size() == 0) {
      out << "optional_parameters: []";
    } else {
      out << "optional_parameters: [";
      size_t pending_items = msg.optional_parameters.size();
      for (auto item : msg.optional_parameters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: agv_actions
  {
    if (msg.agv_actions.size() == 0) {
      out << "agv_actions: []";
    } else {
      out << "agv_actions: [";
      size_t pending_items = msg.agv_actions.size();
      for (auto item : msg.agv_actions) {
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
  const ProtocolFeatures & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: optional_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.optional_parameters.size() == 0) {
      out << "optional_parameters: []\n";
    } else {
      out << "optional_parameters:\n";
      for (auto item : msg.optional_parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: agv_actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.agv_actions.size() == 0) {
      out << "agv_actions: []\n";
    } else {
      out << "agv_actions:\n";
      for (auto item : msg.agv_actions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProtocolFeatures & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::ProtocolFeatures & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::ProtocolFeatures & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::ProtocolFeatures>()
{
  return "vda5050_msgs::msg::ProtocolFeatures";
}

template<>
inline const char * name<vda5050_msgs::msg::ProtocolFeatures>()
{
  return "vda5050_msgs/msg/ProtocolFeatures";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::ProtocolFeatures>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::ProtocolFeatures>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::ProtocolFeatures>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__TRAITS_HPP_
