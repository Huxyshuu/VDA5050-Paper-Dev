// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/load_specification__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'load_sets'
#include "vda5050_msgs/msg/detail/load_set__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LoadSpecification & msg,
  std::ostream & out)
{
  out << "{";
  // member: load_positions
  {
    if (msg.load_positions.size() == 0) {
      out << "load_positions: []";
    } else {
      out << "load_positions: [";
      size_t pending_items = msg.load_positions.size();
      for (auto item : msg.load_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: load_sets
  {
    if (msg.load_sets.size() == 0) {
      out << "load_sets: []";
    } else {
      out << "load_sets: [";
      size_t pending_items = msg.load_sets.size();
      for (auto item : msg.load_sets) {
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
  const LoadSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: load_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.load_positions.size() == 0) {
      out << "load_positions: []\n";
    } else {
      out << "load_positions:\n";
      for (auto item : msg.load_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: load_sets
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.load_sets.size() == 0) {
      out << "load_sets: []\n";
    } else {
      out << "load_sets:\n";
      for (auto item : msg.load_sets) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadSpecification & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::LoadSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::LoadSpecification & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::LoadSpecification>()
{
  return "vda5050_msgs::msg::LoadSpecification";
}

template<>
inline const char * name<vda5050_msgs::msg::LoadSpecification>()
{
  return "vda5050_msgs/msg/LoadSpecification";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::LoadSpecification>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::LoadSpecification>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::LoadSpecification>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__TRAITS_HPP_
