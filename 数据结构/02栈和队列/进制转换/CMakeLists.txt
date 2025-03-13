cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

project(进制转换)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC
  "src/*.cpp"
  "main.cpp"
)

file(GLOB INCLUDE_DIRS
  "include"
)

add_executable(test.out ${SRC})
target_include_directories(test.out PRIVATE ${INCLUDE_DIRS})
