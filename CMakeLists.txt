cmake_minimum_required(VERSION 3.14)
project(store)

set(CMAKE_CXX_STANDARD 14)

add_executable(store main.cpp node.h node.cpp table.cpp table.h index.cpp index.h json.hpp)