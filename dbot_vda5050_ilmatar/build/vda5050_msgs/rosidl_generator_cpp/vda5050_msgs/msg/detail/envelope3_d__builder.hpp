// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Envelope3D.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/envelope3_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Envelope3D_description
{
public:
  explicit Init_Envelope3D_description(::vda5050_msgs::msg::Envelope3D & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Envelope3D description(::vda5050_msgs::msg::Envelope3D::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope3D msg_;
};

class Init_Envelope3D_url
{
public:
  explicit Init_Envelope3D_url(::vda5050_msgs::msg::Envelope3D & msg)
  : msg_(msg)
  {}
  Init_Envelope3D_description url(::vda5050_msgs::msg::Envelope3D::_url_type arg)
  {
    msg_.url = std::move(arg);
    return Init_Envelope3D_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope3D msg_;
};

class Init_Envelope3D_data
{
public:
  explicit Init_Envelope3D_data(::vda5050_msgs::msg::Envelope3D & msg)
  : msg_(msg)
  {}
  Init_Envelope3D_url data(::vda5050_msgs::msg::Envelope3D::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_Envelope3D_url(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope3D msg_;
};

class Init_Envelope3D_format
{
public:
  explicit Init_Envelope3D_format(::vda5050_msgs::msg::Envelope3D & msg)
  : msg_(msg)
  {}
  Init_Envelope3D_data format(::vda5050_msgs::msg::Envelope3D::_format_type arg)
  {
    msg_.format = std::move(arg);
    return Init_Envelope3D_data(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope3D msg_;
};

class Init_Envelope3D_set
{
public:
  Init_Envelope3D_set()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Envelope3D_format set(::vda5050_msgs::msg::Envelope3D::_set_type arg)
  {
    msg_.set = std::move(arg);
    return Init_Envelope3D_format(msg_);
  }

private:
  ::vda5050_msgs::msg::Envelope3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Envelope3D>()
{
  return vda5050_msgs::msg::builder::Init_Envelope3D_set();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__BUILDER_HPP_
