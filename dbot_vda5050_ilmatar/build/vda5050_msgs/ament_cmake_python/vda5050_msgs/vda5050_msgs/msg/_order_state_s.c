// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "vda5050_msgs/msg/detail/order_state__struct.h"
#include "vda5050_msgs/msg/detail/order_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "vda5050_msgs/msg/detail/current_action__functions.h"
#include "vda5050_msgs/msg/detail/edge_state__functions.h"
#include "vda5050_msgs/msg/detail/error__functions.h"
#include "vda5050_msgs/msg/detail/info__functions.h"
#include "vda5050_msgs/msg/detail/load__functions.h"
#include "vda5050_msgs/msg/detail/node_state__functions.h"
// end nested array functions include
bool vda5050_msgs__msg__node_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__node_state__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__edge_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__edge_state__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__agv_position__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__agv_position__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__velocity__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__velocity__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__load__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__load__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__current_action__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__current_action__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__battery_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__battery_state__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__error__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__error__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__info__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__safety_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__safety_state__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__order_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vda5050_msgs.msg._order_state.OrderState", full_classname_dest, 40) == 0);
  }
  vda5050_msgs__msg__OrderState * ros_message = _ros_message;
  {  // header_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "header_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->header_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->timestamp, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->version, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // manufacturer
    PyObject * field = PyObject_GetAttrString(_pymsg, "manufacturer");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->manufacturer, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // serial_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "serial_number");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->serial_number, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // order_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->order_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // order_update_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_update_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->order_update_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // zone_set_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_set_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->zone_set_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // last_node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_node_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->last_node_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // last_node_sequence_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_node_sequence_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_node_sequence_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // node_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_states");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'node_states'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__NodeState__Sequence__init(&(ros_message->node_states), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__NodeState__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__NodeState * dest = ros_message->node_states.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__node_state__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // edge_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "edge_states");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'edge_states'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__EdgeState__Sequence__init(&(ros_message->edge_states), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__EdgeState__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__EdgeState * dest = ros_message->edge_states.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__edge_state__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // agv_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "agv_position");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__agv_position__convert_from_py(field, &ros_message->agv_position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__velocity__convert_from_py(field, &ros_message->velocity)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // loads
    PyObject * field = PyObject_GetAttrString(_pymsg, "loads");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'loads'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__Load__Sequence__init(&(ros_message->loads), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__Load__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__Load * dest = ros_message->loads.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__load__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // driving
    PyObject * field = PyObject_GetAttrString(_pymsg, "driving");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->driving = (Py_True == field);
    Py_DECREF(field);
  }
  {  // paused
    PyObject * field = PyObject_GetAttrString(_pymsg, "paused");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->paused = (Py_True == field);
    Py_DECREF(field);
  }
  {  // new_base_request
    PyObject * field = PyObject_GetAttrString(_pymsg, "new_base_request");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->new_base_request = (Py_True == field);
    Py_DECREF(field);
  }
  {  // distance_since_last_node
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_since_last_node");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_since_last_node = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // action_states
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_states");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'action_states'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__CurrentAction__Sequence__init(&(ros_message->action_states), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__CurrentAction__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__CurrentAction * dest = ros_message->action_states.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__current_action__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // battery_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_state");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__battery_state__convert_from_py(field, &ros_message->battery_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // operating_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "operating_mode");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->operating_mode, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // errors
    PyObject * field = PyObject_GetAttrString(_pymsg, "errors");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'errors'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__Error__Sequence__init(&(ros_message->errors), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__Error__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__Error * dest = ros_message->errors.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__error__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // informations
    PyObject * field = PyObject_GetAttrString(_pymsg, "informations");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'informations'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vda5050_msgs__msg__Info__Sequence__init(&(ros_message->informations), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__Info__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__Info * dest = ros_message->informations.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__info__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // safety_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "safety_state");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__safety_state__convert_from_py(field, &ros_message->safety_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__order_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OrderState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._order_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OrderState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__OrderState * ros_message = (vda5050_msgs__msg__OrderState *)raw_ros_message;
  {  // header_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->header_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "header_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->timestamp.data,
      strlen(ros_message->timestamp.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // version
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->version.data,
      strlen(ros_message->version.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manufacturer
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->manufacturer.data,
      strlen(ros_message->manufacturer.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "manufacturer", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // serial_number
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->serial_number.data,
      strlen(ros_message->serial_number.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "serial_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // order_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->order_id.data,
      strlen(ros_message->order_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // order_update_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->order_update_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_update_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_set_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->zone_set_id.data,
      strlen(ros_message->zone_set_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_set_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_node_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->last_node_id.data,
      strlen(ros_message->last_node_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_node_sequence_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->last_node_sequence_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_node_sequence_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_states
    PyObject * field = NULL;
    size_t size = ros_message->node_states.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__NodeState * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->node_states.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__node_state__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // edge_states
    PyObject * field = NULL;
    size_t size = ros_message->edge_states.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__EdgeState * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->edge_states.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__edge_state__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "edge_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agv_position
    PyObject * field = NULL;
    field = vda5050_msgs__msg__agv_position__convert_to_py(&ros_message->agv_position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "agv_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity
    PyObject * field = NULL;
    field = vda5050_msgs__msg__velocity__convert_to_py(&ros_message->velocity);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // loads
    PyObject * field = NULL;
    size_t size = ros_message->loads.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__Load * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->loads.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__load__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "loads", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // driving
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->driving ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "driving", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // paused
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->paused ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "paused", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // new_base_request
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->new_base_request ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "new_base_request", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_since_last_node
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_since_last_node);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_since_last_node", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // action_states
    PyObject * field = NULL;
    size_t size = ros_message->action_states.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__CurrentAction * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->action_states.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__current_action__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_states", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_state
    PyObject * field = NULL;
    field = vda5050_msgs__msg__battery_state__convert_to_py(&ros_message->battery_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // operating_mode
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->operating_mode.data,
      strlen(ros_message->operating_mode.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "operating_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // errors
    PyObject * field = NULL;
    size_t size = ros_message->errors.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__Error * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->errors.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__error__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "errors", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // informations
    PyObject * field = NULL;
    size_t size = ros_message->informations.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__Info * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->informations.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__info__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "informations", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safety_state
    PyObject * field = NULL;
    field = vda5050_msgs__msg__safety_state__convert_to_py(&ros_message->safety_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "safety_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
