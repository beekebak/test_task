#include <gtest/gtest.h>

using namespace testing;

TEST(program_tests, parser_test){
  EXPECT_EQ(1, 1);
}


int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

