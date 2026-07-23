cmake_minimum_required(VERSION 3.16)
project(numerical-methods LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(numerical-methods
    src/main.cpp
    include/Polynomial.h
)

target_include_directories(numerical-methods PRIVATE include)

if(MSVC)
    target_compile_options(numerical-methods PRIVATE /W4)
else()
    target_compile_options(numerical-methods PRIVATE -Wall -Wextra -Wpedantic)
endif()