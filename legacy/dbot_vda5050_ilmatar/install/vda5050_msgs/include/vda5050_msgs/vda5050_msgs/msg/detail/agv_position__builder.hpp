// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/AGVPosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/agv_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_AGVPosition_map_description
{
public:
  explicit Init_AGVPosition_map_description(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::AGVPosition map_description(::vda5050_msgs::msg::AGVPosition::_map_description_type arg)
  {
    msg_.map_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_map_id
{
public:
  explicit Init_AGVPosition_map_id(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_map_description map_id(::vda5050_msgs::msg::AGVPosition::_map_id_type arg)
  {
    msg_.map_id = std::move(arg);
    return Init_AGVPosition_map_description(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_theta
{
public:
  explicit Init_AGVPosition_theta(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_map_id theta(::vda5050_msgs::msg::AGVPosition::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_AGVPosition_map_id(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_y
{
public:
  explicit Init_AGVPosition_y(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_theta y(::vda5050_msgs::msg::AGVPosition::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_AGVPosition_theta(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_x
{
public:
  explicit Init_AGVPosition_x(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_y x(::vda5050_msgs::msg::AGVPosition::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AGVPosition_y(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_deviation_range
{
public:
  explicit Init_AGVPosition_deviation_range(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_x deviation_range(::vda5050_msgs::msg::AGVPosition::_deviation_range_type arg)
  {
    msg_.deviation_range = std::move(arg);
    return Init_AGVPosition_x(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_localization_score
{
public:
  explicit Init_AGVPosition_localization_score(::vda5050_msgs::msg::AGVPosition & msg)
  : msg_(msg)
  {}
  Init_AGVPosition_deviation_range localization_score(::vda5050_msgs::msg::AGVPosition::_localization_score_type arg)
  {
    msg_.localization_score = std::move(arg);
    return Init_AGVPosition_deviation_range(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

class Init_AGVPosition_position_initialized
{
public:
  Init_AGVPosition_position_initialized()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AGVPosition_localization_score position_initialized(::vda5050_msgs::msg::AGVPosition::_position_initialized_type arg)
  {
    msg_.position_initialized = std::move(arg);
    return Init_AGVPosition_localization_score(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::AGVPosition>()
{
  return vda5050_msgs::msg::builder::Init_AGVPosition_position_initialized();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__BUILDER_HPP_
