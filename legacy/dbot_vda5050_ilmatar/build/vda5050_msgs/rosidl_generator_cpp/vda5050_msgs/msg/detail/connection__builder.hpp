// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Connection.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CONNECTION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__CONNECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/connection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Connection_connection_state
{
public:
  explicit Init_Connection_connection_state(::vda5050_msgs::msg::Connection & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Connection connection_state(::vda5050_msgs::msg::Connection::_connection_state_type arg)
  {
    msg_.connection_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

class Init_Connection_serial_number
{
public:
  explicit Init_Connection_serial_number(::vda5050_msgs::msg::Connection & msg)
  : msg_(msg)
  {}
  Init_Connection_connection_state serial_number(::vda5050_msgs::msg::Connection::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_Connection_connection_state(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

class Init_Connection_manufacturer
{
public:
  explicit Init_Connection_manufacturer(::vda5050_msgs::msg::Connection & msg)
  : msg_(msg)
  {}
  Init_Connection_serial_number manufacturer(::vda5050_msgs::msg::Connection::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_Connection_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

class Init_Connection_version
{
public:
  explicit Init_Connection_version(::vda5050_msgs::msg::Connection & msg)
  : msg_(msg)
  {}
  Init_Connection_manufacturer version(::vda5050_msgs::msg::Connection::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_Connection_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

class Init_Connection_timestamp
{
public:
  explicit Init_Connection_timestamp(::vda5050_msgs::msg::Connection & msg)
  : msg_(msg)
  {}
  Init_Connection_version timestamp(::vda5050_msgs::msg::Connection::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Connection_version(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

class Init_Connection_header_id
{
public:
  Init_Connection_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Connection_timestamp header_id(::vda5050_msgs::msg::Connection::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_Connection_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::Connection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Connection>()
{
  return vda5050_msgs::msg::builder::Init_Connection_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__CONNECTION__BUILDER_HPP_
