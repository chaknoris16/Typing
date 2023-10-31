cmake_minimum_required(VERSION 3.14)
project(Typing)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/RATATYPE-C)

add_subdirectory(src/RATATYPE-C)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
