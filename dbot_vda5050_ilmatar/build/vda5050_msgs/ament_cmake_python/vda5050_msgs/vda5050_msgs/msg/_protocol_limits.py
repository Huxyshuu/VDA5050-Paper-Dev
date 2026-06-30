# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/ProtocolLimits.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ProtocolLimits(type):
    """Metaclass of message 'ProtocolLimits'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'vda5050_msgs.msg.ProtocolLimits')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__protocol_limits
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__protocol_limits
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__protocol_limits
            cls._TYPE_SUPPORT = module.type_support_msg__msg__protocol_limits
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__protocol_limits

            from vda5050_msgs.msg import MaxArrayLens
            if MaxArrayLens.__class__._TYPE_SUPPORT is None:
                MaxArrayLens.__class__.__import_type_support__()

            from vda5050_msgs.msg import MaxStringLens
            if MaxStringLens.__class__._TYPE_SUPPORT is None:
                MaxStringLens.__class__.__import_type_support__()

            from vda5050_msgs.msg import Timing
            if Timing.__class__._TYPE_SUPPORT is None:
                Timing.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProtocolLimits(metaclass=Metaclass_ProtocolLimits):
    """Message class 'ProtocolLimits'."""

    __slots__ = [
        '_max_string_lens',
        '_max_array_lens',
        '_timing',
    ]

    _fields_and_field_types = {
        'max_string_lens': 'vda5050_msgs/MaxStringLens',
        'max_array_lens': 'vda5050_msgs/MaxArrayLens',
        'timing': 'vda5050_msgs/Timing',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'MaxStringLens'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'MaxArrayLens'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Timing'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from vda5050_msgs.msg import MaxStringLens
        self.max_string_lens = kwargs.get('max_string_lens', MaxStringLens())
        from vda5050_msgs.msg import MaxArrayLens
        self.max_array_lens = kwargs.get('max_array_lens', MaxArrayLens())
        from vda5050_msgs.msg import Timing
        self.timing = kwargs.get('timing', Timing())

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
        if self.max_string_lens != other.max_string_lens:
            return False
        if self.max_array_lens != other.max_array_lens:
            return False
        if self.timing != other.timing:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def max_string_lens(self):
        """Message field 'max_string_lens'."""
        return self._max_string_lens

    @max_string_lens.setter
    def max_string_lens(self, value):
        if __debug__:
            from vda5050_msgs.msg import MaxStringLens
            assert \
                isinstance(value, MaxStringLens), \
                "The 'max_string_lens' field must be a sub message of type 'MaxStringLens'"
        self._max_string_lens = value

    @builtins.property
    def max_array_lens(self):
        """Message field 'max_array_lens'."""
        return self._max_array_lens

    @max_array_lens.setter
    def max_array_lens(self, value):
        if __debug__:
            from vda5050_msgs.msg import MaxArrayLens
            assert \
                isinstance(value, MaxArrayLens), \
                "The 'max_array_lens' field must be a sub message of type 'MaxArrayLens'"
        self._max_array_lens = value

    @builtins.property
    def timing(self):
        """Message field 'timing'."""
        return self._timing

    @timing.setter
    def timing(self, value):
        if __debug__:
            from vda5050_msgs.msg import Timing
            assert \
                isinstance(value, Timing), \
                "The 'timing' field must be a sub message of type 'Timing'"
        self._timing = value
