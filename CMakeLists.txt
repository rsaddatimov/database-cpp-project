cmake_minimum_required(VERSION 3.1)

project(database_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(database
    main.cpp
        database.cpp
        token.cpp
        condition_parser.cpp
        date.cpp
        node.cpp
    
    condition_parser_test.cpp
)
