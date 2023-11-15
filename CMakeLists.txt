
cmake_minimum_required(VERSION 3.21)
project(Typing)
set(BUILD_TEST_LIBRARY ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(src/RATATYPE-C)

add_subdirectory(src/RATATYPE-C)

if (BUILD_TEST_LIBRARY)
 add_subdirectory(tests)
 add_subdirectory(lib/googletest)
endif ()
