#include "client.h"

Client::Client(std::string name, Table* table): name_(name),
                                                 occupied_table_(table){}

Client::Client(std::string name): Client(name, nullptr) {}

Client::Client(): Client("", nullptr) {}
