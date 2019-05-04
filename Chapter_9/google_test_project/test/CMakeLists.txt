cmake_minimum_required(VERSION 3.14)

set(This test) # giving name to this library

set(Sources basic_test.cpp) # setting source files

add_executable(${This} ${Sources}) # making exec from the given Sources with the name This

target_link_libraries(
        ${This} gtest_main google_test_project # linking to this test the lib from the main folder and the gtest lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
