cmake_minimum_required(VERSION 3.16)
project(numerical-methods LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(numerical-methods
    main.cpp
    Polynomial.h
)

target_include_directories(numerical-methods PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(numerical-methods PRIVATE /W4)
else()
    target_compile_options(numerical-methods PRIVATE -Wall -Wextra -Wpedantic)
endif()
