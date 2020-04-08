cmake_minimum_required(VERSION 3.15)

project(ME-Final-Project-MPL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(ME-Final-Project-MPL main.cpp hangman.py)