# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/MaxStringLens.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MaxStringLens(type):
    """Metaclass of message 'MaxStringLens'."""

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
                'vda5050_msgs.msg.MaxStringLens')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__max_string_lens
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__max_string_lens
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__max_string_lens
            cls._TYPE_SUPPORT = module.type_support_msg__msg__max_string_lens
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__max_string_lens

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MaxStringLens(metaclass=Metaclass_MaxStringLens):
    """Message class 'MaxStringLens'."""

    __slots__ = [
        '_msg_len',
        '_topic_serial_len',
        '_topic_elem_len',
        '_id_len',
        '_id_numerical_only',
        '_enum_len',
        '_load_id_len',
    ]

    _fields_and_field_types = {
        'msg_len': 'uint32',
        'topic_serial_len': 'uint32',
        'topic_elem_len': 'uint32',
        'id_len': 'uint32',
        'id_numerical_only': 'boolean',
        'enum_len': 'uint32',
        'load_id_len': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.msg_len = kwargs.get('msg_len', int())
        self.topic_serial_len = kwargs.get('topic_serial_len', int())
        self.topic_elem_len = kwargs.get('topic_elem_len', int())
        self.id_len = kwargs.get('id_len', int())
        self.id_numerical_only = kwargs.get('id_numerical_only', bool())
        self.enum_len = kwargs.get('enum_len', int())
        self.load_id_len = kwargs.get('load_id_len', int())

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
        if self.msg_len != other.msg_len:
            return False
        if self.topic_serial_len != other.topic_serial_len:
            return False
        if self.topic_elem_len != other.topic_elem_len:
            return False
        if self.id_len != other.id_len:
            return False
        if self.id_numerical_only != other.id_numerical_only:
            return False
        if self.enum_len != other.enum_len:
            return False
        if self.load_id_len != other.load_id_len:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def msg_len(self):
        """Message field 'msg_len'."""
        return self._msg_len

    @msg_len.setter
    def msg_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'msg_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'msg_len' field must be an unsigned integer in [0, 4294967295]"
        self._msg_len = value

    @builtins.property
    def topic_serial_len(self):
        """Message field 'topic_serial_len'."""
        return self._topic_serial_len

    @topic_serial_len.setter
    def topic_serial_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'topic_serial_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'topic_serial_len' field must be an unsigned integer in [0, 4294967295]"
        self._topic_serial_len = value

    @builtins.property
    def topic_elem_len(self):
        """Message field 'topic_elem_len'."""
        return self._topic_elem_len

    @topic_elem_len.setter
    def topic_elem_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'topic_elem_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'topic_elem_len' field must be an unsigned integer in [0, 4294967295]"
        self._topic_elem_len = value

    @builtins.property
    def id_len(self):
        """Message field 'id_len'."""
        return self._id_len

    @id_len.setter
    def id_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'id_len' field must be an unsigned integer in [0, 4294967295]"
        self._id_len = value

    @builtins.property
    def id_numerical_only(self):
        """Message field 'id_numerical_only'."""
        return self._id_numerical_only

    @id_numerical_only.setter
    def id_numerical_only(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'id_numerical_only' field must be of type 'bool'"
        self._id_numerical_only = value

    @builtins.property
    def enum_len(self):
        """Message field 'enum_len'."""
        return self._enum_len

    @enum_len.setter
    def enum_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enum_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'enum_len' field must be an unsigned integer in [0, 4294967295]"
        self._enum_len = value

    @builtins.property
    def load_id_len(self):
        """Message field 'load_id_len'."""
        return self._load_id_len

    @load_id_len.setter
    def load_id_len(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'load_id_len' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'load_id_len' field must be an unsigned integer in [0, 4294967295]"
        self._load_id_len = value
