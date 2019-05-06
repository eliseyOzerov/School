cmake_minimum_required(VERSION 3.14)
project(functionTemplates)

set(CMAKE_CXX_STANDARD 17)

add_executable(functionTemplates main.cpp templates.h Date.cpp Date.h)