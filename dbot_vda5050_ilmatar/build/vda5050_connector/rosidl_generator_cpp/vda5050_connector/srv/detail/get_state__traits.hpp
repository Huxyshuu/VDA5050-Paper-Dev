// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_connector:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__TRAITS_HPP_
#define VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_connector/srv/detail/get_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_connector
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetState_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetState_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::srv::GetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::srv::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::srv::GetState_Request & msg)
{
  return vda5050_connector::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::srv::GetState_Request>()
{
  return "vda5050_connector::srv::GetState_Request";
}

template<>
inline const char * name<vda5050_connector::srv::GetState_Request>()
{
  return "vda5050_connector/srv/GetState_Request";
}

template<>
struct has_fixed_size<vda5050_connector::srv::GetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_connector::srv::GetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_connector::srv::GetState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'state'
#include "vda5050_msgs/msg/detail/order_state__traits.hpp"

namespace vda5050_connector
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetState_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetState_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::srv::GetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::srv::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::srv::GetState_Response & msg)
{
  return vda5050_connector::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::srv::GetState_Response>()
{
  return "vda5050_connector::srv::GetState_Response";
}

template<>
inline const char * name<vda5050_connector::srv::GetState_Response>()
{
  return "vda5050_connector/srv/GetState_Response";
}

template<>
struct has_fixed_size<vda5050_connector::srv::GetState_Response>
  : std::integral_constant<bool, has_fixed_size<vda5050_msgs::msg::OrderState>::value> {};

template<>
struct has_bounded_size<vda5050_connector::srv::GetState_Response>
  : std::integral_constant<bool, has_bounded_size<vda5050_msgs::msg::OrderState>::value> {};

template<>
struct is_message<vda5050_connector::srv::GetState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vda5050_connector::srv::GetState>()
{
  return "vda5050_connector::srv::GetState";
}

template<>
inline const char * name<vda5050_connector::srv::GetState>()
{
  return "vda5050_connector/srv/GetState";
}

template<>
struct has_fixed_size<vda5050_connector::srv::GetState>
  : std::integral_constant<
    bool,
    has_fixed_size<vda5050_connector::srv::GetState_Request>::value &&
    has_fixed_size<vda5050_connector::srv::GetState_Response>::value
  >
{
};

template<>
struct has_bounded_size<vda5050_connector::srv::GetState>
  : std::integral_constant<
    bool,
    has_bounded_size<vda5050_connector::srv::GetState_Request>::value &&
    has_bounded_size<vda5050_connector::srv::GetState_Response>::value
  >
{
};

template<>
struct is_service<vda5050_connector::srv::GetState>
  : std::true_type
{
};

template<>
struct is_service_request<vda5050_connector::srv::GetState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vda5050_connector::srv::GetState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__TRAITS_HPP_
