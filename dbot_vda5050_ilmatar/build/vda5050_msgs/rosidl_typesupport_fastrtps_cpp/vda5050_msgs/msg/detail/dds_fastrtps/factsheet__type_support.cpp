// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/factsheet__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vda5050_msgs/msg/detail/factsheet__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::TypeSpecification &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::TypeSpecification &);
size_t get_serialized_size(
  const vda5050_msgs::msg::TypeSpecification &,
  size_t current_alignment);
size_t
max_serialized_size_TypeSpecification(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::PhysicalParameters &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::PhysicalParameters &);
size_t get_serialized_size(
  const vda5050_msgs::msg::PhysicalParameters &,
  size_t current_alignment);
size_t
max_serialized_size_PhysicalParameters(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::ProtocolLimits &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::ProtocolLimits &);
size_t get_serialized_size(
  const vda5050_msgs::msg::ProtocolLimits &,
  size_t current_alignment);
size_t
max_serialized_size_ProtocolLimits(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::ProtocolFeatures &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::ProtocolFeatures &);
size_t get_serialized_size(
  const vda5050_msgs::msg::ProtocolFeatures &,
  size_t current_alignment);
size_t
max_serialized_size_ProtocolFeatures(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::AGVGeometry &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::AGVGeometry &);
size_t get_serialized_size(
  const vda5050_msgs::msg::AGVGeometry &,
  size_t current_alignment);
size_t
max_serialized_size_AGVGeometry(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::LoadSpecification &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::LoadSpecification &);
size_t get_serialized_size(
  const vda5050_msgs::msg::LoadSpecification &,
  size_t current_alignment);
size_t
max_serialized_size_LoadSpecification(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs


namespace vda5050_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_serialize(
  const vda5050_msgs::msg::Factsheet & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header_id
  cdr << ros_message.header_id;
  // Member: timestamp
  cdr << ros_message.timestamp;
  // Member: version
  cdr << ros_message.version;
  // Member: manufacturer
  cdr << ros_message.manufacturer;
  // Member: serial_number
  cdr << ros_message.serial_number;
  // Member: type_specification
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.type_specification,
    cdr);
  // Member: physical_parameters
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.physical_parameters,
    cdr);
  // Member: protocol_limits
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.protocol_limits,
    cdr);
  // Member: protocol_features
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.protocol_features,
    cdr);
  // Member: agv_geometry
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.agv_geometry,
    cdr);
  // Member: load_specification
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.load_specification,
    cdr);
  // Member: localization_parameters
  cdr << ros_message.localization_parameters;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vda5050_msgs::msg::Factsheet & ros_message)
{
  // Member: header_id
  cdr >> ros_message.header_id;

  // Member: timestamp
  cdr >> ros_message.timestamp;

  // Member: version
  cdr >> ros_message.version;

  // Member: manufacturer
  cdr >> ros_message.manufacturer;

  // Member: serial_number
  cdr >> ros_message.serial_number;

  // Member: type_specification
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.type_specification);

  // Member: physical_parameters
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.physical_parameters);

  // Member: protocol_limits
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.protocol_limits);

  // Member: protocol_features
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.protocol_features);

  // Member: agv_geometry
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.agv_geometry);

  // Member: load_specification
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.load_specification);

  // Member: localization_parameters
  cdr >> ros_message.localization_parameters;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
get_serialized_size(
  const vda5050_msgs::msg::Factsheet & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header_id
  {
    size_t item_size = sizeof(ros_message.header_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: timestamp
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.timestamp.size() + 1);
  // Member: version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.version.size() + 1);
  // Member: manufacturer
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.manufacturer.size() + 1);
  // Member: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.serial_number.size() + 1);
  // Member: type_specification

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.type_specification, current_alignment);
  // Member: physical_parameters

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.physical_parameters, current_alignment);
  // Member: protocol_limits

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.protocol_limits, current_alignment);
  // Member: protocol_features

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.protocol_features, current_alignment);
  // Member: agv_geometry

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.agv_geometry, current_alignment);
  // Member: load_specification

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.load_specification, current_alignment);
  // Member: localization_parameters
  {
    size_t item_size = sizeof(ros_message.localization_parameters);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
max_serialized_size_Factsheet(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: timestamp
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: version
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: manufacturer
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: serial_number
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: type_specification
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_TypeSpecification(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: physical_parameters
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_PhysicalParameters(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: protocol_limits
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ProtocolLimits(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: protocol_features
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ProtocolFeatures(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: agv_geometry
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_AGVGeometry(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: load_specification
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_LoadSpecification(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: localization_parameters
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs::msg::Factsheet;
    is_plain =
      (
      offsetof(DataType, localization_parameters) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Factsheet__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::Factsheet *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Factsheet__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vda5050_msgs::msg::Factsheet *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Factsheet__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::Factsheet *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Factsheet__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Factsheet(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Factsheet__callbacks = {
  "vda5050_msgs::msg",
  "Factsheet",
  _Factsheet__cdr_serialize,
  _Factsheet__cdr_deserialize,
  _Factsheet__get_serialized_size,
  _Factsheet__max_serialized_size
};

static rosidl_message_type_support_t _Factsheet__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Factsheet__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vda5050_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_msgs::msg::Factsheet>()
{
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_Factsheet__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_msgs, msg, Factsheet)() {
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_Factsheet__handle;
}

#ifdef __cplusplus
}
#endif
