cmake_minimum_required(VERSION 3.16)
project(PathFinder C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(libmx/inc)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "inc/*.h")
file(GLOB_RECURSE LIB RELATIVE ${CMAKE_SOURCE_DIR} "libmx/src/*.c")
file(GLOB_RECURSE LIB_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "libmx/inc/*.h")

add_executable(PathFinder main.c ${SOURCES} ${LIB} ${HEADERS} ${LIB_HEADERS})
