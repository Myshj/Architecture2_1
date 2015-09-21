cmake_minimum_required(VERSION 3.3)
project(Architecture1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -std=c++11")

set(SOURCE_FILES main.cpp GenericSet.cpp GenericSet.h)
add_executable(Architecture1 ${SOURCE_FILES})