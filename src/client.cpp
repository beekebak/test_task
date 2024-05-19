#include "client.h"

Client::Client(int desk, Time first_sit):
                            occupied_desk_(desk), desk_change_time_(first_sit){}

Client::Client(): Client(-1, Time(1440)){}

Time Client::GetLastSitTime(){
  return desk_change_time_;
}

int Client::GetOccupiedDesk(){
  return occupied_desk_;
}

void Client::ChangeDesk(int new_desk, Time new_sit_time){
  occupied_desk_ = new_desk;
  desk_change_time_ = new_sit_time;
}
