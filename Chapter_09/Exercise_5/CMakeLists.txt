cmake_minimum_required(VERSION 3.14)

set (This ex5)
project(This C CXX)

set(CMAKE_CXX_STANDARD 11)

set (Headers ex5.h)
set (Sources ex5.cpp)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(googletest)
add_subdirectory(tests)
