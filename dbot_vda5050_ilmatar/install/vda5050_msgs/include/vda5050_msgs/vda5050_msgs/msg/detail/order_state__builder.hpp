// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/order_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_OrderState_safety_state
{
public:
  explicit Init_OrderState_safety_state(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::OrderState safety_state(::vda5050_msgs::msg::OrderState::_safety_state_type arg)
  {
    msg_.safety_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_informations
{
public:
  explicit Init_OrderState_informations(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_safety_state informations(::vda5050_msgs::msg::OrderState::_informations_type arg)
  {
    msg_.informations = std::move(arg);
    return Init_OrderState_safety_state(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_errors
{
public:
  explicit Init_OrderState_errors(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_informations errors(::vda5050_msgs::msg::OrderState::_errors_type arg)
  {
    msg_.errors = std::move(arg);
    return Init_OrderState_informations(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_operating_mode
{
public:
  explicit Init_OrderState_operating_mode(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_errors operating_mode(::vda5050_msgs::msg::OrderState::_operating_mode_type arg)
  {
    msg_.operating_mode = std::move(arg);
    return Init_OrderState_errors(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_battery_state
{
public:
  explicit Init_OrderState_battery_state(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_operating_mode battery_state(::vda5050_msgs::msg::OrderState::_battery_state_type arg)
  {
    msg_.battery_state = std::move(arg);
    return Init_OrderState_operating_mode(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_action_states
{
public:
  explicit Init_OrderState_action_states(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_battery_state action_states(::vda5050_msgs::msg::OrderState::_action_states_type arg)
  {
    msg_.action_states = std::move(arg);
    return Init_OrderState_battery_state(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_distance_since_last_node
{
public:
  explicit Init_OrderState_distance_since_last_node(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_action_states distance_since_last_node(::vda5050_msgs::msg::OrderState::_distance_since_last_node_type arg)
  {
    msg_.distance_since_last_node = std::move(arg);
    return Init_OrderState_action_states(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_new_base_request
{
public:
  explicit Init_OrderState_new_base_request(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_distance_since_last_node new_base_request(::vda5050_msgs::msg::OrderState::_new_base_request_type arg)
  {
    msg_.new_base_request = std::move(arg);
    return Init_OrderState_distance_since_last_node(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_paused
{
public:
  explicit Init_OrderState_paused(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_new_base_request paused(::vda5050_msgs::msg::OrderState::_paused_type arg)
  {
    msg_.paused = std::move(arg);
    return Init_OrderState_new_base_request(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_driving
{
public:
  explicit Init_OrderState_driving(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_paused driving(::vda5050_msgs::msg::OrderState::_driving_type arg)
  {
    msg_.driving = std::move(arg);
    return Init_OrderState_paused(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_loads
{
public:
  explicit Init_OrderState_loads(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_driving loads(::vda5050_msgs::msg::OrderState::_loads_type arg)
  {
    msg_.loads = std::move(arg);
    return Init_OrderState_driving(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_velocity
{
public:
  explicit Init_OrderState_velocity(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_loads velocity(::vda5050_msgs::msg::OrderState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_OrderState_loads(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_agv_position
{
public:
  explicit Init_OrderState_agv_position(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_velocity agv_position(::vda5050_msgs::msg::OrderState::_agv_position_type arg)
  {
    msg_.agv_position = std::move(arg);
    return Init_OrderState_velocity(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_edge_states
{
public:
  explicit Init_OrderState_edge_states(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_agv_position edge_states(::vda5050_msgs::msg::OrderState::_edge_states_type arg)
  {
    msg_.edge_states = std::move(arg);
    return Init_OrderState_agv_position(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_node_states
{
public:
  explicit Init_OrderState_node_states(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_edge_states node_states(::vda5050_msgs::msg::OrderState::_node_states_type arg)
  {
    msg_.node_states = std::move(arg);
    return Init_OrderState_edge_states(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_last_node_sequence_id
{
public:
  explicit Init_OrderState_last_node_sequence_id(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_node_states last_node_sequence_id(::vda5050_msgs::msg::OrderState::_last_node_sequence_id_type arg)
  {
    msg_.last_node_sequence_id = std::move(arg);
    return Init_OrderState_node_states(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_last_node_id
{
public:
  explicit Init_OrderState_last_node_id(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_last_node_sequence_id last_node_id(::vda5050_msgs::msg::OrderState::_last_node_id_type arg)
  {
    msg_.last_node_id = std::move(arg);
    return Init_OrderState_last_node_sequence_id(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_zone_set_id
{
public:
  explicit Init_OrderState_zone_set_id(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_last_node_id zone_set_id(::vda5050_msgs::msg::OrderState::_zone_set_id_type arg)
  {
    msg_.zone_set_id = std::move(arg);
    return Init_OrderState_last_node_id(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_order_update_id
{
public:
  explicit Init_OrderState_order_update_id(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_zone_set_id order_update_id(::vda5050_msgs::msg::OrderState::_order_update_id_type arg)
  {
    msg_.order_update_id = std::move(arg);
    return Init_OrderState_zone_set_id(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_order_id
{
public:
  explicit Init_OrderState_order_id(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_order_update_id order_id(::vda5050_msgs::msg::OrderState::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_OrderState_order_update_id(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_serial_number
{
public:
  explicit Init_OrderState_serial_number(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_order_id serial_number(::vda5050_msgs::msg::OrderState::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_OrderState_order_id(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_manufacturer
{
public:
  explicit Init_OrderState_manufacturer(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_serial_number manufacturer(::vda5050_msgs::msg::OrderState::_manufacturer_type arg)
  {
    msg_.manufacturer = std::move(arg);
    return Init_OrderState_serial_number(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_version
{
public:
  explicit Init_OrderState_version(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_manufacturer version(::vda5050_msgs::msg::OrderState::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_OrderState_manufacturer(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_timestamp
{
public:
  explicit Init_OrderState_timestamp(::vda5050_msgs::msg::OrderState & msg)
  : msg_(msg)
  {}
  Init_OrderState_version timestamp(::vda5050_msgs::msg::OrderState::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_OrderState_version(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

class Init_OrderState_header_id
{
public:
  Init_OrderState_header_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderState_timestamp header_id(::vda5050_msgs::msg::OrderState::_header_id_type arg)
  {
    msg_.header_id = std::move(arg);
    return Init_OrderState_timestamp(msg_);
  }

private:
  ::vda5050_msgs::msg::OrderState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::OrderState>()
{
  return vda5050_msgs::msg::builder::Init_OrderState_header_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__BUILDER_HPP_
