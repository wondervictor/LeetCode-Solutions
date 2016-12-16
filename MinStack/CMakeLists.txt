cmake_minimum_required(VERSION 3.6)
project(MinStack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    makefile)

add_executable(MinStack ${SOURCE_FILES})