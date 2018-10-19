cmake_minimum_required(VERSION 3.5)
project(hw6_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(minimal_fighter minimal_fighter.cc minimal_fighter.h minimal_fighter_main.cc)
add_executable(simple_account simple_account.h simple_account.cc simple_account_main.cc)
