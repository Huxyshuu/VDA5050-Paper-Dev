// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/InfoReference.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/info_reference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_InfoReference_reference_value
{
public:
  explicit Init_InfoReference_reference_value(::vda5050_msgs::msg::InfoReference & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::InfoReference reference_value(::vda5050_msgs::msg::InfoReference::_reference_value_type arg)
  {
    msg_.reference_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::InfoReference msg_;
};

class Init_InfoReference_reference_key
{
public:
  Init_InfoReference_reference_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InfoReference_reference_value reference_key(::vda5050_msgs::msg::InfoReference::_reference_key_type arg)
  {
    msg_.reference_key = std::move(arg);
    return Init_InfoReference_reference_value(msg_);
  }

private:
  ::vda5050_msgs::msg::InfoReference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::InfoReference>()
{
  return vda5050_msgs::msg::builder::Init_InfoReference_reference_key();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__BUILDER_HPP_
