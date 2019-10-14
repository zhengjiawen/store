cmake_minimum_required(VERSION 3.14)
project(store)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
#set(CMAKE_CXX_STANDARD 17)

add_executable(store main.cpp node.h node.cpp table.cpp table.h index.cpp index.h)