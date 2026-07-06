// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/load__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/load__struct.h"
#include "vda5050_msgs/msg/detail/load__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // load_id, load_position, load_type
#include "rosidl_runtime_c/string_functions.h"  // load_id, load_position, load_type
#include "vda5050_msgs/msg/detail/bounding_box_reference__functions.h"  // bounding_box_reference
#include "vda5050_msgs/msg/detail/load_dimensions__functions.h"  // load_dimensions

// forward declare type support functions
size_t get_serialized_size_vda5050_msgs__msg__BoundingBoxReference(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_vda5050_msgs__msg__BoundingBoxReference(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, BoundingBoxReference)();
size_t get_serialized_size_vda5050_msgs__msg__LoadDimensions(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_vda5050_msgs__msg__LoadDimensions(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, LoadDimensions)();


using _Load__ros_msg_type = vda5050_msgs__msg__Load;

static bool _Load__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Load__ros_msg_type * ros_message = static_cast<const _Load__ros_msg_type *>(untyped_ros_message);
  // Field name: load_id
  {
    const rosidl_runtime_c__String * str = &ros_message->load_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: load_type
  {
    const rosidl_runtime_c__String * str = &ros_message->load_type;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: load_position
  {
    const rosidl_runtime_c__String * str = &ros_message->load_position;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounding_box_reference
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, BoundingBoxReference
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->bounding_box_reference, cdr))
    {
      return false;
    }
  }

  // Field name: load_dimensions
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, LoadDimensions
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->load_dimensions, cdr))
    {
      return false;
    }
  }

  // Field name: weight
  {
    cdr << ros_message->weight;
  }

  return true;
}

static bool _Load__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Load__ros_msg_type * ros_message = static_cast<_Load__ros_msg_type *>(untyped_ros_message);
  // Field name: load_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->load_id.data) {
      rosidl_runtime_c__String__init(&ros_message->load_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->load_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'load_id'\n");
      return false;
    }
  }

  // Field name: load_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->load_type.data) {
      rosidl_runtime_c__String__init(&ros_message->load_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->load_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'load_type'\n");
      return false;
    }
  }

  // Field name: load_position
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->load_position.data) {
      rosidl_runtime_c__String__init(&ros_message->load_position);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->load_position,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'load_position'\n");
      return false;
    }
  }

  // Field name: bounding_box_reference
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, BoundingBoxReference
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->bounding_box_reference))
    {
      return false;
    }
  }

  // Field name: load_dimensions
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, LoadDimensions
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->load_dimensions))
    {
      return false;
    }
  }

  // Field name: weight
  {
    cdr >> ros_message->weight;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__Load(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Load__ros_msg_type * ros_message = static_cast<const _Load__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name load_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->load_id.size + 1);
  // field.name load_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->load_type.size + 1);
  // field.name load_position
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->load_position.size + 1);
  // field.name bounding_box_reference

  current_alignment += get_serialized_size_vda5050_msgs__msg__BoundingBoxReference(
    &(ros_message->bounding_box_reference), current_alignment);
  // field.name load_dimensions

  current_alignment += get_serialized_size_vda5050_msgs__msg__LoadDimensions(
    &(ros_message->load_dimensions), current_alignment);
  // field.name weight
  {
    size_t item_size = sizeof(ros_message->weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Load__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__Load(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__Load(
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

  // member: load_id
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
  // member: load_type
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
  // member: load_position
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
  // member: bounding_box_reference
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vda5050_msgs__msg__BoundingBoxReference(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: load_dimensions
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vda5050_msgs__msg__LoadDimensions(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__Load;
    is_plain =
      (
      offsetof(DataType, weight) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Load__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__Load(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Load = {
  "vda5050_msgs::msg",
  "Load",
  _Load__cdr_serialize,
  _Load__cdr_deserialize,
  _Load__get_serialized_size,
  _Load__max_serialized_size
};

static rosidl_message_type_support_t _Load__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Load,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, Load)() {
  return &_Load__type_support;
}

#if defined(__cplusplus)
}
#endif
