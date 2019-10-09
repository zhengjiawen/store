cmake_minimum_required(VERSION 3.15)
project(store)

set(CMAKE_CXX_STANDARD 14)

add_executable(store main.cpp node.h node.cpp)