cmake_minimum_required(VERSION 3.13)
project(kmpSearch)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(kmpSearch main.cpp TextFile.cpp TextFile.h)