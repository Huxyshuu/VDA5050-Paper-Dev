// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/PolygonPoint.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/polygon_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_PolygonPoint_y
{
public:
  explicit Init_PolygonPoint_y(::vda5050_msgs::msg::PolygonPoint & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::PolygonPoint y(::vda5050_msgs::msg::PolygonPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::PolygonPoint msg_;
};

class Init_PolygonPoint_x
{
public:
  Init_PolygonPoint_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonPoint_y x(::vda5050_msgs::msg::PolygonPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PolygonPoint_y(msg_);
  }

private:
  ::vda5050_msgs::msg::PolygonPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::PolygonPoint>()
{
  return vda5050_msgs::msg::builder::Init_PolygonPoint_x();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__POLYGON_POINT__BUILDER_HPP_
