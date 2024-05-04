# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\TypingTrainer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TypingTrainer_autogen.dir\\ParseCache.txt"
  "TypingTrainer_autogen"
  )
endif()
