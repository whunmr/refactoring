cmake_minimum_required(VERSION 3.6)
project(refactoring)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES "*.cpp")

add_executable(refactoring ${SOURCE_FILES})