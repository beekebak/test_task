#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/club.h"

using namespace testing;;

TEST(club_tests, EndDayGetterTest){
  Club club(4);
  club.AddClientToQueue("name1");
  club.AddClientToQueue("name2");
  club.AddClientToQueue("name3");
  club.AddClientToQueue("name4");
  club.AddClientToQueue("name5");
  auto printLambda = [](Time time, std::string name, int index){};
  club.MoveClient(1, "name2", Time(10), 10, printLambda);
  club.MoveClient(2, "name3", Time(10), 10, printLambda);
  club.MoveClient(3, "name4", Time(10), 10, printLambda);
  ASSERT_THAT(club.GetRemainingClientNames(), ElementsAre("name1", "name2", "name3", "name4", "name5"));
  club.RemoveClient("name3", Time(10), 10, printLambda);
  ASSERT_THAT(club.GetRemainingClientNames(), ElementsAre("name1", "name2", "name4", "name5"));
}

TEST(club_tests, ChecksTest){
  Club club(4);
  ASSERT_TRUE(club.CheckIfTableIsFree(0));
  ASSERT_FALSE(club.CheckIfClientInClub("name"));
  ASSERT_TRUE(club.CheckIfThereAreFreePlaces());
  ASSERT_FALSE(club.CheckIfQueueTooBig());
  club.AddClientToQueue("name1");
  club.AddClientToQueue("name2");
  club.AddClientToQueue("name3");
  club.AddClientToQueue("name4");
  club.AddClientToQueue("name5");
  ASSERT_TRUE(club.CheckIfQueueTooBig());
  ASSERT_TRUE(club.CheckIfClientInClub("name1"));
  auto printLambda = [](Time time, std::string name, int index){};
  club.MoveClient(0, "name1", Time(10), 10, printLambda);
  ASSERT_FALSE(club.CheckIfQueueTooBig());
  ASSERT_FALSE(club.CheckIfTableIsFree(0));
  ASSERT_TRUE(club.CheckIfClientInClub("name1"));
  club.MoveClient(1, "name2", Time(10), 10, printLambda);
  club.MoveClient(2, "name3", Time(10), 10, printLambda);
  club.MoveClient(3, "name4", Time(10), 10, printLambda);
  ASSERT_FALSE(club.CheckIfThereAreFreePlaces());
}
