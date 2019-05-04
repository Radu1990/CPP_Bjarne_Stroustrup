cmake_minimum_required(VERSION 3.14)

set(This google_test_project) # set name of library
project(This C CXX) # set name of project

set(CMAKE_CXX_STANDARD 11)

set(Headers Example.h)
set(Sources Example.cpp )

add_library(${This} STATIC ${Sources} ${Headers}) # linking Sources and Headers to our target library ${This}

add_subdirectory(googletest) # adding these subdirectories to check for cmake files there
add_subdirectory(test) # adding these subdirectories to check for cmake files there
