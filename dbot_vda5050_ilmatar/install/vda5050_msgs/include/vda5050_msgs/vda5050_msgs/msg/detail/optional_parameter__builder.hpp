// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/OptionalParameter.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/optional_parameter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_OptionalParameter_description
{
public:
  explicit Init_OptionalParameter_description(::vda5050_msgs::msg::OptionalParameter & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::OptionalParameter description(::vda5050_msgs::msg::OptionalParameter::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::OptionalParameter msg_;
};

class Init_OptionalParameter_support
{
public:
  explicit Init_OptionalParameter_support(::vda5050_msgs::msg::OptionalParameter & msg)
  : msg_(msg)
  {}
  Init_OptionalParameter_description support(::vda5050_msgs::msg::OptionalParameter::_support_type arg)
  {
    msg_.support = std::move(arg);
    return Init_OptionalParameter_description(msg_);
  }

private:
  ::vda5050_msgs::msg::OptionalParameter msg_;
};

class Init_OptionalParameter_parameter
{
public:
  Init_OptionalParameter_parameter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OptionalParameter_support parameter(::vda5050_msgs::msg::OptionalParameter::_parameter_type arg)
  {
    msg_.parameter = std::move(arg);
    return Init_OptionalParameter_support(msg_);
  }

private:
  ::vda5050_msgs::msg::OptionalParameter msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::OptionalParameter>()
{
  return vda5050_msgs::msg::builder::Init_OptionalParameter_parameter();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__OPTIONAL_PARAMETER__BUILDER_HPP_
