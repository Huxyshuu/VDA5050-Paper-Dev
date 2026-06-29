// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/SafetyState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/safety_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_SafetyState_field_violation
{
public:
  explicit Init_SafetyState_field_violation(::vda5050_msgs::msg::SafetyState & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::SafetyState field_violation(::vda5050_msgs::msg::SafetyState::_field_violation_type arg)
  {
    msg_.field_violation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::SafetyState msg_;
};

class Init_SafetyState_e_stop
{
public:
  Init_SafetyState_e_stop()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyState_field_violation e_stop(::vda5050_msgs::msg::SafetyState::_e_stop_type arg)
  {
    msg_.e_stop = std::move(arg);
    return Init_SafetyState_field_violation(msg_);
  }

private:
  ::vda5050_msgs::msg::SafetyState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::SafetyState>()
{
  return vda5050_msgs::msg::builder::Init_SafetyState_e_stop();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__SAFETY_STATE__BUILDER_HPP_
