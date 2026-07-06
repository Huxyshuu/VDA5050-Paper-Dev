// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/protocol_limits__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_ProtocolLimits_timing
{
public:
  explicit Init_ProtocolLimits_timing(::vda5050_msgs::msg::ProtocolLimits & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::ProtocolLimits timing(::vda5050_msgs::msg::ProtocolLimits::_timing_type arg)
  {
    msg_.timing = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::ProtocolLimits msg_;
};

class Init_ProtocolLimits_max_array_lens
{
public:
  explicit Init_ProtocolLimits_max_array_lens(::vda5050_msgs::msg::ProtocolLimits & msg)
  : msg_(msg)
  {}
  Init_ProtocolLimits_timing max_array_lens(::vda5050_msgs::msg::ProtocolLimits::_max_array_lens_type arg)
  {
    msg_.max_array_lens = std::move(arg);
    return Init_ProtocolLimits_timing(msg_);
  }

private:
  ::vda5050_msgs::msg::ProtocolLimits msg_;
};

class Init_ProtocolLimits_max_string_lens
{
public:
  Init_ProtocolLimits_max_string_lens()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProtocolLimits_max_array_lens max_string_lens(::vda5050_msgs::msg::ProtocolLimits::_max_string_lens_type arg)
  {
    msg_.max_string_lens = std::move(arg);
    return Init_ProtocolLimits_max_array_lens(msg_);
  }

private:
  ::vda5050_msgs::msg::ProtocolLimits msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::ProtocolLimits>()
{
  return vda5050_msgs::msg::builder::Init_ProtocolLimits_max_string_lens();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__BUILDER_HPP_
