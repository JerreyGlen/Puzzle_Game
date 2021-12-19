# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Puzzle_Game_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Puzzle_Game_autogen.dir\\ParseCache.txt"
  "Puzzle_Game_autogen"
  )
endif()
