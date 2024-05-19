#include "club.h"

Club::Club(int desks_count): desks(std::vector<Desk>(desks_count)){};

bool Club::CheckIfClientInClub(std::string name){
  for(auto const client_pair:clients_queue){
    if(client_pair.first == name) return true;
  }
  return playing_clients.find(name) != playing_clients.end();
}

bool Club::CheckIfDeskIsFree(int index){
  return !desks[index].client_is_present;
}

bool Club::CheckIfThereAreFreePlaces(){
  return desks.size() > playing_clients.size();
}

bool Club::CheckIfQueueIsTooBig(){
  return desks.size() < clients_queue.size();
}

std::set<std::string> Club::GetRemainingClientNames(){
  std::set<std::string> remaining_clients;
  for(auto const client_pair:clients_queue){
    remaining_clients.emplace(client_pair.first);
  }
  for(auto const client_pair:playing_clients){
    remaining_clients.emplace(client_pair.first);
  }
  return remaining_clients;
}

std::vector<Desk> Club::GetDesks(){
  return desks;
}

void Club::ChangeDeskValues(int index,  Time diff, int hourly_rate){
  desks[index].used_time += diff;
  desks[index].earned_money += diff.GetHoursCeil() * hourly_rate;
}

void Club::TakeEmptyDesk(int index, Time event_time,
                          std::function<void(Time, Event, std::string, int)>
                          print_event_callback){
  if(clients_queue.size() > 0){
    std::pair<std::string, Client> new_client = clients_queue.front();
    clients_queue.pop_front();
    new_client.second.ChangeDesk(index, event_time);
    playing_clients[new_client.first] = new_client.second;
    print_event_callback(event_time, Event::kTookFreeDesk, new_client.first, index);
    desks[index].client_is_present = true;
  }
  else desks[index].client_is_present = false;
}

void Club::MoveClientBetweenDesks(int index, std::string client, Time event_time,
                       int hourly_rate, std::function<void(Time, Event, std::string, int)>
                                                        print_event_callback){
  Time time_diff = event_time - playing_clients[client].GetLastSitTime();
  ChangeDeskValues(playing_clients[client].GetOccupiedDesk(), time_diff,
                    hourly_rate);
  playing_clients[client].ChangeDesk(index, event_time);
  TakeEmptyDesk(index, event_time, print_event_callback);
}

void Club::RemoveClient(std::string client, Time event_time, int hourly_rate,
                        std::function<void(Time, Event, std::string, int)>
                        print_event_callback){
  if(playing_clients.find(client) != playing_clients.end()){
    int index = playing_clients[client].GetOccupiedDesk();
    Time diff = event_time - playing_clients[client].GetLastSitTime();
    playing_clients.erase(client);
    ChangeDeskValues(index, diff, hourly_rate);
    TakeEmptyDesk(index, event_time, print_event_callback);
  }
  else{
    for(auto iter = clients_queue.begin(); iter < clients_queue.end(); iter++){
      if(iter->first == client){
        print_event_callback(event_time, Event::kDayEndOrLeft, client,
                             iter->second.GetOccupiedDesk());
        clients_queue.erase(iter);
        break;
      }
    }
  }
}

void Club::EndDay(Time day_end_time, int hourly_rate){
  for(auto pair:playing_clients){
    ChangeDeskValues(pair.second.GetOccupiedDesk(),
                      day_end_time-pair.second.GetLastSitTime(), hourly_rate);
  }
}

void Club::AddClientToQueue(std::string client){
  clients_queue.push_back({client, Client()});
}

void Club::LandClientToDesk(int index, std::string client, Time event_time){
  for(auto iter = clients_queue.begin(); iter < clients_queue.end(); iter++){
    if(iter->first == client){
      iter->second.ChangeDesk(index, event_time);
      playing_clients[iter->first] = iter->second;
      clients_queue.erase(iter);
      desks[index].client_is_present = true;
      break;
    }
  }
}

void Club::MoveClient(int index, std::string client, Time event_time,
                      int hourly_rate, std::function<void(Time, Event, std::string, int)>
                      print_event_callback){
  if(playing_clients.find(client) != playing_clients.end()){
    MoveClientBetweenDesks(index, client, event_time, hourly_rate,
                            print_event_callback);
  }
  else LandClientToDesk(index, client, event_time);
}
