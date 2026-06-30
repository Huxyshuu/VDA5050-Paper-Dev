// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/InstantActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/instant_actions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_InstantActions_actions
{
public:
  explicit Init_InstantActions_actions(::vda5050_msgs::msg::InstantActions & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::InstantActions actions(::vda5050_msgs::msg::InstantActions::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

class Init_InstantActions_serial_number
{
public:
  explicit Init_InstantActions_serial_number(::vda5050_msgs::msg::InstantActions & msg)
  : msg_(msg)
  {}
  Init_InstantActions_actions serial_number(::vda5050_msgs::msg::InstantActions::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_InstantActions_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

class Init_InstantActions_manufacturer
{
public:
  explicit Init_InstantActions_manufacturer(::vda5050_msgs::msg::InstantActions & msg)
  : msg_(msg)
  {}
  Init_InstantActions_serial_number manufacturer(::vda5050_msgs::msg::InstantActions::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_InstantActions_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

class Init_InstantActions_version
{
public:
  explicit Init_InstantActions_version(::vda5050_msgs::msg::InstantActions & msg)
  : msg_(msg)
  {}
  Init_InstantActions_manufacturer version(::vda5050_msgs::msg::InstantActions::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_InstantActions_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

class Init_InstantActions_timestamp
{
public:
  explicit Init_InstantActions_timestamp(::vda5050_msgs::msg::InstantActions & msg)
  : msg_(msg)
  {}
  Init_InstantActions_version timestamp(::vda5050_msgs::msg::InstantActions::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_InstantActions_version(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

class Init_InstantActions_header_id
{
public:
  Init_InstantActions_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InstantActions_timestamp header_id(::vda5050_msgs::msg::InstantActions::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_InstantActions_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::InstantActions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::InstantActions>()
{
  return vda5050_msgs::msg::builder::Init_InstantActions_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__INSTANT_ACTIONS__BUILDER_HPP_
