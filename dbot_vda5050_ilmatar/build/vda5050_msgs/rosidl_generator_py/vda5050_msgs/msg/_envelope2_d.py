# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Envelope2D.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Envelope2D(type):
    """Metaclass of message 'Envelope2D'."""

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
                'vda5050_msgs.msg.Envelope2D')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__envelope2_d
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__envelope2_d
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__envelope2_d
            cls._TYPE_SUPPORT = module.type_support_msg__msg__envelope2_d
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__envelope2_d

            from vda5050_msgs.msg import PolygonPoint
            if PolygonPoint.__class__._TYPE_SUPPORT is None:
                PolygonPoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Envelope2D(metaclass=Metaclass_Envelope2D):
    """Message class 'Envelope2D'."""

    __slots__ = [
        '_set',
        '_polygon_points',
        '_description',
    ]

    _fields_and_field_types = {
        'set': 'string',
        'polygon_points': 'sequence<vda5050_msgs/PolygonPoint>',
        'description': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'PolygonPoint')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.set = kwargs.get('set', str())
        self.polygon_points = kwargs.get('polygon_points', [])
        self.description = kwargs.get('description', str())

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
        if self.set != other.set:
            return False
        if self.polygon_points != other.polygon_points:
            return False
        if self.description != other.description:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def set(self):  # noqa: A003
        """Message field 'set'."""
        return self._set

    @set.setter  # noqa: A003
    def set(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'set' field must be of type 'str'"
        self._set = value

    @builtins.property
    def polygon_points(self):
        """Message field 'polygon_points'."""
        return self._polygon_points

    @polygon_points.setter
    def polygon_points(self, value):
        if __debug__:
            from vda5050_msgs.msg import PolygonPoint
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
                 all(isinstance(v, PolygonPoint) for v in value) and
                 True), \
                "The 'polygon_points' field must be a set or sequence and each value of type 'PolygonPoint'"
        self._polygon_points = value

    @builtins.property
    def description(self):
        """Message field 'description'."""
        return self._description

    @description.setter
    def description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'description' field must be of type 'str'"
        self._description = value
