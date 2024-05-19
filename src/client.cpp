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

void Client::ChangeTable(int new_table, Time new_sit_time){
  occupied_table_ = new_table;
  table_change_time_ = new_sit_time;
}
