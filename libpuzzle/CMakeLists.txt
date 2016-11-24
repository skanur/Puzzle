cmake_minimum_required(VERSION 2.6)

set(SHARED_LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dependencies/ligd-include)
set(SHARED_LIB_INCLUDE_DIR ${SHARED_LIB_INCLUDE_DIR} PARENT_SCOPE)

if(TARGET shared_lib)
    message("shared_lib is already defined")
else()
    include_directories(${SHARED_LIB_INCLUDE_DIR})
    set(LIB_SRCS cvec.c dvec.c puzzle.c tunables.c vector_ops.c)
    
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
            set(MATH_LIB "")
        else()
            set(MATH_LIB m)
            set(${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS} -fcilkplus")
        endif()
    
    add_library(shared_lib STATIC ${LIB_SRCS} ${SHARED_LIB_INCLUDE_HEADERS})
endif()
