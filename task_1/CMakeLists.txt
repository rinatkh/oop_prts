cmake_minimum_required(VERSION 3.21)
project(HW)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW main.cpp src/parser.cpp)
target_include_directories(HW PUBLIC include)