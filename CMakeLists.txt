cmake_minimum_required(VERSION 3.16)
project(PathFinder C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
add_executable(PathFinder main.c src/error_handler/raise_error.c inc/error_handler.h src/error_handler/init_error.c src/base_handler/init_base.c inc/base_handler.h src/base_handler/get_file_size.c)