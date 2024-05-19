#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "time_struct.h"
/**
 * @brief Contains taken desk and last time when desk was changed.
 *
 * By default table and time have unreachable values.
 * Values only should be changed both at once by ChangeDesk method.
 */
class Client{
 public:
  Client(int desk, Time first_sit_time);
  Client();
  void ChangeDesk(int new_desk, Time new_sit_time);
  Time GetLastSitTime();
  int GetOccupiedDesk();
 private:
  int occupied_desk_;
  Time desk_change_time_;
};

#endif // CLIENT_H
