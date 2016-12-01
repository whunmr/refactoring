cmake_minimum_required(VERSION 3.3.2)
project(refactoring)

LINK_DIRECTORIES(/Users/hmwang/lab/repo/googletest/googlemock/gtest)
INCLUDE_DIRECTORIES(/Users/hmwang/lab/repo/googletest/googletest/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

file(GLOB_RECURSE SOURCE_FILES "*/*.cpp")

add_executable(refactoring ${SOURCE_FILES})
target_link_libraries(refactoring gtest gtest_main)

