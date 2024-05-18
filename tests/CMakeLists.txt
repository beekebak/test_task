set(TESTS parser_test.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        I0bfbb2da6b3902fc3e41a8e1c4aacb291ffdd098
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests ${TESTS})

target_link_libraries(
  my_googletest
  GTest::gtest
  GTest::gtest_main
)

include(GoogleTest)

foreach(tst ${TESTS})
gtest_discover_tests(${tst})
