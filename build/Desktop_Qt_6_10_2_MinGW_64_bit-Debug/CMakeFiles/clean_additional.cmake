# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qt-Calculator-GUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qt-Calculator-GUI_autogen.dir\\ParseCache.txt"
  "Qt-Calculator-GUI_autogen"
  )
endif()
