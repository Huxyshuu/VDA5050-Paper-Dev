// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/protocol_features__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_ProtocolFeatures_agv_actions
{
public:
  explicit Init_ProtocolFeatures_agv_actions(::vda5050_msgs::msg::ProtocolFeatures & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::ProtocolFeatures agv_actions(::vda5050_msgs::msg::ProtocolFeatures::_agv_actions_type arg)
  {
    msg_.agv_actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::ProtocolFeatures msg_;
};

class Init_ProtocolFeatures_optional_parameters
{
public:
  Init_ProtocolFeatures_optional_parameters()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProtocolFeatures_agv_actions optional_parameters(::vda5050_msgs::msg::ProtocolFeatures::_optional_parameters_type arg)
  {
    msg_.optional_parameters = std::move(arg);
    return Init_ProtocolFeatures_agv_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::ProtocolFeatures msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::ProtocolFeatures>()
{
  return vda5050_msgs::msg::builder::Init_ProtocolFeatures_optional_parameters();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_FEATURES__BUILDER_HPP_
