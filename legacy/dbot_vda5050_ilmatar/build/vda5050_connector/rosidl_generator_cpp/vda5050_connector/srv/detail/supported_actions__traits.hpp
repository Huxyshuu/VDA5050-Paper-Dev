// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_connector:srv/SupportedActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__TRAITS_HPP_
#define VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_connector/srv/detail/supported_actions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_connector
{

namespace srv
{

inline void to_flow_style_yaml(
  const SupportedActions_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SupportedActions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SupportedActions_Request & msg, bool use_flow_style = false)
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
  const vda5050_connector::srv::SupportedActions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::srv::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::srv::SupportedActions_Request & msg)
{
  return vda5050_connector::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::srv::SupportedActions_Request>()
{
  return "vda5050_connector::srv::SupportedActions_Request";
}

template<>
inline const char * name<vda5050_connector::srv::SupportedActions_Request>()
{
  return "vda5050_connector/srv/SupportedActions_Request";
}

template<>
struct has_fixed_size<vda5050_connector::srv::SupportedActions_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_connector::srv::SupportedActions_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_connector::srv::SupportedActions_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'agv_actions'
#include "vda5050_msgs/msg/detail/agv_action__traits.hpp"

namespace vda5050_connector
{

namespace srv
{

inline void to_flow_style_yaml(
  const SupportedActions_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  const SupportedActions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const SupportedActions_Response & msg, bool use_flow_style = false)
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
  const vda5050_connector::srv::SupportedActions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::srv::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::srv::SupportedActions_Response & msg)
{
  return vda5050_connector::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::srv::SupportedActions_Response>()
{
  return "vda5050_connector::srv::SupportedActions_Response";
}

template<>
inline const char * name<vda5050_connector::srv::SupportedActions_Response>()
{
  return "vda5050_connector/srv/SupportedActions_Response";
}

template<>
struct has_fixed_size<vda5050_connector::srv::SupportedActions_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_connector::srv::SupportedActions_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_connector::srv::SupportedActions_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vda5050_connector::srv::SupportedActions>()
{
  return "vda5050_connector::srv::SupportedActions";
}

template<>
inline const char * name<vda5050_connector::srv::SupportedActions>()
{
  return "vda5050_connector/srv/SupportedActions";
}

template<>
struct has_fixed_size<vda5050_connector::srv::SupportedActions>
  : std::integral_constant<
    bool,
    has_fixed_size<vda5050_connector::srv::SupportedActions_Request>::value &&
    has_fixed_size<vda5050_connector::srv::SupportedActions_Response>::value
  >
{
};

template<>
struct has_bounded_size<vda5050_connector::srv::SupportedActions>
  : std::integral_constant<
    bool,
    has_bounded_size<vda5050_connector::srv::SupportedActions_Request>::value &&
    has_bounded_size<vda5050_connector::srv::SupportedActions_Response>::value
  >
{
};

template<>
struct is_service<vda5050_connector::srv::SupportedActions>
  : std::true_type
{
};

template<>
struct is_service_request<vda5050_connector::srv::SupportedActions_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vda5050_connector::srv::SupportedActions_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__TRAITS_HPP_
