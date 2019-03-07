cmake_minimum_required(VERSION 3.13)
project(in_lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(in_lab
        Fraction.cpp
        Fraction.h
        w5_in_lab.cpp)