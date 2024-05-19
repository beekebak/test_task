#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/data_validity_checker.h"

using namespace testing;

TEST(data_validity_checker_test, TestValidator){
  DataValidityChecker checker;
  ASSERT_FALSE(checker.CheckHeaderData(SimulationMetadata(10, 1, 0, 1)));
  ASSERT_TRUE(checker.CheckHeaderData(SimulationMetadata(10, 1, 10, 1)));
  ASSERT_TRUE(checker.CheckEventData(ParsedEvent(Time(1), Event::kArrival,
                                                 "client")));
  ASSERT_FALSE(checker.CheckEventData(ParsedEvent(Time(0), Event::kArrival,
                                                  "client")));
  ASSERT_FALSE(checker.CheckEventData(ParsedEvent(Time(0), Event::kArrival,
                                                  "client", 20)));
}
