cmake_minimum_required(VERSION 2.6)

file(GLOB PUZZLEDIFF_CPP_SRC *.cpp)
file(GLOB PUZZLEDIFF_C_SRC *.c)
set(${PUZZLEDIFF_CPP_SRC} ${PUZZLEDIFF_CPP_SRC} ${PUZZLEDIFF_C_SRC})

include_directories(${CMAKE_SOURCE_DIR}/libpuzzle)
include_directories(${SHARED_LIB_INCLUDE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/dependencies)
link_directories(${CMAKE_SOURCE_DIR}/libpuzzle)

find_library(LIB_GD libgd.so NAMES libgd.so.2 libgd.so.3)
find_library(LIB_JPEG libjpeg.so NAMES libjpeg.so.8 libjpeg.so.62 libjpeg.so.62.1)
find_library(LIB_Z libz.a NAMES libz.so.1.2.8 libz.so.1 libz.so)
find_library(LIB_WEBP libwebp.so NAMES libwebp.so.6 libwebp.so.5 libwebp.so.5.0.1)
find_library(LIB_PNG libpng.so NAMES libpng16.so libpng16.so.16 libpng12.so.0)

if (NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    find_library(LIB_CILK libcilkrts.so NAMES libcilkrts.so.5)
endif()

set(libraries ${LIB_GD} ${LIB_Z} ${LIB_JPEG} ${LIB_WEBP} ${LIB_PNG} ${LIB_CILK} shared_lib ${MATH_LIB})

add_executable(puzzlediff_cpp ${PUZZLEDIFF_CPP_SRC})
target_link_libraries(puzzlediff_cpp ${libraries})
