#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include "table.h"
#include "event.h"
#include "client.h"

class Club{
 public:
  Club(int tables_count);
  bool CheckIfTableIsFree(int index);
  bool CheckIfClientInClub(std::string name);
  bool CheckIfThereAreFreePlaces();
  bool CheckIfQueueTooBig();
  std::set<std::string> GetRemainingClientNames();
  std::vector<Table> GetTables();
  void MoveClient(int index, std::string client, Time event_time,
                  int hourly_rate, std::function<void(Time, Event, std::string, int)>
                  print_event_callback);
  void AddClientToQueue(std::string client);
  void RemoveClient(std::string client, Time event_time, int hourly_rate,
                    std::function<void(Time, Event, std::string, int)>
                    print_event_callback);
  void EndDay(Time day_end_time, int hourly_rate);
 private:
  void TakeEmptyTable(int index, Time event_time,
                      std::function<void(Time, Event, std::string, int)>
                      print_event_callback);
  void MoveClientBetweenTables(int index, std::string client, Time event_time,
                  int hourly_rate, std::function<void(Time, Event, std::string, int)>
                                                    print_event_callback);
  void LandClientToTable(int index, std::string client, Time event_time);
  void ChangeTableValues(int index, Time diff, int hourly_rate);
  std::vector<Table> tables;
  std::map<std::string, Client> playing_clients;
  std::deque<std::pair<std::string, Client>> clients_queue;
};

#endif // CLUB_H

//Found some ambiguousity. If id2 event happens it isn't said that id12 event
//should happen but in id12 event description it seems so. In my realization
//it happens.
