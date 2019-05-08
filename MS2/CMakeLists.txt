project(MS2)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS2
        ms2.cpp
        ErrorState.cpp ErrorState.h)