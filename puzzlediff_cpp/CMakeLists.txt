cmake_minimum_required(VERSION 2.6)

file(GLOB PUZZLEDIFF_CPP_SRC *.cpp)
file(GLOB PUZZLEDIFF_C_SRC *.c)
set(${PUZZLEDIFF_CPP_SRC} ${PUZZLEDIFF_CPP_SRC} ${PUZZLEDIFF_C_SRC})

include_directories(${CMAKE_SOURCE_DIR}/libpuzzle)
include_directories(${SHARED_LIB_INCLUDE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/dependencies)
link_directories(${CMAKE_SOURCE_DIR}/libpuzzle)

find_library(libraries NAMES libgd.so libz.a libjpeg.so.8 libwebp.so.6 libpng16.so.16 HINTS ${CMAKE_SOURCE_DIR}/dependencies NO_DEFAULT_PATH)
set(libraries ${libraries} shared_lib)

add_executable(puzzlediff_cpp ${PUZZLEDIFF_CPP_SRC})
target_link_libraries(puzzlediff_cpp ${libraries} ${MATH_LIB})
