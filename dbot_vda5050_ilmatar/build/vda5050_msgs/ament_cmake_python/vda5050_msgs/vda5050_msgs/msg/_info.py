# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Info.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Info(type):
    """Metaclass of message 'Info'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DEBUG': 'DEBUG',
        'INFO': 'INFO',
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
                'vda5050_msgs.msg.Info')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__info

            from vda5050_msgs.msg import InfoReference
            if InfoReference.__class__._TYPE_SUPPORT is None:
                InfoReference.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DEBUG': cls.__constants['DEBUG'],
            'INFO': cls.__constants['INFO'],
        }

    @property
    def DEBUG(self):
        """Message constant 'DEBUG'."""
        return Metaclass_Info.__constants['DEBUG']

    @property
    def INFO(self):
        """Message constant 'INFO'."""
        return Metaclass_Info.__constants['INFO']


class Info(metaclass=Metaclass_Info):
    """
    Message class 'Info'.

    Constants:
      DEBUG
      INFO
    """

    __slots__ = [
        '_info_type',
        '_info_references',
        '_info_description',
        '_info_level',
    ]

    _fields_and_field_types = {
        'info_type': 'string',
        'info_references': 'sequence<vda5050_msgs/InfoReference>',
        'info_description': 'string',
        'info_level': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'InfoReference')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.info_type = kwargs.get('info_type', str())
        self.info_references = kwargs.get('info_references', [])
        self.info_description = kwargs.get('info_description', str())
        self.info_level = kwargs.get('info_level', str())

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
        if self.info_type != other.info_type:
            return False
        if self.info_references != other.info_references:
            return False
        if self.info_description != other.info_description:
            return False
        if self.info_level != other.info_level:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info_type(self):
        """Message field 'info_type'."""
        return self._info_type

    @info_type.setter
    def info_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'info_type' field must be of type 'str'"
        self._info_type = value

    @builtins.property
    def info_references(self):
        """Message field 'info_references'."""
        return self._info_references

    @info_references.setter
    def info_references(self, value):
        if __debug__:
            from vda5050_msgs.msg import InfoReference
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
                 all(isinstance(v, InfoReference) for v in value) and
                 True), \
                "The 'info_references' field must be a set or sequence and each value of type 'InfoReference'"
        self._info_references = value

    @builtins.property
    def info_description(self):
        """Message field 'info_description'."""
        return self._info_description

    @info_description.setter
    def info_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'info_description' field must be of type 'str'"
        self._info_description = value

    @builtins.property
    def info_level(self):
        """Message field 'info_level'."""
        return self._info_level

    @info_level.setter
    def info_level(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'info_level' field must be of type 'str'"
        self._info_level = value
