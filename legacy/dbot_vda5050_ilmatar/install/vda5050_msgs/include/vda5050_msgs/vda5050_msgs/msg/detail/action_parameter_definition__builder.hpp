// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/ActionParameterDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/action_parameter_definition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_ActionParameterDefinition_is_optional
{
public:
  explicit Init_ActionParameterDefinition_is_optional(::vda5050_msgs::msg::ActionParameterDefinition & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::ActionParameterDefinition is_optional(::vda5050_msgs::msg::ActionParameterDefinition::_is_optional_type arg)
  {
    msg_.is_optional = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameterDefinition msg_;
};

class Init_ActionParameterDefinition_description
{
public:
  explicit Init_ActionParameterDefinition_description(::vda5050_msgs::msg::ActionParameterDefinition & msg)
  : msg_(msg)
  {}
  Init_ActionParameterDefinition_is_optional description(::vda5050_msgs::msg::ActionParameterDefinition::_description_type arg)
  {
    msg_.description = std::move(arg);
    return Init_ActionParameterDefinition_is_optional(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameterDefinition msg_;
};

class Init_ActionParameterDefinition_value_data_type
{
public:
  explicit Init_ActionParameterDefinition_value_data_type(::vda5050_msgs::msg::ActionParameterDefinition & msg)
  : msg_(msg)
  {}
  Init_ActionParameterDefinition_description value_data_type(::vda5050_msgs::msg::ActionParameterDefinition::_value_data_type_type arg)
  {
    msg_.value_data_type = std::move(arg);
    return Init_ActionParameterDefinition_description(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameterDefinition msg_;
};

class Init_ActionParameterDefinition_key
{
public:
  Init_ActionParameterDefinition_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionParameterDefinition_value_data_type key(::vda5050_msgs::msg::ActionParameterDefinition::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_ActionParameterDefinition_value_data_type(msg_);
  }

private:
  ::vda5050_msgs::msg::ActionParameterDefinition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::ActionParameterDefinition>()
{
  return vda5050_msgs::msg::builder::Init_ActionParameterDefinition_key();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION_PARAMETER_DEFINITION__BUILDER_HPP_
