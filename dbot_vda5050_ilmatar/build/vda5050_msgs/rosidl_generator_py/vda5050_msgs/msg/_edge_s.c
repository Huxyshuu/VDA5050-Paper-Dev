// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/Edge.idl
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
#include "vda5050_msgs/msg/detail/edge__struct.h"
#include "vda5050_msgs/msg/detail/edge__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "vda5050_msgs/msg/detail/action__functions.h"
// end nested array functions include
bool vda5050_msgs__msg__trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__trajectory__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__action__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__action__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__edge__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
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
    assert(strncmp("vda5050_msgs.msg._edge.Edge", full_classname_dest, 27) == 0);
  }
  vda5050_msgs__msg__Edge * ros_message = _ros_message;
  {  // edge_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "edge_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->edge_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // sequence_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "sequence_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sequence_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // edge_description
    PyObject * field = PyObject_GetAttrString(_pymsg, "edge_description");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->edge_description, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // released
    PyObject * field = PyObject_GetAttrString(_pymsg, "released");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->released = (Py_True == field);
    Py_DECREF(field);
  }
  {  // start_node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_node_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->start_node_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // end_node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_node_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->end_node_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // max_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "direction");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->direction, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rotation_allowed
    PyObject * field = PyObject_GetAttrString(_pymsg, "rotation_allowed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rotation_allowed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // max_rotation_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_rotation_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_rotation_speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__trajectory__convert_from_py(field, &ros_message->trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // length
    PyObject * field = PyObject_GetAttrString(_pymsg, "length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // actions
    PyObject * field = PyObject_GetAttrString(_pymsg, "actions");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'actions'");
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
    if (!vda5050_msgs__msg__Action__Sequence__init(&(ros_message->actions), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vda5050_msgs__msg__Action__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vda5050_msgs__msg__Action * dest = ros_message->actions.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vda5050_msgs__msg__action__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__edge__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Edge */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._edge");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Edge");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__Edge * ros_message = (vda5050_msgs__msg__Edge *)raw_ros_message;
  {  // edge_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->edge_id.data,
      strlen(ros_message->edge_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "edge_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sequence_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sequence_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sequence_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // edge_description
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->edge_description.data,
      strlen(ros_message->edge_description.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "edge_description", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // released
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->released ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "released", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_node_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->start_node_id.data,
      strlen(ros_message->start_node_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_node_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->end_node_id.data,
      strlen(ros_message->end_node_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // direction
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->direction.data,
      strlen(ros_message->direction.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rotation_allowed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rotation_allowed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rotation_allowed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_rotation_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_rotation_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_rotation_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectory
    PyObject * field = NULL;
    field = vda5050_msgs__msg__trajectory__convert_to_py(&ros_message->trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // actions
    PyObject * field = NULL;
    size_t size = ros_message->actions.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vda5050_msgs__msg__Action * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->actions.data[i]);
      PyObject * pyitem = vda5050_msgs__msg__action__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "actions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
