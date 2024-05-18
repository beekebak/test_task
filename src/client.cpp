#include "client.h"

Client::Client(std::string name, Table* table): name_(name),
                                                 occupied_table_(table){}

Client::Client(std::string name): Client(name, nullptr) {}

Client::Client(): Client("", nullptr) {}

bool Client::operator==(const Client& other) const{
  return (other.name_ == name_ && other.occupied_table_ == occupied_table_);
}

bool Client::operator!=(const Client& other) const{
  return !(*(this) == other);
}
