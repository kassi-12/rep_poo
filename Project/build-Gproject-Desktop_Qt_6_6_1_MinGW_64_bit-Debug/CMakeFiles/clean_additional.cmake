# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Gproject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Gproject_autogen.dir\\ParseCache.txt"
  "Gproject_autogen"
  )
endif()
