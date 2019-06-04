cmake_minimum_required(VERSION 3.14)
project(weightGenerator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(weightGenerator
        naloga2_2PRG2.cpp
        PersonWeight.cpp
        PersonWeight.h
        Date.cpp
        Date.h
        Person.cpp
        Person.h
        DayWeight.cpp
        DayWeight.h
        WeightTracker.cpp
        WeightTracker.h)
