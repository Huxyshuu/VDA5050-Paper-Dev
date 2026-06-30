// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/LoadDimensions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/load_dimensions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_LoadDimensions_height
{
public:
  explicit Init_LoadDimensions_height(::vda5050_msgs::msg::LoadDimensions & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::LoadDimensions height(::vda5050_msgs::msg::LoadDimensions::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadDimensions msg_;
};

class Init_LoadDimensions_width
{
public:
  explicit Init_LoadDimensions_width(::vda5050_msgs::msg::LoadDimensions & msg)
  : msg_(msg)
  {}
  Init_LoadDimensions_height width(::vda5050_msgs::msg::LoadDimensions::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_LoadDimensions_height(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadDimensions msg_;
};

class Init_LoadDimensions_length
{
public:
  Init_LoadDimensions_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadDimensions_width length(::vda5050_msgs::msg::LoadDimensions::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_LoadDimensions_width(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadDimensions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::LoadDimensions>()
{
  return vda5050_msgs::msg::builder::Init_LoadDimensions_length();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__BUILDER_HPP_
