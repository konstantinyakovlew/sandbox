cmake_minimum_required(VERSION 2.8)

project(common)

set(SRC_UTILS
    utils/singleton.hpp
)

set(SRC_LOGS
    logs/log.hpp
    logs/log.cpp
    logs/log_stdout.hpp
    logs/log_stdout.cpp
)

source_group("src\\utils"   FILES ${SRC_UTILS})
source_group("src\\logs"    FILES ${SRC_LOGS})

set(SOURCES
    ${SRC_UTILS}
    ${SRC_LOGS}
)

add_library(common STATIC ${SOURCES})
