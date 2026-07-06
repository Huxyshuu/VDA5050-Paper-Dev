"""Additional definitions for ZLAC8015D object dictionary to make the code readable"""
import logging
import canopen

OD_DESCRIPTIONS = {
    # (index, subindex): description
    (0x6040,): "Controlword for controlling state machine"
}

OD_VALUE_DESCRIPTIONS = {
    # (index, subindex): {value: description}
    (0x2002,): {
        0: "256000 bps",
        1: "128000 bps",
        2: "115200 bps",
        3: "57600 bps",
        4: "34800 bps",
        5: "19200 bps",
        6: "9600 bps",
    },
    (0x2006,): {0: "invalid", 1: "left", 2: "right", 3: "both"},
    (0x200B,): {
        0: "1000 Kbit/s",
        1: "500 Kbit/s",
        2: "250 Kbit/s",
        3: "125 Kbit/s",
        4: "100 Kbit/s",
    },
    (0x200F,): {0: "async", 1: "sync"},
    (0x2030, 2): {0: "undefined", 1: "emergency stop signal"},
    (0x2030, 3): {0: "undefined", 1: "emergency stop signal"},
    (0x2030, 5): {
        0: "undefined",
        1: "alarm signal",
        2: "driver status signal",
        3: "signal in place (reserved)",
    },
    (0x2030, 6): {
        0: "undefined",
        1: "alarm signal",
        2: "driver status signal",
        3: "signal in place (reserved)",
    },
    (0x2030, 7): {0: "open", 1: "close"},
    (0x2030, 8): {0: "open", 1: "close"},
    (0x2034, 1): {0: "hall error", 7: "hall error"},
    (0x2034, 2): {0: "hall error", 7: "hall error"},
    (0x605A,): {
        0x0005: "Stop normally, maintain quick stop status",
        0x0006: "Decelerate to stop emergencely and maintain quick stop state",
        0x0007: "Emergency stop, maintain quick stop state",
    },
    (0x605B,): {
        0x0000: "Invalid",
        0x0001: "Stop normally, go to ready to switch on state",
    },
    (0x605C,): {
        0x0000: "Invalid",
        0x0001: "Stop normally, switch to switched on state",
    },
    (0x605D,): {
        0x0001: "Stop normally, switch to operation enabeled state",
        0x0002: "Decelerate to stop emergencely and maintain operation enabled state",
        0x0003: "Emergency stop, maintain operation enabled state",
    },
}

OD_BIT_DEFINITIONS = {
    # (index, subindex): {name: bits}
    (0x2003,): {"X0": [0], "X1": [1]},
    (0x2004,): {"Y0": [0], "Y1": [1], "B0": [2], "B1": [3]},
    (0x2005,): {"right": range(8), "left": range(8, 16)},
    (0x2030, 1): {"X0": [0], "X1": [1]},
    (0x2030, 4): {"Y0": [0], "Y1": [1], "B0": [2], "B1": [3]},
    (0x6040,): {
        "New set-point": [4],
        "Change set immediately": [5],
        "Relative": [6],
        "Halt": [8],
    },
    # (0x6041,): {
    #     "right": range(16),
    #     "left": range(16, 32),
    #     # Right motor
    #     "Torque attained (right)": [8],
    #     "Target reached (right)": [10],
    #     "Speed (right)": [12],
    #     "Set-point acknowledge (right)": [12],
    #     "Pend (right)": [15],
    #     # Left motor
    #     "Torque attained (left)": [8 + 16],
    #     "Target reached (left)": [10 + 16],
    #     "Speed (left)": [12 + 16],
    #     "Set-point acknowledge (left)": [12 + 16],
    #     "Pend (left)": [15 + 16],
    # },
    (0x606C, 3): {"right": range(16), "left": range(16, 32)},
    (0x6071, 3): {"left": range(16), "right": range(16, 32)},
    (0x6077, 3): {"left": range(16), "right": range(16, 32)},
    (0x60FF, 3): {"left": range(16), "right": range(16, 32)},
}

