// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/AGVPosition.idl
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
#include "vda5050_msgs/msg/detail/agv_position__struct.h"
#include "vda5050_msgs/msg/detail/agv_position__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__agv_position__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("vda5050_msgs.msg._agv_position.AGVPosition", full_classname_dest, 42) == 0);
  }
  vda5050_msgs__msg__AGVPosition * ros_message = _ros_message;
  {  // position_initialized
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_initialized");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->position_initialized = (Py_True == field);
    Py_DECREF(field);
  }
  {  // localization_score
    PyObject * field = PyObject_GetAttrString(_pymsg, "localization_score");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->localization_score = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // deviation_range
    PyObject * field = PyObject_GetAttrString(_pymsg, "deviation_range");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->deviation_range = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // map_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "map_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->map_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // map_description
    PyObject * field = PyObject_GetAttrString(_pymsg, "map_description");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->map_description, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__agv_position__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AGVPosition */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._agv_position");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AGVPosition");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__AGVPosition * ros_message = (vda5050_msgs__msg__AGVPosition *)raw_ros_message;
  {  // position_initialized
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->position_initialized ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_initialized", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // localization_score
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->localization_score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "localization_score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deviation_range
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->deviation_range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "deviation_range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // map_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->map_id.data,
      strlen(ros_message->map_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "map_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // map_description
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->map_description.data,
      strlen(ros_message->map_description.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "map_description", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
