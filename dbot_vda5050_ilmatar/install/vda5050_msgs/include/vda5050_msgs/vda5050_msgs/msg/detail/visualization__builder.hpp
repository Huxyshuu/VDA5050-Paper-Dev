// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Visualization.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__VISUALIZATION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__VISUALIZATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/visualization__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Visualization_velocity
{
public:
  explicit Init_Visualization_velocity(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Visualization velocity(::vda5050_msgs::msg::Visualization::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_agv_position
{
public:
  explicit Init_Visualization_agv_position(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  Init_Visualization_velocity agv_position(::vda5050_msgs::msg::Visualization::_agv_position_type arg)
  {
    msg_.agv_position = std::move(arg);
    return Init_Visualization_velocity(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_serial_number
{
public:
  explicit Init_Visualization_serial_number(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  Init_Visualization_agv_position serial_number(::vda5050_msgs::msg::Visualization::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_Visualization_agv_position(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_manufacturer
{
public:
  explicit Init_Visualization_manufacturer(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  Init_Visualization_serial_number manufacturer(::vda5050_msgs::msg::Visualization::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_Visualization_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_version
{
public:
  explicit Init_Visualization_version(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  Init_Visualization_manufacturer version(::vda5050_msgs::msg::Visualization::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_Visualization_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_timestamp
{
public:
  explicit Init_Visualization_timestamp(::vda5050_msgs::msg::Visualization & msg)
  : msg_(msg)
  {}
  Init_Visualization_version timestamp(::vda5050_msgs::msg::Visualization::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Visualization_version(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

class Init_Visualization_header_id
{
public:
  Init_Visualization_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Visualization_timestamp header_id(::vda5050_msgs::msg::Visualization::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_Visualization_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::Visualization msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Visualization>()
{
  return vda5050_msgs::msg::builder::Init_Visualization_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__VISUALIZATION__BUILDER_HPP_
