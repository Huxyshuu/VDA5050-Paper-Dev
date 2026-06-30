// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
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
#include "vda5050_msgs/msg/detail/physical_parameters__struct.h"
#include "vda5050_msgs/msg/detail/physical_parameters__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vda5050_msgs__msg__physical_parameters__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
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
    assert(strncmp("vda5050_msgs.msg._physical_parameters.PhysicalParameters", full_classname_dest, 56) == 0);
  }
  vda5050_msgs__msg__PhysicalParameters * ros_message = _ros_message;
  {  // speed_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // acceleration_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "acceleration_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acceleration_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // deceleration_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "deceleration_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->deceleration_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // height_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "height_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height_min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // height_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "height_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height_max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // width
    PyObject * field = PyObject_GetAttrString(_pymsg, "width");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->width = PyFloat_AS_DOUBLE(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vda5050_msgs__msg__physical_parameters__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PhysicalParameters */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vda5050_msgs.msg._physical_parameters");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PhysicalParameters");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vda5050_msgs__msg__PhysicalParameters * ros_message = (vda5050_msgs__msg__PhysicalParameters *)raw_ros_message;
  {  // speed_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acceleration_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acceleration_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acceleration_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deceleration_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->deceleration_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "deceleration_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // width
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "width", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
