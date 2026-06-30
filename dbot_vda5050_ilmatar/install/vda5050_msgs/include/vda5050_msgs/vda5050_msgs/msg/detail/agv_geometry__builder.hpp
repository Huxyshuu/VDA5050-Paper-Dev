// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/agv_geometry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_AGVGeometry_envelopes3d
{
public:
  explicit Init_AGVGeometry_envelopes3d(::vda5050_msgs::msg::AGVGeometry & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::AGVGeometry envelopes3d(::vda5050_msgs::msg::AGVGeometry::_envelopes3d_type arg)
  {
    msg_.envelopes3d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVGeometry msg_;
};

class Init_AGVGeometry_envelopes2d
{
public:
  explicit Init_AGVGeometry_envelopes2d(::vda5050_msgs::msg::AGVGeometry & msg)
  : msg_(msg)
  {}
  Init_AGVGeometry_envelopes3d envelopes2d(::vda5050_msgs::msg::AGVGeometry::_envelopes2d_type arg)
  {
    msg_.envelopes2d = std::move(arg);
    return Init_AGVGeometry_envelopes3d(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVGeometry msg_;
};

class Init_AGVGeometry_wheel_definitions
{
public:
  Init_AGVGeometry_wheel_definitions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AGVGeometry_envelopes2d wheel_definitions(::vda5050_msgs::msg::AGVGeometry::_wheel_definitions_type arg)
  {
    msg_.wheel_definitions = std::move(arg);
    return Init_AGVGeometry_envelopes2d(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVGeometry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::AGVGeometry>()
{
  return vda5050_msgs::msg::builder::Init_AGVGeometry_wheel_definitions();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__BUILDER_HPP_
