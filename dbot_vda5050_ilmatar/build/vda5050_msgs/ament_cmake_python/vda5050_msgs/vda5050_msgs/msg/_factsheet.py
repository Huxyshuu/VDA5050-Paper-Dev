# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Factsheet.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Factsheet(type):
    """Metaclass of message 'Factsheet'."""

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
                'vda5050_msgs.msg.Factsheet')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__factsheet
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__factsheet
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__factsheet
            cls._TYPE_SUPPORT = module.type_support_msg__msg__factsheet
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__factsheet

            from vda5050_msgs.msg import AGVGeometry
            if AGVGeometry.__class__._TYPE_SUPPORT is None:
                AGVGeometry.__class__.__import_type_support__()

            from vda5050_msgs.msg import LoadSpecification
            if LoadSpecification.__class__._TYPE_SUPPORT is None:
                LoadSpecification.__class__.__import_type_support__()

            from vda5050_msgs.msg import PhysicalParameters
            if PhysicalParameters.__class__._TYPE_SUPPORT is None:
                PhysicalParameters.__class__.__import_type_support__()

            from vda5050_msgs.msg import ProtocolFeatures
            if ProtocolFeatures.__class__._TYPE_SUPPORT is None:
                ProtocolFeatures.__class__.__import_type_support__()

            from vda5050_msgs.msg import ProtocolLimits
            if ProtocolLimits.__class__._TYPE_SUPPORT is None:
                ProtocolLimits.__class__.__import_type_support__()

            from vda5050_msgs.msg import TypeSpecification
            if TypeSpecification.__class__._TYPE_SUPPORT is None:
                TypeSpecification.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Factsheet(metaclass=Metaclass_Factsheet):
    """Message class 'Factsheet'."""

    __slots__ = [
        '_header_id',
        '_timestamp',
        '_version',
        '_manufacturer',
        '_serial_number',
        '_type_specification',
        '_physical_parameters',
        '_protocol_limits',
        '_protocol_features',
        '_agv_geometry',
        '_load_specification',
        '_localization_parameters',
    ]

    _fields_and_field_types = {
        'header_id': 'uint32',
        'timestamp': 'string',
        'version': 'string',
        'manufacturer': 'string',
        'serial_number': 'string',
        'type_specification': 'vda5050_msgs/TypeSpecification',
        'physical_parameters': 'vda5050_msgs/PhysicalParameters',
        'protocol_limits': 'vda5050_msgs/ProtocolLimits',
        'protocol_features': 'vda5050_msgs/ProtocolFeatures',
        'agv_geometry': 'vda5050_msgs/AGVGeometry',
        'load_specification': 'vda5050_msgs/LoadSpecification',
        'localization_parameters': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'TypeSpecification'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'PhysicalParameters'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'ProtocolLimits'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'ProtocolFeatures'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'AGVGeometry'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'LoadSpecification'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        from vda5050_msgs.msg import TypeSpecification
        self.type_specification = kwargs.get('type_specification', TypeSpecification())
        from vda5050_msgs.msg import PhysicalParameters
        self.physical_parameters = kwargs.get('physical_parameters', PhysicalParameters())
        from vda5050_msgs.msg import ProtocolLimits
        self.protocol_limits = kwargs.get('protocol_limits', ProtocolLimits())
        from vda5050_msgs.msg import ProtocolFeatures
        self.protocol_features = kwargs.get('protocol_features', ProtocolFeatures())
        from vda5050_msgs.msg import AGVGeometry
        self.agv_geometry = kwargs.get('agv_geometry', AGVGeometry())
        from vda5050_msgs.msg import LoadSpecification
        self.load_specification = kwargs.get('load_specification', LoadSpecification())
        self.localization_parameters = kwargs.get('localization_parameters', int())

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
        if self.type_specification != other.type_specification:
            return False
        if self.physical_parameters != other.physical_parameters:
            return False
        if self.protocol_limits != other.protocol_limits:
            return False
        if self.protocol_features != other.protocol_features:
            return False
        if self.agv_geometry != other.agv_geometry:
            return False
        if self.load_specification != other.load_specification:
            return False
        if self.localization_parameters != other.localization_parameters:
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
    def type_specification(self):
        """Message field 'type_specification'."""
        return self._type_specification

    @type_specification.setter
    def type_specification(self, value):
        if __debug__:
            from vda5050_msgs.msg import TypeSpecification
            assert \
                isinstance(value, TypeSpecification), \
                "The 'type_specification' field must be a sub message of type 'TypeSpecification'"
        self._type_specification = value

    @builtins.property
    def physical_parameters(self):
        """Message field 'physical_parameters'."""
        return self._physical_parameters

    @physical_parameters.setter
    def physical_parameters(self, value):
        if __debug__:
            from vda5050_msgs.msg import PhysicalParameters
            assert \
                isinstance(value, PhysicalParameters), \
                "The 'physical_parameters' field must be a sub message of type 'PhysicalParameters'"
        self._physical_parameters = value

    @builtins.property
    def protocol_limits(self):
        """Message field 'protocol_limits'."""
        return self._protocol_limits

    @protocol_limits.setter
    def protocol_limits(self, value):
        if __debug__:
            from vda5050_msgs.msg import ProtocolLimits
            assert \
                isinstance(value, ProtocolLimits), \
                "The 'protocol_limits' field must be a sub message of type 'ProtocolLimits'"
        self._protocol_limits = value

    @builtins.property
    def protocol_features(self):
        """Message field 'protocol_features'."""
        return self._protocol_features

    @protocol_features.setter
    def protocol_features(self, value):
        if __debug__:
            from vda5050_msgs.msg import ProtocolFeatures
            assert \
                isinstance(value, ProtocolFeatures), \
                "The 'protocol_features' field must be a sub message of type 'ProtocolFeatures'"
        self._protocol_features = value

    @builtins.property
    def agv_geometry(self):
        """Message field 'agv_geometry'."""
        return self._agv_geometry

    @agv_geometry.setter
    def agv_geometry(self, value):
        if __debug__:
            from vda5050_msgs.msg import AGVGeometry
            assert \
                isinstance(value, AGVGeometry), \
                "The 'agv_geometry' field must be a sub message of type 'AGVGeometry'"
        self._agv_geometry = value

    @builtins.property
    def load_specification(self):
        """Message field 'load_specification'."""
        return self._load_specification

    @load_specification.setter
    def load_specification(self, value):
        if __debug__:
            from vda5050_msgs.msg import LoadSpecification
            assert \
                isinstance(value, LoadSpecification), \
                "The 'load_specification' field must be a sub message of type 'LoadSpecification'"
        self._load_specification = value

    @builtins.property
    def localization_parameters(self):
        """Message field 'localization_parameters'."""
        return self._localization_parameters

    @localization_parameters.setter
    def localization_parameters(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'localization_parameters' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'localization_parameters' field must be an integer in [-2147483648, 2147483647]"
        self._localization_parameters = value
