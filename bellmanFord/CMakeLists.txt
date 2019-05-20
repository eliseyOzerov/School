cmake_minimum_required(VERSION 3.14)
project(bellmanFord)

set(CMAKE_CXX_STANDARD 14)

add_executable(bellmanFord main.cpp BellmanFord.cpp BellmanFord.h)