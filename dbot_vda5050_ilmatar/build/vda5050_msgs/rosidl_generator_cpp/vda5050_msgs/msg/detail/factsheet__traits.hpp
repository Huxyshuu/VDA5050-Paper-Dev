// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__FACTSHEET__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__FACTSHEET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/factsheet__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'type_specification'
#include "vda5050_msgs/msg/detail/type_specification__traits.hpp"
// Member 'physical_parameters'
#include "vda5050_msgs/msg/detail/physical_parameters__traits.hpp"
// Member 'protocol_limits'
#include "vda5050_msgs/msg/detail/protocol_limits__traits.hpp"
// Member 'protocol_features'
#include "vda5050_msgs/msg/detail/protocol_features__traits.hpp"
// Member 'agv_geometry'
#include "vda5050_msgs/msg/detail/agv_geometry__traits.hpp"
// Member 'load_specification'
#include "vda5050_msgs/msg/detail/load_specification__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Factsheet & msg,
  std::ostream & out)
{
  out << "{";
  // member: header_id
  {
    out << "header_id: ";
    rosidl_generator_traits::value_to_yaml(msg.header_id, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: manufacturer
  {
    out << "manufacturer: ";
    rosidl_generator_traits::value_to_yaml(msg.manufacturer, out);
    out << ", ";
  }

  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << ", ";
  }

  // member: type_specification
  {
    out << "type_specification: ";
    to_flow_style_yaml(msg.type_specification, out);
    out << ", ";
  }

  // member: physical_parameters
  {
    out << "physical_parameters: ";
    to_flow_style_yaml(msg.physical_parameters, out);
    out << ", ";
  }

  // member: protocol_limits
  {
    out << "protocol_limits: ";
    to_flow_style_yaml(msg.protocol_limits, out);
    out << ", ";
  }

  // member: protocol_features
  {
    out << "protocol_features: ";
    to_flow_style_yaml(msg.protocol_features, out);
    out << ", ";
  }

  // member: agv_geometry
  {
    out << "agv_geometry: ";
    to_flow_style_yaml(msg.agv_geometry, out);
    out << ", ";
  }

  // member: load_specification
  {
    out << "load_specification: ";
    to_flow_style_yaml(msg.load_specification, out);
    out << ", ";
  }

  // member: localization_parameters
  {
    out << "localization_parameters: ";
    rosidl_generator_traits::value_to_yaml(msg.localization_parameters, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Factsheet & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_id: ";
    rosidl_generator_traits::value_to_yaml(msg.header_id, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: manufacturer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manufacturer: ";
    rosidl_generator_traits::value_to_yaml(msg.manufacturer, out);
    out << "\n";
  }

  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }

  // member: type_specification
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_specification:\n";
    to_block_style_yaml(msg.type_specification, out, indentation + 2);
  }

  // member: physical_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "physical_parameters:\n";
    to_block_style_yaml(msg.physical_parameters, out, indentation + 2);
  }

  // member: protocol_limits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "protocol_limits:\n";
    to_block_style_yaml(msg.protocol_limits, out, indentation + 2);
  }

  // member: protocol_features
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "protocol_features:\n";
    to_block_style_yaml(msg.protocol_features, out, indentation + 2);
  }

  // member: agv_geometry
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_geometry:\n";
    to_block_style_yaml(msg.agv_geometry, out, indentation + 2);
  }

  // member: load_specification
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_specification:\n";
    to_block_style_yaml(msg.load_specification, out, indentation + 2);
  }

  // member: localization_parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "localization_parameters: ";
    rosidl_generator_traits::value_to_yaml(msg.localization_parameters, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Factsheet & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Factsheet & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Factsheet & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Factsheet>()
{
  return "vda5050_msgs::msg::Factsheet";
}

template<>
inline const char * name<vda5050_msgs::msg::Factsheet>()
{
  return "vda5050_msgs/msg/Factsheet";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Factsheet>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Factsheet>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Factsheet>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__FACTSHEET__TRAITS_HPP_
