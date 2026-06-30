// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/type_specification__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TypeSpecification & msg,
  std::ostream & out)
{
  out << "{";
  // member: series_name
  {
    out << "series_name: ";
    rosidl_generator_traits::value_to_yaml(msg.series_name, out);
    out << ", ";
  }

  // member: series_description
  {
    out << "series_description: ";
    rosidl_generator_traits::value_to_yaml(msg.series_description, out);
    out << ", ";
  }

  // member: agv_kinematic
  {
    out << "agv_kinematic: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_kinematic, out);
    out << ", ";
  }

  // member: agv_class
  {
    out << "agv_class: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_class, out);
    out << ", ";
  }

  // member: max_load_mass
  {
    out << "max_load_mass: ";
    rosidl_generator_traits::value_to_yaml(msg.max_load_mass, out);
    out << ", ";
  }

  // member: localization_types
  {
    if (msg.localization_types.size() == 0) {
      out << "localization_types: []";
    } else {
      out << "localization_types: [";
      size_t pending_items = msg.localization_types.size();
      for (auto item : msg.localization_types) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: navigation_types
  {
    if (msg.navigation_types.size() == 0) {
      out << "navigation_types: []";
    } else {
      out << "navigation_types: [";
      size_t pending_items = msg.navigation_types.size();
      for (auto item : msg.navigation_types) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const TypeSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: series_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "series_name: ";
    rosidl_generator_traits::value_to_yaml(msg.series_name, out);
    out << "\n";
  }

  // member: series_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "series_description: ";
    rosidl_generator_traits::value_to_yaml(msg.series_description, out);
    out << "\n";
  }

  // member: agv_kinematic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_kinematic: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_kinematic, out);
    out << "\n";
  }

  // member: agv_class
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_class: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_class, out);
    out << "\n";
  }

  // member: max_load_mass
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_load_mass: ";
    rosidl_generator_traits::value_to_yaml(msg.max_load_mass, out);
    out << "\n";
  }

  // member: localization_types
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.localization_types.size() == 0) {
      out << "localization_types: []\n";
    } else {
      out << "localization_types:\n";
      for (auto item : msg.localization_types) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: navigation_types
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.navigation_types.size() == 0) {
      out << "navigation_types: []\n";
    } else {
      out << "navigation_types:\n";
      for (auto item : msg.navigation_types) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TypeSpecification & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::TypeSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::TypeSpecification & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::TypeSpecification>()
{
  return "vda5050_msgs::msg::TypeSpecification";
}

template<>
inline const char * name<vda5050_msgs::msg::TypeSpecification>()
{
  return "vda5050_msgs/msg/TypeSpecification";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::TypeSpecification>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::TypeSpecification>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::TypeSpecification>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__TRAITS_HPP_
