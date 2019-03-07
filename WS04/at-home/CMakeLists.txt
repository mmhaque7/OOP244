cmake_minimum_required(VERSION 3.13)
project(at_home)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(at_home
        Traveler.cpp
        Traveler.h
        w4_at_home.cpp)
