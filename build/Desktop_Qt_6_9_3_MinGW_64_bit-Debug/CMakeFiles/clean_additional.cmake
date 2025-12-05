# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LabS8_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LabS8_autogen.dir\\ParseCache.txt"
  "labs8_autogen"
  )
endif()
