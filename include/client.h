#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "time_struct.h"

class Client{
 public:
  Client(int table, Time first_sit_time);
  Client();
  bool operator==(const Client& other) const;
  bool operator!=(const Client& other) const;
  void ChangeTable(int new_table, Time new_sit_time);
  Time GetLastSitTime();
  int GetOccupiedTable();
 private:
  int occupied_table_;
  Time table_change_time_;
};

#endif // CLIENT_H
