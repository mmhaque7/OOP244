project(MS4)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(MS4
        ms4.cpp iProduct.h Product.cpp Product.h Utilities.h Utilities.cpp ErrorState.h ErrorState.cpp)