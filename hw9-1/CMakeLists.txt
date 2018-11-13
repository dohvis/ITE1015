cmake_minimum_required(VERSION 3.5)
project(hw9_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(classes classes.h classes.cc classes_main.cc)
add_executable(print_info print_info.h print_info.cc print_info_main.cc)
add_executable(print_member print_member.h print_member.cc print_member_main.cc)
