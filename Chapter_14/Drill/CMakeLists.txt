cmake_minimum_required(VERSION 3.14)

set (This Drill)
project(This C CXX)

set(CMAKE_CXX_STANDARD 11)

set(Headers drill.h)
set(Sources drill.cpp)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(googletest)
add_subdirectory(tests)