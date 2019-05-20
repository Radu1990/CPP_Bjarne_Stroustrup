cmake_minimum_required(VERSION 3.14)

set (This Customizing_io)
project(This C CXX)

set(CMAKE_CXX_STANDARD 11)

set(Headers nonstandard_op.h)
set(Sources nonstandard_op.cpp)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(googletest)
add_subdirectory(tests)