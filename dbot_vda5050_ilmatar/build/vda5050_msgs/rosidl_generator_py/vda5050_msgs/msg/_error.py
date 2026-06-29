# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Error.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Error(type):
    """Metaclass of message 'Error'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'WARNING': 'WARNING',
        'FATAL': 'FATAL',
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vda5050_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_msgs.msg.Error')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__error
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__error
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__error
            cls._TYPE_SUPPORT = module.type_support_msg__msg__error
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__error

            from vda5050_msgs.msg import ErrorReference
            if ErrorReference.__class__._TYPE_SUPPORT is None:
                ErrorReference.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'WARNING': cls.__constants['WARNING'],
            'FATAL': cls.__constants['FATAL'],
        }

    @property
    def WARNING(self):
        """Message constant 'WARNING'."""
        return Metaclass_Error.__constants['WARNING']

    @property
    def FATAL(self):
        """Message constant 'FATAL'."""
        return Metaclass_Error.__constants['FATAL']


class Error(metaclass=Metaclass_Error):
    """
    Message class 'Error'.

    Constants:
      WARNING
      FATAL
    """

    __slots__ = [
        '_error_type',
        '_error_references',
        '_error_description',
        '_error_level',
    ]

    _fields_and_field_types = {
        'error_type': 'string',
        'error_references': 'sequence<vda5050_msgs/ErrorReference>',
        'error_description': 'string',
        'error_level': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'ErrorReference')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.error_type = kwargs.get('error_type', str())
        self.error_references = kwargs.get('error_references', [])
        self.error_description = kwargs.get('error_description', str())
        self.error_level = kwargs.get('error_level', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.error_type != other.error_type:
            return False
        if self.error_references != other.error_references:
            return False
        if self.error_description != other.error_description:
            return False
        if self.error_level != other.error_level:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def error_type(self):
        """Message field 'error_type'."""
        return self._error_type

    @error_type.setter
    def error_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_type' field must be of type 'str'"
        self._error_type = value

    @builtins.property
    def error_references(self):
        """Message field 'error_references'."""
        return self._error_references

    @error_references.setter
    def error_references(self, value):
        if __debug__:
            from vda5050_msgs.msg import ErrorReference
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, ErrorReference) for v in value) and
                 True), \
                "The 'error_references' field must be a set or sequence and each value of type 'ErrorReference'"
        self._error_references = value

    @builtins.property
    def error_description(self):
        """Message field 'error_description'."""
        return self._error_description

    @error_description.setter
    def error_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_description' field must be of type 'str'"
        self._error_description = value

    @builtins.property
    def error_level(self):
        """Message field 'error_level'."""
        return self._error_level

    @error_level.setter
    def error_level(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_level' field must be of type 'str'"
        self._error_level = value
