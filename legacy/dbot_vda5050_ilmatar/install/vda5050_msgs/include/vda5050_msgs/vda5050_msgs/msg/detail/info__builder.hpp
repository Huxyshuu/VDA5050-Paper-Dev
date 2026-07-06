// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Info_info_level
{
public:
  explicit Init_Info_info_level(::vda5050_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Info info_level(::vda5050_msgs::msg::Info::_info_level_type arg)
  {
    msg_.info_level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Info msg_;
};

class Init_Info_info_description
{
public:
  explicit Init_Info_info_description(::vda5050_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_info_level info_description(::vda5050_msgs::msg::Info::_info_description_type arg)
  {
    msg_.info_description = std::move(arg);
    return Init_Info_info_level(msg_);
  }

private:
  ::vda5050_msgs::msg::Info msg_;
};

class Init_Info_info_references
{
public:
  explicit Init_Info_info_references(::vda5050_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_info_description info_references(::vda5050_msgs::msg::Info::_info_references_type arg)
  {
    msg_.info_references = std::move(arg);
    return Init_Info_info_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Info msg_;
};

class Init_Info_info_type
{
public:
  Init_Info_info_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Info_info_references info_type(::vda5050_msgs::msg::Info::_info_type_type arg)
  {
    msg_.info_type = std::move(arg);
    return Init_Info_info_references(msg_);
  }

private:
  ::vda5050_msgs::msg::Info msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Info>()
{
  return vda5050_msgs::msg::builder::Init_Info_info_type();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_
