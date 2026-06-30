// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Order_edges
{
public:
  explicit Init_Order_edges(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Order edges(::vda5050_msgs::msg::Order::_edges_type arg)
  {
    msg_.edges = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_nodes
{
public:
  explicit Init_Order_nodes(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_edges nodes(::vda5050_msgs::msg::Order::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return Init_Order_edges(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_zone_set_id
{
public:
  explicit Init_Order_zone_set_id(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_nodes zone_set_id(::vda5050_msgs::msg::Order::_zone_set_id_type arg)
  {
    msg_.zone_set_id = std::move(arg);
    return Init_Order_nodes(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_order_update_id
{
public:
  explicit Init_Order_order_update_id(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_zone_set_id order_update_id(::vda5050_msgs::msg::Order::_order_update_id_type arg)
  {
    msg_.order_update_id = std::move(arg);
    return Init_Order_zone_set_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_order_id
{
public:
  explicit Init_Order_order_id(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_order_update_id order_id(::vda5050_msgs::msg::Order::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_Order_order_update_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_serial_number
{
public:
  explicit Init_Order_serial_number(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_order_id serial_number(::vda5050_msgs::msg::Order::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_Order_order_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_manufacturer
{
public:
  explicit Init_Order_manufacturer(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_serial_number manufacturer(::vda5050_msgs::msg::Order::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_Order_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_version
{
public:
  explicit Init_Order_version(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_manufacturer version(::vda5050_msgs::msg::Order::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_Order_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_timestamp
{
public:
  explicit Init_Order_timestamp(::vda5050_msgs::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_version timestamp(::vda5050_msgs::msg::Order::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Order_version(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

class Init_Order_header_id
{
public:
  Init_Order_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_timestamp header_id(::vda5050_msgs::msg::Order::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_Order_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::Order msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Order>()
{
  return vda5050_msgs::msg::builder::Init_Order_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER__BUILDER_HPP_
