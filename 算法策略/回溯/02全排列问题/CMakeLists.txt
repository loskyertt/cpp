cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 设置默认构建类型为Debug
set(CMAKE_BUILD_TYPE Debug)
# 设置默认构建类型为Release
# set(CMAKE_BUILD_TYPE Release)

project(02全排列问题)
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(test.out ${SRC_SUB} ${SRC_CUR})
include_directories(include)
