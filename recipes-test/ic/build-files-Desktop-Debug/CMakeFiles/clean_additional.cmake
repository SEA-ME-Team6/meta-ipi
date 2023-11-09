# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Instrument_Cluster_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Instrument_Cluster_autogen.dir/ParseCache.txt"
  "Instrument_Cluster_autogen"
  )
endif()
