
cmake_minimum_required(VERSION 3.21)
project(Typing)
set(BUILD_TEST_LIBRARY ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(src/TypingTrainer)

add_subdirectory(src/TypingTrainer)

if (BUILD_TEST_LIBRARY)
 add_subdirectory(tests)
endif ()
