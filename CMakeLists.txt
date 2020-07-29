cmake_minimum_required(VERSION 3.1)

project(database_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(database
    main.cpp
    database.cpp
    token.cpp
    condition_parser.cpp
    test_runner.cpp
    date.cpp
        parser_nodes/empty_node.cpp
        parser_nodes/date_comparison_node.cpp
        parser_nodes/event_comparison_node.cpp
        parser_nodes/logical_operation_node.cpp
)
