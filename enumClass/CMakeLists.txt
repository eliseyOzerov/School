cmake_minimum_required(VERSION 3.13)
project(compositionAndAggregation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(compositionAndAggregation
        Calendar.cpp
        Calendar.h
        Date.cpp
        Date.h
        DateTime.cpp
        DateTime.h
        Event.cpp
        Event.h
        MeetingEvent.cpp
        MeetingEvent.h
        enumClassMain.cpp
        Time.cpp
        Time.h)
