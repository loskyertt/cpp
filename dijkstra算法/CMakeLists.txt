cmake_minimum_required(VERSION 3.10)
# 设置生产 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(PROJECT)
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(test ${SRC_SUB} ${SRC_CUR})
include_directories(include)
