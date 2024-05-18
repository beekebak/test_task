#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include "table.h"
#include "client.h"

class Club{
 public:
  Club();
 private:
  std::vector<Table> tables;
  std::vector<Client> clients;
  int hourly_rate;
};

#endif // CLUB_H
