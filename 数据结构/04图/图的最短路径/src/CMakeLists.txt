cmake_minimum_required(VERSION 3.10)

# 添加所有 .cpp 文件
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 递归查找头文件目录
set(PROJECT_INCLUDE
  "../include"
  "../include/Dijkstra"
  "../include/Floyd"
)

# 设置动态库的输出目录到项目根目录下的 lib/
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# 生成动态库
add_library(mygraph SHARED ${SRC_FILES})

# 让外部 CMakeLists.txt 也能找到头文件
target_include_directories(mygraph PUBLIC ${PROJECT_INCLUDE})
