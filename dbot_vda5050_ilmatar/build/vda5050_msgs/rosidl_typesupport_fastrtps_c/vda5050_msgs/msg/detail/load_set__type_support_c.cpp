// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/load_set__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/load_set__struct.h"
#include "vda5050_msgs/msg/detail/load_set__functions.h"
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

#include "rosidl_runtime_c/string.h"  // description, load_positions, load_type, set_name
#include "rosidl_runtime_c/string_functions.h"  // description, load_positions, load_type, set_name
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


using _LoadSet__ros_msg_type = vda5050_msgs__msg__LoadSet;

static bool _LoadSet__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LoadSet__ros_msg_type * ros_message = static_cast<const _LoadSet__ros_msg_type *>(untyped_ros_message);
  // Field name: set_name
  {
    const rosidl_runtime_c__String * str = &ros_message->set_name;
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

  // Field name: load_positions
  {
    size_t size = ros_message->load_positions.size;
    auto array_ptr = ros_message->load_positions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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

  // Field name: max_weight
  {
    cdr << ros_message->max_weight;
  }

  // Field name: min_loadhandling_height
  {
    cdr << ros_message->min_loadhandling_height;
  }

  // Field name: max_loadhandling_height
  {
    cdr << ros_message->max_loadhandling_height;
  }

  // Field name: min_loadhandling_depth
  {
    cdr << ros_message->min_loadhandling_depth;
  }

  // Field name: max_loadhandling_depth
  {
    cdr << ros_message->max_loadhandling_depth;
  }

  // Field name: min_loadhandling_tilt
  {
    cdr << ros_message->min_loadhandling_tilt;
  }

  // Field name: max_loadhandling_tilt
  {
    cdr << ros_message->max_loadhandling_tilt;
  }

  // Field name: agv_speed_limit
  {
    cdr << ros_message->agv_speed_limit;
  }

  // Field name: agv_acceleration_limit
  {
    cdr << ros_message->agv_acceleration_limit;
  }

  // Field name: agv_deceleration_limit
  {
    cdr << ros_message->agv_deceleration_limit;
  }

  // Field name: pick_time
  {
    cdr << ros_message->pick_time;
  }

  // Field name: drop_time
  {
    cdr << ros_message->drop_time;
  }

  // Field name: description
  {
    const rosidl_runtime_c__String * str = &ros_message->description;
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

  return true;
}

static bool _LoadSet__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LoadSet__ros_msg_type * ros_message = static_cast<_LoadSet__ros_msg_type *>(untyped_ros_message);
  // Field name: set_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->set_name.data) {
      rosidl_runtime_c__String__init(&ros_message->set_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->set_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'set_name'\n");
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

  // Field name: load_positions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->load_positions.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->load_positions);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->load_positions, size)) {
      fprintf(stderr, "failed to create array for field 'load_positions'");
      return false;
    }
    auto array_ptr = ros_message->load_positions.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'load_positions'\n");
        return false;
      }
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

  // Field name: max_weight
  {
    cdr >> ros_message->max_weight;
  }

  // Field name: min_loadhandling_height
  {
    cdr >> ros_message->min_loadhandling_height;
  }

  // Field name: max_loadhandling_height
  {
    cdr >> ros_message->max_loadhandling_height;
  }

  // Field name: min_loadhandling_depth
  {
    cdr >> ros_message->min_loadhandling_depth;
  }

  // Field name: max_loadhandling_depth
  {
    cdr >> ros_message->max_loadhandling_depth;
  }

  // Field name: min_loadhandling_tilt
  {
    cdr >> ros_message->min_loadhandling_tilt;
  }

  // Field name: max_loadhandling_tilt
  {
    cdr >> ros_message->max_loadhandling_tilt;
  }

  // Field name: agv_speed_limit
  {
    cdr >> ros_message->agv_speed_limit;
  }

  // Field name: agv_acceleration_limit
  {
    cdr >> ros_message->agv_acceleration_limit;
  }

  // Field name: agv_deceleration_limit
  {
    cdr >> ros_message->agv_deceleration_limit;
  }

  // Field name: pick_time
  {
    cdr >> ros_message->pick_time;
  }

  // Field name: drop_time
  {
    cdr >> ros_message->drop_time;
  }

  // Field name: description
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->description.data) {
      rosidl_runtime_c__String__init(&ros_message->description);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->description,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'description'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__LoadSet(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LoadSet__ros_msg_type * ros_message = static_cast<const _LoadSet__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name set_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->set_name.size + 1);
  // field.name load_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->load_type.size + 1);
  // field.name load_positions
  {
    size_t array_size = ros_message->load_positions.size;
    auto array_ptr = ros_message->load_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name bounding_box_reference

  current_alignment += get_serialized_size_vda5050_msgs__msg__BoundingBoxReference(
    &(ros_message->bounding_box_reference), current_alignment);
  // field.name load_dimensions

  current_alignment += get_serialized_size_vda5050_msgs__msg__LoadDimensions(
    &(ros_message->load_dimensions), current_alignment);
  // field.name max_weight
  {
    size_t item_size = sizeof(ros_message->max_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_loadhandling_height
  {
    size_t item_size = sizeof(ros_message->min_loadhandling_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_loadhandling_height
  {
    size_t item_size = sizeof(ros_message->max_loadhandling_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_loadhandling_depth
  {
    size_t item_size = sizeof(ros_message->min_loadhandling_depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_loadhandling_depth
  {
    size_t item_size = sizeof(ros_message->max_loadhandling_depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_loadhandling_tilt
  {
    size_t item_size = sizeof(ros_message->min_loadhandling_tilt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_loadhandling_tilt
  {
    size_t item_size = sizeof(ros_message->max_loadhandling_tilt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name agv_speed_limit
  {
    size_t item_size = sizeof(ros_message->agv_speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name agv_acceleration_limit
  {
    size_t item_size = sizeof(ros_message->agv_acceleration_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name agv_deceleration_limit
  {
    size_t item_size = sizeof(ros_message->agv_deceleration_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pick_time
  {
    size_t item_size = sizeof(ros_message->pick_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop_time
  {
    size_t item_size = sizeof(ros_message->drop_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name description
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->description.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _LoadSet__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__LoadSet(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__LoadSet(
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

  // member: set_name
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
  // member: load_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

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
  // member: max_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: min_loadhandling_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_loadhandling_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: min_loadhandling_depth
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_loadhandling_depth
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: min_loadhandling_tilt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_loadhandling_tilt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: agv_speed_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: agv_acceleration_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: agv_deceleration_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pick_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: drop_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: description
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__LoadSet;
    is_plain =
      (
      offsetof(DataType, description) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LoadSet__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__LoadSet(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LoadSet = {
  "vda5050_msgs::msg",
  "LoadSet",
  _LoadSet__cdr_serialize,
  _LoadSet__cdr_deserialize,
  _LoadSet__get_serialized_size,
  _LoadSet__max_serialized_size
};

static rosidl_message_type_support_t _LoadSet__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LoadSet,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, LoadSet)() {
  return &_LoadSet__type_support;
}

#if defined(__cplusplus)
}
#endif
