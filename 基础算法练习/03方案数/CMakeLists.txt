cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(COMMON)

# 设置默认构建类型为 Debug
set(CMAKE_BUILD_TYPE Debug)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-std=c++20)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/std:c++20)
endif()


# 添加源文件
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)

add_executable(test.out
    ${SRC_SUB}
    ${SRC_CUR}
)

target_include_directories(test.out PUBLIC
    include
)