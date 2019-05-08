cmake_minimum_required(VERSION 3.13)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(milestone_1
        ms1.cpp
        Date.cpp
        Date.h

        )