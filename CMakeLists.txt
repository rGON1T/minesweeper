cmake_minimum_required(VERSION 3.21)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Google_tests)

add_executable(minesweeper main.cpp minesweeper.h)
