cmake_minimum_required(VERSION 3.5)
project(hw11_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(world_clock world_clock.h world_clock.cc world_clock_main.cc)
add_executable(calendar calendar.h calendar.cc calendar_main.cc)
