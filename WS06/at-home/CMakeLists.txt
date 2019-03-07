cmake_minimum_required(VERSION 3.13)
project(at_home)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(at_home
        w6_at_home.cpp
        Contact.h
        Contact.cpp
        )