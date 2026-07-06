// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_connector:action/ProcessVDAAction.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_Goal_type_support_ids_t;

static const _ProcessVDAAction_Goal_type_support_ids_t _ProcessVDAAction_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_Goal_type_support_symbol_names_t _ProcessVDAAction_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_Goal)),
  }
};

typedef struct _ProcessVDAAction_Goal_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_Goal_type_support_data_t;

static _ProcessVDAAction_Goal_type_support_data_t _ProcessVDAAction_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_Goal_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Goal>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_Goal)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_Result_type_support_ids_t;

static const _ProcessVDAAction_Result_type_support_ids_t _ProcessVDAAction_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_Result_type_support_symbol_names_t _ProcessVDAAction_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_Result)),
  }
};

typedef struct _ProcessVDAAction_Result_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_Result_type_support_data_t;

static _ProcessVDAAction_Result_type_support_data_t _ProcessVDAAction_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_Result_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_Result_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_Result_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Result>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_Result)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_Feedback_type_support_ids_t;

static const _ProcessVDAAction_Feedback_type_support_ids_t _ProcessVDAAction_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_Feedback_type_support_symbol_names_t _ProcessVDAAction_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_Feedback)),
  }
};

typedef struct _ProcessVDAAction_Feedback_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_Feedback_type_support_data_t;

static _ProcessVDAAction_Feedback_type_support_data_t _ProcessVDAAction_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_Feedback_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Feedback>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_Feedback)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_SendGoal_Request_type_support_ids_t;

static const _ProcessVDAAction_SendGoal_Request_type_support_ids_t _ProcessVDAAction_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_SendGoal_Request_type_support_symbol_names_t _ProcessVDAAction_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Request)),
  }
};

typedef struct _ProcessVDAAction_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_SendGoal_Request_type_support_data_t;

static _ProcessVDAAction_SendGoal_Request_type_support_data_t _ProcessVDAAction_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_SendGoal_Request_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal_Request>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Request)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_SendGoal_Response_type_support_ids_t;

static const _ProcessVDAAction_SendGoal_Response_type_support_ids_t _ProcessVDAAction_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_SendGoal_Response_type_support_symbol_names_t _ProcessVDAAction_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Response)),
  }
};

typedef struct _ProcessVDAAction_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_SendGoal_Response_type_support_data_t;

static _ProcessVDAAction_SendGoal_Response_type_support_data_t _ProcessVDAAction_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_SendGoal_Response_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal_Response>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal_Response)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_SendGoal_type_support_ids_t;

static const _ProcessVDAAction_SendGoal_type_support_ids_t _ProcessVDAAction_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_SendGoal_type_support_symbol_names_t _ProcessVDAAction_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal)),
  }
};

typedef struct _ProcessVDAAction_SendGoal_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_SendGoal_type_support_data_t;

static _ProcessVDAAction_SendGoal_type_support_data_t _ProcessVDAAction_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_SendGoal_service_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ProcessVDAAction_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<vda5050_connector::action::ProcessVDAAction_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_GetResult_Request_type_support_ids_t;

static const _ProcessVDAAction_GetResult_Request_type_support_ids_t _ProcessVDAAction_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_GetResult_Request_type_support_symbol_names_t _ProcessVDAAction_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Request)),
  }
};

typedef struct _ProcessVDAAction_GetResult_Request_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_GetResult_Request_type_support_data_t;

static _ProcessVDAAction_GetResult_Request_type_support_data_t _ProcessVDAAction_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_GetResult_Request_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult_Request>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Request)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_GetResult_Response_type_support_ids_t;

static const _ProcessVDAAction_GetResult_Response_type_support_ids_t _ProcessVDAAction_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_GetResult_Response_type_support_symbol_names_t _ProcessVDAAction_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Response)),
  }
};

typedef struct _ProcessVDAAction_GetResult_Response_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_GetResult_Response_type_support_data_t;

static _ProcessVDAAction_GetResult_Response_type_support_data_t _ProcessVDAAction_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_GetResult_Response_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult_Response>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_GetResult_Response)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_GetResult_type_support_ids_t;

static const _ProcessVDAAction_GetResult_type_support_ids_t _ProcessVDAAction_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_GetResult_type_support_symbol_names_t _ProcessVDAAction_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_GetResult)),
  }
};

typedef struct _ProcessVDAAction_GetResult_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_GetResult_type_support_data_t;

static _ProcessVDAAction_GetResult_type_support_data_t _ProcessVDAAction_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_GetResult_service_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ProcessVDAAction_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<vda5050_connector::action::ProcessVDAAction_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessVDAAction_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessVDAAction_FeedbackMessage_type_support_ids_t;

static const _ProcessVDAAction_FeedbackMessage_type_support_ids_t _ProcessVDAAction_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessVDAAction_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessVDAAction_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessVDAAction_FeedbackMessage_type_support_symbol_names_t _ProcessVDAAction_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, ProcessVDAAction_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, ProcessVDAAction_FeedbackMessage)),
  }
};

typedef struct _ProcessVDAAction_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _ProcessVDAAction_FeedbackMessage_type_support_data_t;

static _ProcessVDAAction_FeedbackMessage_type_support_data_t _ProcessVDAAction_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessVDAAction_FeedbackMessage_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_ProcessVDAAction_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessVDAAction_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessVDAAction_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessVDAAction_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessVDAAction_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_FeedbackMessage>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction_FeedbackMessage)() {
  return get_message_type_support_handle<vda5050_connector::action::ProcessVDAAction_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace vda5050_connector
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t ProcessVDAAction_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<vda5050_connector::action::ProcessVDAAction>()
{
  using ::vda5050_connector::action::rosidl_typesupport_cpp::ProcessVDAAction_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  ProcessVDAAction_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::vda5050_connector::action::ProcessVDAAction::Impl::SendGoalService>();
  ProcessVDAAction_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::vda5050_connector::action::ProcessVDAAction::Impl::GetResultService>();
  ProcessVDAAction_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::vda5050_connector::action::ProcessVDAAction::Impl::CancelGoalService>();
  ProcessVDAAction_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::vda5050_connector::action::ProcessVDAAction::Impl::FeedbackMessage>();
  ProcessVDAAction_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::vda5050_connector::action::ProcessVDAAction::Impl::GoalStatusMessage>();
  return &ProcessVDAAction_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, ProcessVDAAction)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<vda5050_connector::action::ProcessVDAAction>();
}

#ifdef __cplusplus
}
#endif
