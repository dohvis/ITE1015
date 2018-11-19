cmake_minimum_required(VERSION 3.5)
project(hw9_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Animals Animals.h Animals.cc Animals_main.cc)
add_executable(draw_shape draw_shape.h draw_shape.cc draw_shape_main.cc)
