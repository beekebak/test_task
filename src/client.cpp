#include "client.h"

Client::Client(int table, Time first_sit):
                            occupied_table_(table), table_change_time_(first_sit){}

Client::Client(): Client(-1, Time(1440)){}

Time Client::GetLastSitTime(){
  return table_change_time_;
}

int Client::GetOccupiedTable(){
  return occupied_table_;
}

bool Client::operator==(const Client& other) const{
  return (other.table_change_time_ == table_change_time_ &&
          other.occupied_table_ == occupied_table_);
}

bool Client::operator!=(const Client& other) const{
  return !(*(this) == other);
}

void Client::ChangeTable(int new_table, Time new_sit_time){
  occupied_table_ = new_table;
  table_change_time_ = new_sit_time;
}
