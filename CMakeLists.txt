cmake_minimum_required(VERSION 3.29)
project(CGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/main/cpp)

add_executable(CGame
    src/main/cpp/main.cpp
    src/main/cpp/main.h)
