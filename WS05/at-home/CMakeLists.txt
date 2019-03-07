cmake_minimum_required(VERSION 3.13)
project(in_lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(at_home
        Fraction.cpp
        Fraction.h
        w5_at_home.cpp)