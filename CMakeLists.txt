cmake_minimum_required(VERSION 2.8)

project(database_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(database main.cpp token.cpp condition_parser.cpp)
