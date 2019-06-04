cmake_minimum_required(VERSION 3.14)
project(kMeans)

set(CMAKE_CXX_STANDARD 14)

add_executable(kMeans main.cpp
        kMeans.cpp
        kMeans.h)