cmake_minimum_required(VERSION 3.5)
project(hw7_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(sorted_array sorted_array.h sorted_array.cc sorted_array_main.cc)
add_executable(integer_set integer_set.h integer_set.cc integer_set_main.cc)
