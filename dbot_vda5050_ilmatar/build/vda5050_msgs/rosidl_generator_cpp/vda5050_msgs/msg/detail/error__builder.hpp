// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Error_error_level
{
public:
  explicit Init_Error_error_level(::vda5050_msgs::msg::Error & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Error error_level(::vda5050_msgs::msg::Error::_error_level_type arg)
  {
    msg_.error_level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Error msg_;
};

class Init_Error_error_description
{
public:
  explicit Init_Error_error_description(::vda5050_msgs::msg::Error & msg)
  : msg_(msg)
  {}
  Init_Error_error_level error_description(::vda5050_msgs::msg::Error::_error_description_type arg)
  {
    msg_.error_description = std::move(arg);
    return Init_Error_error_level(msg_);
  }

private:
  ::vda5050_msgs::msg::Error msg_;
};

class Init_Error_error_references
{
public:
  explicit Init_Error_error_references(::vda5050_msgs::msg::Error & msg)
  : msg_(msg)
  {}
  Init_Error_error_description error_references(::vda5050_msgs::msg::Error::_error_references_type arg)
  {
    msg_.error_references = std::move(arg);
    return Init_Error_error_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Error msg_;
};

class Init_Error_error_type
{
public:
  Init_Error_error_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Error_error_references error_type(::vda5050_msgs::msg::Error::_error_type_type arg)
  {
    msg_.error_type = std::move(arg);
    return Init_Error_error_references(msg_);
  }

private:
  ::vda5050_msgs::msg::Error msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Error>()
{
  return vda5050_msgs::msg::builder::Init_Error_error_type();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_
