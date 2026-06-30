// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'action_parameters'
#include "vda5050_msgs/msg/detail/action_parameter__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Action & msg,
  std::ostream & out)
{
  out << "{";
  // member: action_type
  {
    out << "action_type: ";
    rosidl_generator_traits::value_to_yaml(msg.action_type, out);
    out << ", ";
  }

  // member: action_id
  {
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
    out << ", ";
  }

  // member: action_description
  {
    out << "action_description: ";
    rosidl_generator_traits::value_to_yaml(msg.action_description, out);
    out << ", ";
  }

  // member: blocking_type
  {
    out << "blocking_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blocking_type, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action & msg,
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

  // member: action_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
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

  // member: blocking_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blocking_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blocking_type, out);
    out << "\n";
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Action & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Action & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Action>()
{
  return "vda5050_msgs::msg::Action";
}

template<>
inline const char * name<vda5050_msgs::msg::Action>()
{
  return "vda5050_msgs/msg/Action";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Action>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION__TRAITS_HPP_
