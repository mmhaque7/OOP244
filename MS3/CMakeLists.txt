project(MS3)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS2
        ms3.cpp Product.cpp Product.h ErrorState.cpp ErrorState.h Utilities.cpp Utilities.h)