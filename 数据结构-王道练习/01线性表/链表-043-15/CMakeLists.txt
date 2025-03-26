cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project("判断链表是否有环")

## ------------------------------------------ basic-settings ----------------------------------------------

# 设置默认构建类型为 Debug
set(CMAKE_BUILD_TYPE Debug)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++20 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


## ------------------------------------------ files-settings ----------------------------------------------
# 添加源文件
file(GLOB SRC_DIR
    main.cpp
)


add_executable(test
    ${SRC_DIR}
)

# target_include_directories(test PUBLIC
#     include
# )
