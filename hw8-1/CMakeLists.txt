cmake_minimum_required(VERSION 3.5)
project(hw8_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(number number.h number.cc number_main.cc)
add_executable(rectangle rectangle.h rectangle.cc rectangle_main.cc)

