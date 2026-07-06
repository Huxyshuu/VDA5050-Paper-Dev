// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__FACTSHEET__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__FACTSHEET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/factsheet__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Factsheet_localization_parameters
{
public:
  explicit Init_Factsheet_localization_parameters(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Factsheet localization_parameters(::vda5050_msgs::msg::Factsheet::_localization_parameters_type arg)
  {
    msg_.localization_parameters = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_load_specification
{
public:
  explicit Init_Factsheet_load_specification(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_localization_parameters load_specification(::vda5050_msgs::msg::Factsheet::_load_specification_type arg)
  {
    msg_.load_specification = std::move(arg);
    return Init_Factsheet_localization_parameters(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_agv_geometry
{
public:
  explicit Init_Factsheet_agv_geometry(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_load_specification agv_geometry(::vda5050_msgs::msg::Factsheet::_agv_geometry_type arg)
  {
    msg_.agv_geometry = std::move(arg);
    return Init_Factsheet_load_specification(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_protocol_features
{
public:
  explicit Init_Factsheet_protocol_features(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_agv_geometry protocol_features(::vda5050_msgs::msg::Factsheet::_protocol_features_type arg)
  {
    msg_.protocol_features = std::move(arg);
    return Init_Factsheet_agv_geometry(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_protocol_limits
{
public:
  explicit Init_Factsheet_protocol_limits(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_protocol_features protocol_limits(::vda5050_msgs::msg::Factsheet::_protocol_limits_type arg)
  {
    msg_.protocol_limits = std::move(arg);
    return Init_Factsheet_protocol_features(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_physical_parameters
{
public:
  explicit Init_Factsheet_physical_parameters(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_protocol_limits physical_parameters(::vda5050_msgs::msg::Factsheet::_physical_parameters_type arg)
  {
    msg_.physical_parameters = std::move(arg);
    return Init_Factsheet_protocol_limits(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_type_specification
{
public:
  explicit Init_Factsheet_type_specification(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_physical_parameters type_specification(::vda5050_msgs::msg::Factsheet::_type_specification_type arg)
  {
    msg_.type_specification = std::move(arg);
    return Init_Factsheet_physical_parameters(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_serial_number
{
public:
  explicit Init_Factsheet_serial_number(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_type_specification serial_number(::vda5050_msgs::msg::Factsheet::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_Factsheet_type_specification(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_manufacturer
{
public:
  explicit Init_Factsheet_manufacturer(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_serial_number manufacturer(::vda5050_msgs::msg::Factsheet::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_Factsheet_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_version
{
public:
  explicit Init_Factsheet_version(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_manufacturer version(::vda5050_msgs::msg::Factsheet::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_Factsheet_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_timestamp
{
public:
  explicit Init_Factsheet_timestamp(::vda5050_msgs::msg::Factsheet & msg)
  : msg_(msg)
  {}
  Init_Factsheet_version timestamp(::vda5050_msgs::msg::Factsheet::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Factsheet_version(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

class Init_Factsheet_header_id
{
public:
  Init_Factsheet_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Factsheet_timestamp header_id(::vda5050_msgs::msg::Factsheet::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_Factsheet_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::Factsheet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Factsheet>()
{
  return vda5050_msgs::msg::builder::Init_Factsheet_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__FACTSHEET__BUILDER_HPP_
