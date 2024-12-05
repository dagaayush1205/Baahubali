#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "armvone::armvone" for configuration "Release"
set_property(TARGET armvone::armvone APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(armvone::armvone PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/codegen/dll/armvone/armvone.so"
  IMPORTED_SONAME_RELEASE "armvone.so"
  )

list(APPEND _cmake_import_check_targets armvone::armvone )
list(APPEND _cmake_import_check_files_for_armvone::armvone "${_IMPORT_PREFIX}/codegen/dll/armvone/armvone.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
