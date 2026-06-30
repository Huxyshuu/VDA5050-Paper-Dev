// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/battery_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryState & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery_charge
  {
    out << "battery_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_charge, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: battery_health
  {
    out << "battery_health: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_health, out);
    out << ", ";
  }

  // member: charging
  {
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << ", ";
  }

  // member: reach
  {
    out << "reach: ";
    rosidl_generator_traits::value_to_yaml(msg.reach, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_charge, out);
    out << "\n";
  }

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: battery_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_health: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_health, out);
    out << "\n";
  }

  // member: charging
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << "\n";
  }

  // member: reach
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reach: ";
    rosidl_generator_traits::value_to_yaml(msg.reach, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryState & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::BatteryState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::BatteryState & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::BatteryState>()
{
  return "vda5050_msgs::msg::BatteryState";
}

template<>
inline const char * name<vda5050_msgs::msg::BatteryState>()
{
  return "vda5050_msgs/msg/BatteryState";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::BatteryState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::BatteryState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::BatteryState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
