cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
project(farma)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(farma ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++14 -Wall -Wextra")
