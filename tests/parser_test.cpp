#include <gtest/gtest.h>
#include "../include/parser.h"

using namespace testing;

TEST(parser_tests, integer_checking_test){
  Parser parser;
  parser.CheckNumLineCorrectness(std::string("1"));
}


int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

