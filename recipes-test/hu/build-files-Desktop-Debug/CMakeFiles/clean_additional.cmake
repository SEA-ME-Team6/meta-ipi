# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Head_Unit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Head_Unit_autogen.dir/ParseCache.txt"
  "Head_Unit_autogen"
  )
endif()
