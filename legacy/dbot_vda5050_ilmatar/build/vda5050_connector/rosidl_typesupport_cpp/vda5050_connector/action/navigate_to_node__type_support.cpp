// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_connector:action/NavigateToNode.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_Goal_type_support_ids_t;

static const _NavigateToNode_Goal_type_support_ids_t _NavigateToNode_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_Goal_type_support_symbol_names_t _NavigateToNode_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_Goal)),
  }
};

typedef struct _NavigateToNode_Goal_type_support_data_t
{
  void * data[2];
} _NavigateToNode_Goal_type_support_data_t;

static _NavigateToNode_Goal_type_support_data_t _NavigateToNode_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_Goal_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_Goal_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Goal>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_Goal)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Goal>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_Result_type_support_ids_t;

static const _NavigateToNode_Result_type_support_ids_t _NavigateToNode_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_Result_type_support_symbol_names_t _NavigateToNode_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_Result)),
  }
};

typedef struct _NavigateToNode_Result_type_support_data_t
{
  void * data[2];
} _NavigateToNode_Result_type_support_data_t;

static _NavigateToNode_Result_type_support_data_t _NavigateToNode_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_Result_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_Result_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_Result_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_Result_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Result>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_Result)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Result>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_Feedback_type_support_ids_t;

static const _NavigateToNode_Feedback_type_support_ids_t _NavigateToNode_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_Feedback_type_support_symbol_names_t _NavigateToNode_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_Feedback)),
  }
};

typedef struct _NavigateToNode_Feedback_type_support_data_t
{
  void * data[2];
} _NavigateToNode_Feedback_type_support_data_t;

static _NavigateToNode_Feedback_type_support_data_t _NavigateToNode_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_Feedback_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_Feedback_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Feedback>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_Feedback)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_Feedback>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_SendGoal_Request_type_support_ids_t;

static const _NavigateToNode_SendGoal_Request_type_support_ids_t _NavigateToNode_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_SendGoal_Request_type_support_symbol_names_t _NavigateToNode_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Request)),
  }
};

typedef struct _NavigateToNode_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _NavigateToNode_SendGoal_Request_type_support_data_t;

static _NavigateToNode_SendGoal_Request_type_support_data_t _NavigateToNode_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_SendGoal_Request_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_SendGoal_Request_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal_Request>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Request)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal_Request>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_SendGoal_Response_type_support_ids_t;

static const _NavigateToNode_SendGoal_Response_type_support_ids_t _NavigateToNode_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_SendGoal_Response_type_support_symbol_names_t _NavigateToNode_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Response)),
  }
};

typedef struct _NavigateToNode_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _NavigateToNode_SendGoal_Response_type_support_data_t;

static _NavigateToNode_SendGoal_Response_type_support_data_t _NavigateToNode_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_SendGoal_Response_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_SendGoal_Response_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal_Response>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_SendGoal_Response)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_SendGoal_type_support_ids_t;

static const _NavigateToNode_SendGoal_type_support_ids_t _NavigateToNode_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_SendGoal_type_support_symbol_names_t _NavigateToNode_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_SendGoal)),
  }
};

typedef struct _NavigateToNode_SendGoal_type_support_data_t
{
  void * data[2];
} _NavigateToNode_SendGoal_type_support_data_t;

static _NavigateToNode_SendGoal_type_support_data_t _NavigateToNode_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_SendGoal_service_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t NavigateToNode_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_SendGoal_service_typesupport_map),
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
get_service_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<vda5050_connector::action::NavigateToNode_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_GetResult_Request_type_support_ids_t;

static const _NavigateToNode_GetResult_Request_type_support_ids_t _NavigateToNode_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_GetResult_Request_type_support_symbol_names_t _NavigateToNode_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_GetResult_Request)),
  }
};

typedef struct _NavigateToNode_GetResult_Request_type_support_data_t
{
  void * data[2];
} _NavigateToNode_GetResult_Request_type_support_data_t;

static _NavigateToNode_GetResult_Request_type_support_data_t _NavigateToNode_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_GetResult_Request_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_GetResult_Request_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult_Request>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_GetResult_Request)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult_Request>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_GetResult_Response_type_support_ids_t;

static const _NavigateToNode_GetResult_Response_type_support_ids_t _NavigateToNode_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_GetResult_Response_type_support_symbol_names_t _NavigateToNode_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_GetResult_Response)),
  }
};

typedef struct _NavigateToNode_GetResult_Response_type_support_data_t
{
  void * data[2];
} _NavigateToNode_GetResult_Response_type_support_data_t;

static _NavigateToNode_GetResult_Response_type_support_data_t _NavigateToNode_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_GetResult_Response_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_GetResult_Response_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult_Response>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_GetResult_Response)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult_Response>();
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
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_GetResult_type_support_ids_t;

static const _NavigateToNode_GetResult_type_support_ids_t _NavigateToNode_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_GetResult_type_support_symbol_names_t _NavigateToNode_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_GetResult)),
  }
};

typedef struct _NavigateToNode_GetResult_type_support_data_t
{
  void * data[2];
} _NavigateToNode_GetResult_type_support_data_t;

static _NavigateToNode_GetResult_type_support_data_t _NavigateToNode_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_GetResult_service_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t NavigateToNode_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_GetResult_service_typesupport_map),
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
get_service_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<vda5050_connector::action::NavigateToNode_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

typedef struct _NavigateToNode_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigateToNode_FeedbackMessage_type_support_ids_t;

static const _NavigateToNode_FeedbackMessage_type_support_ids_t _NavigateToNode_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _NavigateToNode_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigateToNode_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigateToNode_FeedbackMessage_type_support_symbol_names_t _NavigateToNode_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_connector, action, NavigateToNode_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_connector, action, NavigateToNode_FeedbackMessage)),
  }
};

typedef struct _NavigateToNode_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _NavigateToNode_FeedbackMessage_type_support_data_t;

static _NavigateToNode_FeedbackMessage_type_support_data_t _NavigateToNode_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigateToNode_FeedbackMessage_message_typesupport_map = {
  2,
  "vda5050_connector",
  &_NavigateToNode_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_NavigateToNode_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_NavigateToNode_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigateToNode_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigateToNode_FeedbackMessage_message_typesupport_map),
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
get_message_type_support_handle<vda5050_connector::action::NavigateToNode_FeedbackMessage>()
{
  return &::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode_FeedbackMessage)() {
  return get_message_type_support_handle<vda5050_connector::action::NavigateToNode_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
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

static rosidl_action_type_support_t NavigateToNode_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<vda5050_connector::action::NavigateToNode>()
{
  using ::vda5050_connector::action::rosidl_typesupport_cpp::NavigateToNode_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  NavigateToNode_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::vda5050_connector::action::NavigateToNode::Impl::SendGoalService>();
  NavigateToNode_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::vda5050_connector::action::NavigateToNode::Impl::GetResultService>();
  NavigateToNode_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::vda5050_connector::action::NavigateToNode::Impl::CancelGoalService>();
  NavigateToNode_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::vda5050_connector::action::NavigateToNode::Impl::FeedbackMessage>();
  NavigateToNode_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::vda5050_connector::action::NavigateToNode::Impl::GoalStatusMessage>();
  return &NavigateToNode_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, vda5050_connector, action, NavigateToNode)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<vda5050_connector::action::NavigateToNode>();
}

#ifdef __cplusplus
}
#endif
