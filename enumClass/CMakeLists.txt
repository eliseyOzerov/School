cmake_minimum_required(VERSION 3.13)
project(enumClass)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(enumClass
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
        main.cpp
        TimeClass.cpp
        TimeClass.h
        LectureEvent.cpp
        LectureEvent.h
        BirthdayEvent.cpp
        BirthdayEvent.h)
