cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project("判断AVL树")

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
file(GLOB SRC_FIR
    # "src/*.cpp"
    "main.cpp"
)

# set(INCLUDE_DIR
#     "include"
# )

add_executable(test
    ${SRC_FIR}
)

# target_include_directories(test PUBLIC
#     ${INCLUDE_DIR}
# )
