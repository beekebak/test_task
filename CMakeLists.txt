cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestProject scheduler.cpp
    time.h time.cpp
    client_state.h client_state.cpp
    event.h event.cpp
    error_handler.h error_handler.cpp
    table.h table.cpp
    client.h client.cpp
    club.h club.cpp
    parser.h parser.cpp
    simulation.h simulation.cpp)
