cmake_minimum_required(VERSION 3.20)
project("test_task")

set(CMAKE_CXX_STANDARD 17)
#set(GOOGLETEST_VERSION 1.14.0)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(SOURCES
    src/scheduler.cpp
    src/time_struct.cpp
    src/client_state.cpp
    src/event.cpp
    src/error_handler.cpp
    src/table.cpp
    src/client.cpp
    src/club.cpp
    src/parser.cpp
    src/simulation.cpp
    src/simulation_metadata.cpp
    src/parsed_event.cpp
)

#enable_testing()

#add_subdirectory(googletest)
add_executable(main ${SOURCES})

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

#target_link_libraries(main gtest_main)
