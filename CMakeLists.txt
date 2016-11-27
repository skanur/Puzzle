cmake_minimum_required(VERSION 2.6)
project(puzzle)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    set(MATH_LIB "")
else()
    add_compile_options("-fcilkplus")
    set(MATH_LIB m)
endif()

add_compile_options("-g")
add_subdirectory(libpuzzle)
add_subdirectory(puzzlediff_cpp)
