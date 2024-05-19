#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include "desk.h"
#include "event.h"
#include "client.h"

/**
 * Contains desks and clients present in club.
 * Provides interface to work with this data.
 * Used std::function insted of direct access to output_handler because
 * I thought that it would be bad for code flexibility.
 */

class Club{
 public:
  Club(int desks_count);
  bool CheckIfDeskIsFree(int index);
  bool CheckIfClientInClub(std::string name);
  bool CheckIfThereAreFreePlaces();
  bool CheckIfQueueIsTooBig();
  std::set<std::string> GetRemainingClientNames();
  std::vector<Desk> GetDesks();
  /**
   * Delegates work MoveClientBetweenDesks or LandClientToDesk depending on
   * location of client(queue or some table).
   */
  void MoveClient(int index, std::string client, Time event_time,
                  int hourly_rate, std::function<void(Time, Event, std::string, int)>
                  print_event_callback);
  void AddClientToQueue(std::string client);
  void RemoveClient(std::string client, Time event_time, int hourly_rate,
                    std::function<void(Time, Event, std::string, int)>
                    print_event_callback);
  /**
   * @brief Finishing function.
   */
  void EndDay(Time day_end_time, int hourly_rate);
 private:
  /**
   * @brief Appoints empty desk to first client in queue.
   * Keeps it empty if queue is empty.
   */
  void TakeEmptyDesk(int index, Time event_time,
                      std::function<void(Time, Event, std::string, int)>
                      print_event_callback);
  void MoveClientBetweenDesks(int index, std::string client, Time event_time,
                  int hourly_rate, std::function<void(Time, Event, std::string, int)>
                                                    print_event_callback);
  void LandClientToDesk(int index, std::string client, Time event_time);
  /**
   * @brief Changes revenue and busy time of desk.
   * Should be invoked every time client helded deck changes it's place.
   */
  void ChangeDeskValues(int index, Time diff, int hourly_rate);
  std::vector<Desk> desks;
  std::map<std::string, Client> playing_clients;
  std::deque<std::pair<std::string, Client>> clients_queue;
};

#endif // CLUB_H
