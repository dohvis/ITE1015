cmake_minimum_required(VERSION 3.5)
project(hw12_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(linked_list linked_list_main.cc linked_list.h)
add_executable(shared_ptr shared_ptr_main.cc shared_ptr.h)
