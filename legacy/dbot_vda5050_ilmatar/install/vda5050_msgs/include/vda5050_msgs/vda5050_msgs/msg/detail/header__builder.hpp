// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Header.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__HEADER__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__HEADER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/header__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Header_serial_number
{
public:
  explicit Init_Header_serial_number(::vda5050_msgs::msg::Header & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Header serial_number(::vda5050_msgs::msg::Header::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Header msg_;
};

class Init_Header_manufacturer
{
public:
  explicit Init_Header_manufacturer(::vda5050_msgs::msg::Header & msg)
  : msg_(msg)
  {}
  Init_Header_serial_number manufacturer(::vda5050_msgs::msg::Header::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_Header_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::Header msg_;
};

class Init_Header_version
{
public:
  explicit Init_Header_version(::vda5050_msgs::msg::Header & msg)
  : msg_(msg)
  {}
  Init_Header_manufacturer version(::vda5050_msgs::msg::Header::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_Header_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::Header msg_;
};

class Init_Header_timestamp
{
public:
  explicit Init_Header_timestamp(::vda5050_msgs::msg::Header & msg)
  : msg_(msg)
  {}
  Init_Header_version timestamp(::vda5050_msgs::msg::Header::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Header_version(msg_);
  }

private:
  ::vda5050_msgs::msg::Header msg_;
};

class Init_Header_header_id
{
public:
  Init_Header_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Header_timestamp header_id(::vda5050_msgs::msg::Header::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_Header_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::Header msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Header>()
{
  return vda5050_msgs::msg::builder::Init_Header_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__HEADER__BUILDER_HPP_
