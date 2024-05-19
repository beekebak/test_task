#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/output_handler.h"

using namespace testing;

TEST(output_handlerTest, PrintEventFormatTest){
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(1, 10), Event::kArrival, "client", -1);
  std::string buffer = testing::internal::GetCapturedStdout();
  ASSERT_EQ("01:10 1 client\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 0), Event::kTookFreeDesk, "client", 3);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_EQ("23:00 12 client 4\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 0), Event::kArrival, "client", 3);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("23:00 12 client 4\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 0), Event::kTookFreeDesk, "client", 4);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("23:00 12 client\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 0), Event::kArrival, "client1", 3);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("23:00 1 client\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 23), Event::kArrival, "client", 3);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("23:00 1 client\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintEvent(Time(23, 0), Event::kWait, "client", 3);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("23:00 1 client\n", buffer);
}

TEST(output_handlerTest, PrintError){
  testing::internal::CaptureStdout();
  output_handler::PrintError(Time(1, 10), Error::kClientAlreadyInClub);
  std::string buffer = testing::internal::GetCapturedStdout();
  ASSERT_EQ("01:10 13 YouShallNotPass\n", buffer);
  testing::internal::CaptureStdout();
  output_handler::PrintError(Time(1, 10), Error::kClientCantWait);
  buffer = testing::internal::GetCapturedStdout();
  ASSERT_NE("01:10 13 YouShallNotPass\n", buffer);
}

TEST(output_handlerTest, PrintTime){
  testing::internal::CaptureStdout();
  output_handler::PrintTime(Time(1, 10));
  std::string buffer = testing::internal::GetCapturedStdout();
  ASSERT_EQ(buffer, "01:10\n");
}

TEST(output_handlerTest, PrintEndOfDatData){
  std::vector<Desk> desks(3);
  for(int i = 0; i < 3; i++){
    desks[i].earned_money = (i+1)*10+i;
    desks[i].used_time = Time(i * 62 + 20);
  }
  std::string expected = "1 10 00:20\n2 21 01:22\n3 32 02:24\n";
  testing::internal::CaptureStdout();
  output_handler::PrintEndOfDayData(desks);
  std::string buffer = testing::internal::GetCapturedStdout();
  ASSERT_EQ(buffer, expected);
}

