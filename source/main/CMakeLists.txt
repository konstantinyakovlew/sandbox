cmake_minimum_required(VERSION 2.8)

project(main)

set(SOURCES
    main.cpp
)

source_group("src" FILES ${SOURCES})

add_executable(main ${SOURCES})
target_link_libraries(main common)
