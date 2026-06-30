// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/Timing.idl
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
#include "vda5050_msgs/msg/detail/timing__struct.h"
#include "vda5050_msgs/msg/detail/timing__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__timing__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
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
    assert(strncmp("vda5050_msgs.msg._timing.Timing", full_classname_dest, 31) == 0);
  }
  vda5050_msgs__msg__Timing * ros_message = _ros_message;
  {  // min_order_interval
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_order_interval");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_order_interval = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_state_interval
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_state_interval");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_state_interval = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // default_state_interval
    PyObject * field = PyObject_GetAttrString(_pymsg, "default_state_interval");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->default_state_interval = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // visualization_interval
    PyObject * field = PyObject_GetAttrString(_pymsg, "visualization_interval");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->visualization_interval = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__timing__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Timing */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._timing");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Timing");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__Timing * ros_message = (vda5050_msgs__msg__Timing *)raw_ros_message;
  {  // min_order_interval
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_order_interval);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_order_interval", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_state_interval
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_state_interval);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_state_interval", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // default_state_interval
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->default_state_interval);
    {
      int rc = PyObject_SetAttrString(_pymessage, "default_state_interval", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // visualization_interval
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->visualization_interval);
    {
      int rc = PyObject_SetAttrString(_pymessage, "visualization_interval", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
