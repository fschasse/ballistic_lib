cmake_minimum_required(VERSION 3.0)

project(ballistics_cpp_lib)

add_executable(ballistics_cpp_lib main.cpp)

install(TARGETS ballistics_cpp_lib RUNTIME DESTINATION bin)
