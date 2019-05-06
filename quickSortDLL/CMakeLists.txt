cmake_minimum_required(VERSION 3.14)
project(quickSortDLL)

set(CMAKE_CXX_STANDARD 17)

add_executable(quickSortDLL main.cpp Node.cpp Node.h DLL.cpp DLL.h)