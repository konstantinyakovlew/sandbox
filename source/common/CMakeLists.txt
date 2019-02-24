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

set(SRC_LOGS_EXT
	logs/log_stdout_win.hpp
	logs/log_stdout_win.cpp
)

source_group("src\\utils"   FILES ${SRC_UTILS})
source_group("src\\logs"    FILES ${SRC_LOGS} ${SRC_LOGS_EXT})

set(SOURCES
    ${SRC_UTILS}
    ${SRC_LOGS}
	${SRC_LOGS_EXT}
)

add_library(common STATIC ${SOURCES})
