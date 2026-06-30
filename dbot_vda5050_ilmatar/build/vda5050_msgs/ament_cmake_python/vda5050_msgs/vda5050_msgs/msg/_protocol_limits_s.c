// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
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
#include "vda5050_msgs/msg/detail/protocol_limits__struct.h"
#include "vda5050_msgs/msg/detail/protocol_limits__functions.h"

bool vda5050_msgs__msg__max_string_lens__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__max_string_lens__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__max_array_lens__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__max_array_lens__convert_to_py(void * raw_ros_message);
bool vda5050_msgs__msg__timing__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vda5050_msgs__msg__timing__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__protocol_limits__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("vda5050_msgs.msg._protocol_limits.ProtocolLimits", full_classname_dest, 48) == 0);
  }
  vda5050_msgs__msg__ProtocolLimits * ros_message = _ros_message;
  {  // max_string_lens
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_string_lens");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__max_string_lens__convert_from_py(field, &ros_message->max_string_lens)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // max_array_lens
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_array_lens");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__max_array_lens__convert_from_py(field, &ros_message->max_array_lens)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // timing
    PyObject * field = PyObject_GetAttrString(_pymsg, "timing");
    if (!field) {
      return false;
    }
    if (!vda5050_msgs__msg__timing__convert_from_py(field, &ros_message->timing)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__protocol_limits__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ProtocolLimits */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._protocol_limits");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ProtocolLimits");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__ProtocolLimits * ros_message = (vda5050_msgs__msg__ProtocolLimits *)raw_ros_message;
  {  // max_string_lens
    PyObject * field = NULL;
    field = vda5050_msgs__msg__max_string_lens__convert_to_py(&ros_message->max_string_lens);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_string_lens", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_array_lens
    PyObject * field = NULL;
    field = vda5050_msgs__msg__max_array_lens__convert_to_py(&ros_message->max_array_lens);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_array_lens", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timing
    PyObject * field = NULL;
    field = vda5050_msgs__msg__timing__convert_to_py(&ros_message->timing);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "timing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
