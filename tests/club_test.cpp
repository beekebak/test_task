#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/club.h"

using namespace testing;;

TEST(club_test, EndDayGetterTest){
  Club club(4);
  club.AddClientToQueue("name1");
  club.AddClientToQueue("name2");
  club.AddClientToQueue("name3");
  club.AddClientToQueue("name4");
  club.AddClientToQueue("name5");
  auto printLambda = [](Time time, Event, std::string name, int index){};
  club.MoveClient(1, "name2", Time(10), 10, printLambda);
  club.MoveClient(2, "name3", Time(10), 10, printLambda);
  club.MoveClient(3, "name4", Time(10), 10, printLambda);
  ASSERT_THAT(club.GetRemainingClientNames(), ElementsAre("name1", "name2", "name3", "name4", "name5"));
  club.RemoveClient("name3", Time(10), 10, printLambda);
  ASSERT_THAT(club.GetRemainingClientNames(), ElementsAre("name1", "name2", "name4", "name5"));
}

TEST(club_test, ChecksTest){
  Club club(4);
  ASSERT_TRUE(club.CheckIfDeskIsFree(0));
  ASSERT_FALSE(club.CheckIfClientInClub("name"));
  ASSERT_TRUE(club.CheckIfThereAreFreePlaces());
  ASSERT_FALSE(club.CheckIfQueueIsTooBig());
  club.AddClientToQueue("name1");
  club.AddClientToQueue("name2");
  club.AddClientToQueue("name3");
  club.AddClientToQueue("name4");
  club.AddClientToQueue("name5");
  ASSERT_TRUE(club.CheckIfQueueIsTooBig());
  ASSERT_TRUE(club.CheckIfClientInClub("name1"));
  auto printLambda = [](Time time, Event, std::string name, int index){};
  club.MoveClient(0, "name1", Time(10), 10, printLambda);
  ASSERT_FALSE(club.CheckIfQueueIsTooBig());
  ASSERT_FALSE(club.CheckIfDeskIsFree(0));
  ASSERT_TRUE(club.CheckIfClientInClub("name1"));
  club.MoveClient(1, "name2", Time(10), 10, printLambda);
  club.MoveClient(2, "name3", Time(10), 10, printLambda);
  club.MoveClient(3, "name4", Time(10), 10, printLambda);
  ASSERT_FALSE(club.CheckIfThereAreFreePlaces());
}
