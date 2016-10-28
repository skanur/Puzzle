cmake_minimum_required(VERSION 2.6)

file(GLOB PUZZLEDIFF_SRC *.c)

include_directories(${CMAKE_SOURCE_DIR}/libpuzzle)
include_directories(${SHARED_LIB_INCLUDE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/dependencies)
link_directories(${CMAKE_SOURCE_DIR}/libpuzzle)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    set(MATH_LIB "")
else()
    set(MATH_LIB m)
    set(${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS} -fcilkplus")
endif()

add_executable(puzzlediff ${PUZZLEDIFF_SRC})
target_link_libraries(puzzlediff shared_lib gd z jpeg png ${MATH_LIB})
