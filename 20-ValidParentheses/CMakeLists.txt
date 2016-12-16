cmake_minimum_required(VERSION 3.6)
project(20_ValidParentheses)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    makefile)

add_executable(20_ValidParentheses ${SOURCE_FILES})