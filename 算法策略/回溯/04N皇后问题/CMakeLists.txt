cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 设置默认构建类型为 Debug/Release
set(CMAKE_BUILD_TYPE Debug)
project(03N皇后问题)
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(test.out ${SRC_SUB} ${SRC_CUR})
target_include_directories(test.out PRIVATE include)
# include_directories(include)
