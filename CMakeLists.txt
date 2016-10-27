cmake_minimum_required(VERSION 2.6)
project(puzzle)

add_executable(puzzle main.cpp)

install(TARGETS puzzle RUNTIME DESTINATION bin)
