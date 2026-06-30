# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Connection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Connection(type):
    """Metaclass of message 'Connection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'ONLINE': 'ONLINE',
        'OFFLINE': 'OFFLINE',
        'CONNECTIONBROKEN': 'CONNECTIONBROKEN',
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
                'vda5050_msgs.msg.Connection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__connection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__connection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__connection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__connection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__connection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ONLINE': cls.__constants['ONLINE'],
            'OFFLINE': cls.__constants['OFFLINE'],
            'CONNECTIONBROKEN': cls.__constants['CONNECTIONBROKEN'],
        }

    @property
    def ONLINE(self):
        """Message constant 'ONLINE'."""
        return Metaclass_Connection.__constants['ONLINE']

    @property
    def OFFLINE(self):
        """Message constant 'OFFLINE'."""
        return Metaclass_Connection.__constants['OFFLINE']

    @property
    def CONNECTIONBROKEN(self):
        """Message constant 'CONNECTIONBROKEN'."""
        return Metaclass_Connection.__constants['CONNECTIONBROKEN']


class Connection(metaclass=Metaclass_Connection):
    """
    Message class 'Connection'.

    Constants:
      ONLINE
      OFFLINE
      CONNECTIONBROKEN
    """

    __slots__ = [
        '_header_id',
        '_timestamp',
        '_version',
        '_manufacturer',
        '_serial_number',
        '_connection_state',
    ]

    _fields_and_field_types = {
        'header_id': 'uint32',
        'timestamp': 'string',
        'version': 'string',
        'manufacturer': 'string',
        'serial_number': 'string',
        'connection_state': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.header_id = kwargs.get('header_id', int())
        self.timestamp = kwargs.get('timestamp', str())
        self.version = kwargs.get('version', str())
        self.manufacturer = kwargs.get('manufacturer', str())
        self.serial_number = kwargs.get('serial_number', str())
        self.connection_state = kwargs.get('connection_state', str())

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
        if self.header_id != other.header_id:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.version != other.version:
            return False
        if self.manufacturer != other.manufacturer:
            return False
        if self.serial_number != other.serial_number:
            return False
        if self.connection_state != other.connection_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header_id(self):
        """Message field 'header_id'."""
        return self._header_id

    @header_id.setter
    def header_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'header_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'header_id' field must be an unsigned integer in [0, 4294967295]"
        self._header_id = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'timestamp' field must be of type 'str'"
        self._timestamp = value

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'version' field must be of type 'str'"
        self._version = value

    @builtins.property
    def manufacturer(self):
        """Message field 'manufacturer'."""
        return self._manufacturer

    @manufacturer.setter
    def manufacturer(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'manufacturer' field must be of type 'str'"
        self._manufacturer = value

    @builtins.property
    def serial_number(self):
        """Message field 'serial_number'."""
        return self._serial_number

    @serial_number.setter
    def serial_number(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'serial_number' field must be of type 'str'"
        self._serial_number = value

    @builtins.property
    def connection_state(self):
        """Message field 'connection_state'."""
        return self._connection_state

    @connection_state.setter
    def connection_state(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'connection_state' field must be of type 'str'"
        self._connection_state = value
