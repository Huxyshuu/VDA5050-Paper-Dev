// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/CurrentAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/current_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CurrentAction & msg,
  std::ostream & out)
{
  out << "{";
  // member: action_id
  {
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
    out << ", ";
  }

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

  // member: action_status
  {
    out << "action_status: ";
    rosidl_generator_traits::value_to_yaml(msg.action_status, out);
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
  const CurrentAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: action_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_id: ";
    rosidl_generator_traits::value_to_yaml(msg.action_id, out);
    out << "\n";
  }

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

  // member: action_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_status: ";
    rosidl_generator_traits::value_to_yaml(msg.action_status, out);
    out << "\n";
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

inline std::string to_yaml(const CurrentAction & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::CurrentAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::CurrentAction & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::CurrentAction>()
{
  return "vda5050_msgs::msg::CurrentAction";
}

template<>
inline const char * name<vda5050_msgs::msg::CurrentAction>()
{
  return "vda5050_msgs/msg/CurrentAction";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::CurrentAction>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::CurrentAction>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::CurrentAction>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__TRAITS_HPP_
