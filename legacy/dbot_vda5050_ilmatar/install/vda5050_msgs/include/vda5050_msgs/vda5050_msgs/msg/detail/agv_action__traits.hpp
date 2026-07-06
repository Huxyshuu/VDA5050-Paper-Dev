// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/agv_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'action_parameters'
#include "vda5050_msgs/msg/detail/action_parameter_definition__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AGVAction & msg,
  std::ostream & out)
{
  out << "{";
  // member: action_type
  {
    out << "action_type: ";
    rosidl_generator_traits::value_to_yaml(msg.action_type, out);
    out << ", ";
  }

  // member: action_description
  {
    out << "action_description: ";
    rosidl_generator_traits::value_to_yaml(msg.action_description, out);
    out << ", ";
  }

  // member: action_scopes
  {
    if (msg.action_scopes.size() == 0) {
      out << "action_scopes: []";
    } else {
      out << "action_scopes: [";
      size_t pending_items = msg.action_scopes.size();
      for (auto item : msg.action_scopes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: action_parameters
  {
    if (msg.action_parameters.size() == 0) {
      out << "action_parameters: []";
    } else {
      out << "action_parameters: [";
      size_t pending_items = msg.action_parameters.size();
      for (auto item : msg.action_parameters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: result_description
  {
    out << "result_description: ";
    rosidl_generator_traits::value_to_yaml(msg.result_description, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AGVAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: action_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_type: ";
    rosidl_generator_traits::value_to_yaml(msg.action_type, out);
    out << "\n";
  }

  // member: action_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_description: ";
    rosidl_generator_traits::value_to_yaml(msg.action_description, out);
    out << "\n";
  }

  // member: action_scopes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action_scopes.size() == 0) {
      out << "action_scopes: []\n";
    } else {
      out << "action_scopes:\n";
      for (auto item : msg.action_scopes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: action_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action_parameters.size() == 0) {
      out << "action_parameters: []\n";
    } else {
      out << "action_parameters:\n";
      for (auto item : msg.action_parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: result_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_description: ";
    rosidl_generator_traits::value_to_yaml(msg.result_description, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AGVAction & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::AGVAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::AGVAction & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::AGVAction>()
{
  return "vda5050_msgs::msg::AGVAction";
}

template<>
inline const char * name<vda5050_msgs::msg::AGVAction>()
{
  return "vda5050_msgs/msg/AGVAction";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::AGVAction>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::AGVAction>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::AGVAction>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__TRAITS_HPP_
