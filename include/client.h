#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "table.h"

class Client{
 public:
  Client();
  Client(std::string name);
  Client(std::string name, Table* table);
 private:
  const std::string name_;
  Table* occupied_table_;
};

#endif // CLIENT_H