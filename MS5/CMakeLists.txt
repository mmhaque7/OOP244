project(MS5)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(MS5
        Perishable.cpp Perishable.h AmaApp.cpp AmaApp.h ErrorState.cpp ErrorState.h Date.h Date.cpp Product.cpp
        Product.h Utilities.cpp Utilities.h ms5.cpp iProduct.h )