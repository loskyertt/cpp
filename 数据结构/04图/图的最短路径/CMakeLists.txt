cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project("图的最短路径")

## ------------------------------------------ basic-settings ----------------------------------------------

# 设置默认构建类型为 Debug
set(CMAKE_BUILD_TYPE Debug)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++20 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)


## ------------------------------------------ files-settings ----------------------------------------------
# 添加源文件
file(GLOB PROJECT_SOURCES
    "src/*.cpp"
    "main.cpp"
)

# add_subdirectory(src)

set(PROJECT_INCLUDE
    "include"
    "include/Dijkstra"
    "include/Floyd"
)

add_executable(test
    ${PROJECT_SOURCES}
)

target_include_directories(test PUBLIC
    ${PROJECT_INCLUDE}
)

# target_link_libraries(test PRIVATE mygraph)
