cmake_minimum_required(VERSION 3.13)
project(fp)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp Chap2.cpp Chap2_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
