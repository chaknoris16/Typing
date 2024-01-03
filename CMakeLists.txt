
cmake_minimum_required(VERSION 3.21)
project(Typing)
option(BUILD_TESTS "Build tests" OFF)
set(CMAKE_CXX_STANDARD 17)

include_directories(src/TypingTrainer)

add_subdirectory(src/TypingTrainer)

if (BUILD_TESTS)
 add_subdirectory(tests)
endif ()
