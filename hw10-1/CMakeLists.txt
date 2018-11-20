cmake_minimum_required(VERSION 3.5)
project(hw10_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(class_function class_function.h class_function.cc class_function_main.cc)
add_executable(cast_quiz cast_quiz.cc)
add_executable(dynamic_cast dynamic_cast.cc dynamic_cast.h dynamic_cast_main.cc)