OD_FACTORS_AND_UNITS = {
    # (index, subindex): (factor, unit)
    (0x2000,): (1, "ms"),
    (0x2008,): (1, "r/min"),
    (0x200D, 1): (1, "r/min"),
    (0x200D, 2): (1, "r/min"),
    (0x2011, 1): (1, "\N{DEGREE SIGN}"),
    (0x2011, 2): (1, "\N{DEGREE SIGN}"),
    (0x2012, 1): (1, "%"),
    (0x2012, 2): (1, "%"),
    (0x2013, 1): (0.1, "\N{DEGREE SIGN}C"),
    (0x2013, 2): (0.1, "\N{DEGREE SIGN}C"),
    (0x2014, 1): (0.1, "A"),
    (0x2014, 2): (0.1, "A"),
    (0x2015, 1): (0.1, "A"),
    (0x2015, 2): (0.1, "A"),
    (0x2016, 1): (10, "ms"),
    (0x2016, 2): (10, "ms"),
    (0x2017, 1): (10, "counts"),
    (0x2017, 2): (10, "counts"),
    (0x2032, 1): (0.1, "\N{DEGREE SIGN}C"),
    (0x2032, 2): (0.1, "\N{DEGREE SIGN}C"),
    (0x2032, 3): (0.1, "\N{DEGREE SIGN}C"),
    (0x2035,): (0.01, "V"),
    (0x6064, 1): (1, "count"),
    (0x6064, 2): (-1, "count"),
    (0x606C, 1): (0.1, "r/min"),
    (0x606C, 2): (-0.1, "r/min"),
    (0x606C, 3): (0.1, "r/min"),
    (0x6071, 1): (1, "mA"),
    (0x6071, 2): (1, "mA"),
    (0x6071, 3): (1, "mA"),
    (0x6077, 1): (0.1, "A"),
    (0x6077, 2): (0.1, "A"),
    (0x6077, 3): (0.1, "A"),
    (0x607A, 1): (1, "counts"),
    (0x607A, 2): (-1, "counts"),
    (0x6081, 1): (1, "r/min"),
    (0x6081, 2): (1, "r/min"),
    (0x6083, 1): (1, "ms"),
    (0x6083, 2): (1, "ms"),
    (0x6084, 1): (1, "ms"),
    (0x6084, 2): (1, "ms"),
    (0x6087, 1): (1, "mA/s"),
    (0x6087, 2): (1, "mA/s"),
    (0x60FF, 1): (1, "r/min"),
    (0x60FF, 2): (-1, "r/min"),
    # (0x60FF, 3): (1, "r/min"),
}

ERROR_FLAGS = {
    # Error flag bits for 0x603F
    0x0000: "No error",
    0x0001: "Over-voltage",
    0x0002: "Under-voltage",
    0x0004: "Over-current (left)",
    0x0004 << 16: "Over-current (right)",
    0x0008: "Overload (left)",
    0x0008 << 16: "Overload (right)",
    0x0010: "Current out of tolerance (left)",
    0x0010 << 16: "Current out of tolerance (right)",
    0x0020: "Encoder out of tolerance (left)",
    0x0020 << 16: "Encoder out of tolerance (right)",
    0x0040: "Velocity out of tolerance (left)",
    0x0040 << 16: "Velocity out of tolerance (right)",
    0x0080: "Reference voltage error (left)",
    0x0080 << 16: "Reference voltage error (right)",
    0x0100: "EEPROM read and write error",
    0x0200: "Hall error (left)",
    0x0200 << 16: "Hall error (right)",
}


def add_od_descriptions(
    object_dictionary: canopen.ObjectDictionary, descriptions: dict
):
    """Add descriptions to object dictionary entries.

    Args:
        object_dictionary (canopen.ObjectDictionary): The object dictionary.
        descriptions (dict): Dictionary with OD index as key, description as value.
    """
    for index, desc in descriptions.items():
        obj = object_dictionary.get_variable(*index)

        if obj is not None:
            obj.description = desc
        else:
            logging.warning(
                "Object at index %#Xsub%02X not found in object dictionary. Can't add description.",
                index[0],
                index[1],
            )


def add_od_value_descriptions(
    object_dictionary: canopen.ObjectDictionary, value_descriptions: dict
):
    """Add descriptions for specific values to the object dictionary.

    Args:
        object_dictionary (canopen.ObjectDictionary): The object dictionary.
        value_descriptions (dict): Dictionary with index as key, and dictionary of value: description as the value.
    """
    for index, descriptions in value_descriptions.items():
        var = object_dictionary.get_variable(*index)

        if var is not None:
            for value, description in descriptions.items():
                var.add_value_description(value, description)
        else:
            logging.warning(
                "Object at index %#Xsub%02X not found in object dictionary. Can't add value description.",
                index[0],
                index[1],
            )


def add_od_bit_definitions(
    object_dictionary: canopen.ObjectDictionary, bit_definitions: dict
):
    """Add definitions for specific bits of a value to the object dictionary.

    Args:
        object_dictionary (canopen.ObjectDictionary): The object dictionary.
        bit_definitions (dict): Dictionary with index as key, and dictionary of definition: bit(s) as the value
    """
    for index, definitions in bit_definitions.items():
        var = object_dictionary.get_variable(*index)

        if var is not None:
            for definition, bits in definitions.items():
                var.add_bit_definition(definition, bits)
        else:
            logging.warning(
                "Object at index %#Xsub%02X not found in object dictionary. Can't add bit definitions.",
                index[0],
                index[1],
            )


def add_od_factors_and_units(
    object_dictionary: canopen.ObjectDictionary, factors_and_units: dict
):
    """Add factor and unit to object dictionary entries.

    Args:
        object_dictionary (canopen.ObjectDictionary): The object dictionary.
        factors_and_units (dict): Dictionary with index as key, tuple of factor and unit as value.
    """
    for index, factor_and_unit in factors_and_units.items():
        var = object_dictionary.get_variable(*index)

        if var is not None:
            var.factor, var.unit = factor_and_unit
        else:
            logging.warning(
                "Object at index %#Xsub%02X not found in object dictionary. Can't add factors and units.",
                index[0],
                index[1],
            )
