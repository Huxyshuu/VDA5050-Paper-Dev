// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'node_states'
#include "vda5050_msgs/msg/detail/node_state__struct.hpp"
// Member 'edge_states'
#include "vda5050_msgs/msg/detail/edge_state__struct.hpp"
// Member 'agv_position'
#include "vda5050_msgs/msg/detail/agv_position__struct.hpp"
// Member 'velocity'
#include "vda5050_msgs/msg/detail/velocity__struct.hpp"
// Member 'loads'
#include "vda5050_msgs/msg/detail/load__struct.hpp"
// Member 'action_states'
#include "vda5050_msgs/msg/detail/current_action__struct.hpp"
// Member 'battery_state'
#include "vda5050_msgs/msg/detail/battery_state__struct.hpp"
// Member 'errors'
#include "vda5050_msgs/msg/detail/error__struct.hpp"
// Member 'informations'
#include "vda5050_msgs/msg/detail/info__struct.hpp"
// Member 'safety_state'
#include "vda5050_msgs/msg/detail/safety_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__OrderState __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__OrderState __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrderState_
{
  using Type = OrderState_<ContainerAllocator>;

  explicit OrderState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : agv_position(_init),
    velocity(_init),
    battery_state(_init),
    safety_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
      this->order_id = "";
      this->order_update_id = 0ul;
      this->zone_set_id = "";
      this->last_node_id = "";
      this->last_node_sequence_id = 0ul;
      this->driving = false;
      this->paused = false;
      this->new_base_request = false;
      this->distance_since_last_node = 0.0;
      this->operating_mode = "";
    }
  }

  explicit OrderState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc),
    version(_alloc),
    manufacturer(_alloc),
    serial_number(_alloc),
    order_id(_alloc),
    zone_set_id(_alloc),
    last_node_id(_alloc),
    agv_position(_alloc, _init),
    velocity(_alloc, _init),
    battery_state(_alloc, _init),
    operating_mode(_alloc),
    safety_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header_id = 0ul;
      this->timestamp = "";
      this->version = "";
      this->manufacturer = "";
      this->serial_number = "";
      this->order_id = "";
      this->order_update_id = 0ul;
      this->zone_set_id = "";
      this->last_node_id = "";
      this->last_node_sequence_id = 0ul;
      this->driving = false;
      this->paused = false;
      this->new_base_request = false;
      this->distance_since_last_node = 0.0;
      this->operating_mode = "";
    }
  }

  // field types and members
  using _header_id_type =
    uint32_t;
  _header_id_type header_id;
  using _timestamp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_type timestamp;
  using _version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _version_type version;
  using _manufacturer_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _manufacturer_type manufacturer;
  using _serial_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _serial_number_type serial_number;
  using _order_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _order_id_type order_id;
  using _order_update_id_type =
    uint32_t;
  _order_update_id_type order_update_id;
  using _zone_set_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_set_id_type zone_set_id;
  using _last_node_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _last_node_id_type last_node_id;
  using _last_node_sequence_id_type =
    uint32_t;
  _last_node_sequence_id_type last_node_sequence_id;
  using _node_states_type =
    std::vector<vda5050_msgs::msg::NodeState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::NodeState_<ContainerAllocator>>>;
  _node_states_type node_states;
  using _edge_states_type =
    std::vector<vda5050_msgs::msg::EdgeState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::EdgeState_<ContainerAllocator>>>;
  _edge_states_type edge_states;
  using _agv_position_type =
    vda5050_msgs::msg::AGVPosition_<ContainerAllocator>;
  _agv_position_type agv_position;
  using _velocity_type =
    vda5050_msgs::msg::Velocity_<ContainerAllocator>;
  _velocity_type velocity;
  using _loads_type =
    std::vector<vda5050_msgs::msg::Load_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Load_<ContainerAllocator>>>;
  _loads_type loads;
  using _driving_type =
    bool;
  _driving_type driving;
  using _paused_type =
    bool;
  _paused_type paused;
  using _new_base_request_type =
    bool;
  _new_base_request_type new_base_request;
  using _distance_since_last_node_type =
    double;
  _distance_since_last_node_type distance_since_last_node;
  using _action_states_type =
    std::vector<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>>;
  _action_states_type action_states;
  using _battery_state_type =
    vda5050_msgs::msg::BatteryState_<ContainerAllocator>;
  _battery_state_type battery_state;
  using _operating_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _operating_mode_type operating_mode;
  using _errors_type =
    std::vector<vda5050_msgs::msg::Error_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Error_<ContainerAllocator>>>;
  _errors_type errors;
  using _informations_type =
    std::vector<vda5050_msgs::msg::Info_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Info_<ContainerAllocator>>>;
  _informations_type informations;
  using _safety_state_type =
    vda5050_msgs::msg::SafetyState_<ContainerAllocator>;
  _safety_state_type safety_state;

  // setters for named parameter idiom
  Type & set__header_id(
    const uint32_t & _arg)
  {
    this->header_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__manufacturer(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->manufacturer = _arg;
    return *this;
  }
  Type & set__serial_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }
  Type & set__order_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order_id = _arg;
    return *this;
  }
  Type & set__order_update_id(
    const uint32_t & _arg)
  {
    this->order_update_id = _arg;
    return *this;
  }
  Type & set__zone_set_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_set_id = _arg;
    return *this;
  }
  Type & set__last_node_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->last_node_id = _arg;
    return *this;
  }
  Type & set__last_node_sequence_id(
    const uint32_t & _arg)
  {
    this->last_node_sequence_id = _arg;
    return *this;
  }
  Type & set__node_states(
    const std::vector<vda5050_msgs::msg::NodeState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::NodeState_<ContainerAllocator>>> & _arg)
  {
    this->node_states = _arg;
    return *this;
  }
  Type & set__edge_states(
    const std::vector<vda5050_msgs::msg::EdgeState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::EdgeState_<ContainerAllocator>>> & _arg)
  {
    this->edge_states = _arg;
    return *this;
  }
  Type & set__agv_position(
    const vda5050_msgs::msg::AGVPosition_<ContainerAllocator> & _arg)
  {
    this->agv_position = _arg;
    return *this;
  }
  Type & set__velocity(
    const vda5050_msgs::msg::Velocity_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__loads(
    const std::vector<vda5050_msgs::msg::Load_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Load_<ContainerAllocator>>> & _arg)
  {
    this->loads = _arg;
    return *this;
  }
  Type & set__driving(
    const bool & _arg)
  {
    this->driving = _arg;
    return *this;
  }
  Type & set__paused(
    const bool & _arg)
  {
    this->paused = _arg;
    return *this;
  }
  Type & set__new_base_request(
    const bool & _arg)
  {
    this->new_base_request = _arg;
    return *this;
  }
  Type & set__distance_since_last_node(
    const double & _arg)
  {
    this->distance_since_last_node = _arg;
    return *this;
  }
  Type & set__action_states(
    const std::vector<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::CurrentAction_<ContainerAllocator>>> & _arg)
  {
    this->action_states = _arg;
    return *this;
  }
  Type & set__battery_state(
    const vda5050_msgs::msg::BatteryState_<ContainerAllocator> & _arg)
  {
    this->battery_state = _arg;
    return *this;
  }
  Type & set__operating_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->operating_mode = _arg;
    return *this;
  }
  Type & set__errors(
    const std::vector<vda5050_msgs::msg::Error_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Error_<ContainerAllocator>>> & _arg)
  {
    this->errors = _arg;
    return *this;
  }
  Type & set__informations(
    const std::vector<vda5050_msgs::msg::Info_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vda5050_msgs::msg::Info_<ContainerAllocator>>> & _arg)
  {
    this->informations = _arg;
    return *this;
  }
  Type & set__safety_state(
    const vda5050_msgs::msg::SafetyState_<ContainerAllocator> & _arg)
  {
    this->safety_state = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> AUTOMATIC;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SEMIAUTOMATIC;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MANUAL;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SERVICE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> TEACHIN;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::OrderState_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::OrderState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::OrderState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::OrderState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__OrderState
    std::shared_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__OrderState
    std::shared_ptr<vda5050_msgs::msg::OrderState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderState_ & other) const
  {
    if (this->header_id != other.header_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->manufacturer != other.manufacturer) {
      return false;
    }
    if (this->serial_number != other.serial_number) {
      return false;
    }
    if (this->order_id != other.order_id) {
      return false;
    }
    if (this->order_update_id != other.order_update_id) {
      return false;
    }
    if (this->zone_set_id != other.zone_set_id) {
      return false;
    }
    if (this->last_node_id != other.last_node_id) {
      return false;
    }
    if (this->last_node_sequence_id != other.last_node_sequence_id) {
      return false;
    }
    if (this->node_states != other.node_states) {
      return false;
    }
    if (this->edge_states != other.edge_states) {
      return false;
    }
    if (this->agv_position != other.agv_position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->loads != other.loads) {
      return false;
    }
    if (this->driving != other.driving) {
      return false;
    }
    if (this->paused != other.paused) {
      return false;
    }
    if (this->new_base_request != other.new_base_request) {
      return false;
    }
    if (this->distance_since_last_node != other.distance_since_last_node) {
      return false;
    }
    if (this->action_states != other.action_states) {
      return false;
    }
    if (this->battery_state != other.battery_state) {
      return false;
    }
    if (this->operating_mode != other.operating_mode) {
      return false;
    }
    if (this->errors != other.errors) {
      return false;
    }
    if (this->informations != other.informations) {
      return false;
    }
    if (this->safety_state != other.safety_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderState_

// alias to use template instance with default allocator
using OrderState =
  vda5050_msgs::msg::OrderState_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
OrderState_<ContainerAllocator>::AUTOMATIC = "AUTOMATIC";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
OrderState_<ContainerAllocator>::SEMIAUTOMATIC = "SEMIAUTOMATIC";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
OrderState_<ContainerAllocator>::MANUAL = "MANUAL";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
OrderState_<ContainerAllocator>::SERVICE = "SERVICE";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
OrderState_<ContainerAllocator>::TEACHIN = "TEACHIN";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__STRUCT_HPP_
