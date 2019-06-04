cmake_minimum_required(VERSION 3.14)

set (This Drill)
project(This C CXX)

set(CMAKE_CXX_STANDARD 11)

set(Headers vector_free_store.h)
set(Sources vector_free_store.cpp)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(googletest)
add_subdirectory(tests)