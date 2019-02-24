cmake_minimum_required(VERSION 2.8)

project(tests)

set(SOURCES
    tests.cpp
)

source_group("src" FILES ${SOURCES})

add_executable(tests ${SOURCES})
target_link_libraries(tests common gtest_main)
