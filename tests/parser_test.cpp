#include <gtest/gtest.h>
#include "../include/parser.h"

using namespace testing;

TEST(parser_test, integer_checking_test){
  Parser parser;
  ASSERT_TRUE(parser.CheckNumLineCorrectness(std::string("1")));
  ASSERT_TRUE(parser.CheckNumLineCorrectness(std::string("100004")));
  ASSERT_TRUE(parser.CheckNumLineCorrectness(std::string("1234567890987654321")));
  ASSERT_FALSE(parser.CheckNumLineCorrectness(std::string("-1")));
  ASSERT_FALSE(parser.CheckNumLineCorrectness(std::string("0")));
  ASSERT_FALSE(parser.CheckNumLineCorrectness(std::string("a")));
  ASSERT_FALSE(parser.CheckNumLineCorrectness(std::string("13-13")));
}

TEST(parser_test, double_time_cheking_test){
  Parser parser;
  ASSERT_TRUE(parser.CheckSecondLineCorrectness(std::string("09:45 21:30")));
  ASSERT_TRUE(parser.CheckSecondLineCorrectness(std::string("20:31 00:00")));
  ASSERT_TRUE(parser.CheckSecondLineCorrectness(std::string("23:59 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("24:00 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("30:11 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("20:71 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("20:60 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("2031 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("2:31 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("20:1 01:01")));
  ASSERT_FALSE(parser.CheckSecondLineCorrectness(std::string("20ab3 01:01")));
}

TEST(parser_test, event_correctness_checking_test){
  Parser parser;
  ASSERT_TRUE(parser.CheckEventCorrectness(std::string("09:45 1 beek")));
  ASSERT_TRUE(parser.CheckEventCorrectness(std::string("19:45 4 baak")));
  ASSERT_TRUE(parser.CheckEventCorrectness(std::string("19:45 4 b-e_b4k")));
  ASSERT_TRUE(parser.CheckEventCorrectness(std::string("05:11 2 beek 4")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 2 beek")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 2 beek ")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 2 beek 0")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 2 beek a")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 1 beek 2")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 1 AAAA")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("05:11 6 beek")));
  ASSERT_FALSE(parser.CheckEventCorrectness(std::string("24:11 1 beek")));
}

TEST(parser_test, header_parse_test){
  Parser parser;
  SimulationMetadata pattern(3213, Time(10, 10), Time(20, 2), 20);
  std::vector<std::string> right{"3213", "10:10 20:02", "20"};
  std::vector<std::string> wrong_time{"3213", "10:01 20:22", "20"};
  std::vector<std::string> wrong_count{"313", "10:10 20:02", "21"};
  ASSERT_EQ(pattern, parser.ParseHeader(right));
  ASSERT_NE(pattern, parser.ParseHeader(wrong_count));
  ASSERT_NE(pattern, parser.ParseHeader(wrong_time));
}

TEST(parser_test, event_parse_test){
  Parser parser;
  ParsedEvent three(Time(10, 10), Event(1), std::string("named"));
  ParsedEvent four(Time(20, 20), Event(2), std::string("named"), 2);
  std::string three_right("10:10 1 named");
  std::string four_right("20:20 2 named 3");
  std::string name_wrong("10:10 1 notnamed");
  std::string code_wrong("10:10 4 named");
  std::string table_index_wrong("20:20 2 named 5");
  std::string time_wrong("00:30 1 named");
  ASSERT_EQ(three, parser.ParseEvent(three_right));
  ASSERT_EQ(four, parser.ParseEvent(four_right));
  ASSERT_NE(three, parser.ParseEvent(name_wrong));
  ASSERT_NE(three, parser.ParseEvent(code_wrong));
  ASSERT_NE(four, parser.ParseEvent(table_index_wrong));
  ASSERT_NE(three, parser.ParseEvent(time_wrong));
  ASSERT_NE(four, parser.ParseEvent("20:20 1 named"));
}

int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

