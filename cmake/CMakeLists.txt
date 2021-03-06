cmake_minimum_required(VERSION 2.8)

project(sandbox)

# Use folder in solution filters
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Setup output dirs
set(INCLUDE_DIR             ${CMAKE_SOURCE_DIR}/../source)
set(SOURCE_DIR              ${CMAKE_SOURCE_DIR}/../source)
set(EXT_DIR                 ${CMAKE_SOURCE_DIR}/../ext)
set(CMAKE_BINARY_DIR        ${CMAKE_SOURCE_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR})

# Enable c++17
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

# Detect platform
if(WIN32)
    set(PLATFORM_WINDOWS=true)
    add_definitions(-DPLATFORM_WINDOWS)
endif(WIN32)

# Global include dirs
include_directories("${INCLUDE_DIR}")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


# Setup projects
add_subdirectory("${EXT_DIR}/googletest"    googltest)
add_subdirectory("${SOURCE_DIR}/common"     common)
add_subdirectory("${SOURCE_DIR}/tests"      tests)
add_subdirectory("${SOURCE_DIR}/main"       main)

