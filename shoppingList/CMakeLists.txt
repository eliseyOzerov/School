cmake_minimum_required(VERSION 3.14)
project(shoppingList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(shoppingList
        Clothing.cpp
        Clothing.h
        naloga2_1PRG2.cpp
        WrongClothingSize.cpp
        WrongClothingSize.h
        InvalidPrice.h)
