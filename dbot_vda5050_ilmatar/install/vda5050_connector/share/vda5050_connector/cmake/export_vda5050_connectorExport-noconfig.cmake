#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vda5050_connector::adapter" for configuration ""
set_property(TARGET vda5050_connector::adapter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(vda5050_connector::adapter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libadapter.so"
  IMPORTED_SONAME_NOCONFIG "libadapter.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS vda5050_connector::adapter )
list(APPEND _IMPORT_CHECK_FILES_FOR_vda5050_connector::adapter "${_IMPORT_PREFIX}/lib/libadapter.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
