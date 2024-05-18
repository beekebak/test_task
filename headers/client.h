#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "table.h"

class Client{
 public:
  Client();
 private:
  std::string name;
  Table* occupied_table = nullptr;
};

#endif // CLIENT_H
