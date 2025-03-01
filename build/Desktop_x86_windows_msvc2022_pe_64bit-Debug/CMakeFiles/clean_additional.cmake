# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\excel_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\excel_autogen.dir\\ParseCache.txt"
  "excel_autogen"
  )
endif()
