// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/ActionParameter.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/action_parameter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_ActionParameter_value
{
public:
  explicit Init_ActionParameter_value(::vda5050_msgs::msg::ActionParameter & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::ActionParameter value(::vda5050_msgs::msg::ActionParameter::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameter msg_;
};

class Init_ActionParameter_key
{
public:
  Init_ActionParameter_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionParameter_value key(::vda5050_msgs::msg::ActionParameter::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_ActionParameter_value(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameter msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::ActionParameter>()
{
  return vda5050_msgs::msg::builder::Init_ActionParameter_key();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER__BUILDER_HPP_
