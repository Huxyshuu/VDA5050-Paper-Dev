// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/BoundingBoxReference.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/bounding_box_reference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxReference_theta
{
public:
  explicit Init_BoundingBoxReference_theta(::vda5050_msgs::msg::BoundingBoxReference & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::BoundingBoxReference theta(::vda5050_msgs::msg::BoundingBoxReference::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::BoundingBoxReference msg_;
};

class Init_BoundingBoxReference_z
{
public:
  explicit Init_BoundingBoxReference_z(::vda5050_msgs::msg::BoundingBoxReference & msg)
  : msg_(msg)
  {}
  Init_BoundingBoxReference_theta z(::vda5050_msgs::msg::BoundingBoxReference::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_BoundingBoxReference_theta(msg_);
  }

private:
  ::vda5050_msgs::msg::BoundingBoxReference msg_;
};

class Init_BoundingBoxReference_y
{
public:
  explicit Init_BoundingBoxReference_y(::vda5050_msgs::msg::BoundingBoxReference & msg)
  : msg_(msg)
  {}
  Init_BoundingBoxReference_z y(::vda5050_msgs::msg::BoundingBoxReference::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BoundingBoxReference_z(msg_);
  }

private:
  ::vda5050_msgs::msg::BoundingBoxReference msg_;
};

class Init_BoundingBoxReference_x
{
public:
  Init_BoundingBoxReference_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxReference_y x(::vda5050_msgs::msg::BoundingBoxReference::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BoundingBoxReference_y(msg_);
  }

private:
  ::vda5050_msgs::msg::BoundingBoxReference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::BoundingBoxReference>()
{
  return vda5050_msgs::msg::builder::Init_BoundingBoxReference_x();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__BOUNDING_BOX_REFERENCE__BUILDER_HPP_
