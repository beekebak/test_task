cmake_minimum_required(VERSION 3.20)
project("test_task")

set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.14.0)

#set(TESTMODE)

if(DEFINED TESTMODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

set(SOURCES
    src/time_struct.cpp
    src/client.cpp
    src/club.cpp
    src/parser.cpp
    src/simulation.cpp
    src/simulation_metadata.cpp
    src/parsed_event.cpp
    src/error_handler.cpp
    src/output_handler.cpp
    src/data_validity_checker.cpp
)

if(NOT DEFINED TESTMODE)
    add_executable(main ${SOURCES} src/scheduler.cpp)
    target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
endif()

if(DEFINED TESTMODE)
    set(TESTS
        tests/parser_test.cpp
        tests/club_test.cpp)

    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        03597a01ee50ed33e9dfd640b249b4be3799d395
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_executable(my_googletest ${TESTS} ${SOURCES}
        include/data_validity_checker.h
        src/data_validity_checker.cpp)

    target_link_libraries(
      my_googletest
      GTest::gmock
      GTest::gtest
      GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(my_googletest)
    target_include_directories(my_googletest PUBLIC ${PROJECT_SOURCE_DIR}/include)

endif()

