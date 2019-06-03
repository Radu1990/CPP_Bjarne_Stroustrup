cmake_minimum_required(VERSION 3.14)

set (This Exercise_01)
project(This C CXX)

set(CMAKE_CXX_STANDARD 11)

set(Headers Exercise_01.h)
set(Sources Exercise_01.cpp)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(googletest)
add_subdirectory(tests)