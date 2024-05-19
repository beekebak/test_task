#include "club.h"

Club::Club(int tables_count): tables(std::vector<Table>(tables_count)){};

bool Club::CheckIfClientInClub(std::string name){
  for(auto const client_pair:clients_queue){
    if(client_pair.first == name) return true;
  }
  return playing_clients.find(name) != playing_clients.end();
}

bool Club::CheckIfTableIsFree(int index){
  return !tables[index].client_is_present;
}

bool Club::CheckIfThereAreFreePlaces(){
  return tables.size() > playing_clients.size();
}

bool Club::CheckIfQueueTooBig(){
  return tables.size() < clients_queue.size();
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

std::vector<Table> Club::GetTables(){
  return tables;
}

void Club::ChangeTableValues(int index,  Time diff, int hourly_rate){
  tables[index].used_time.time_value += diff.time_value;
  tables[index].earned_money += diff.time_value * hourly_rate;
}

void Club::TakeEmptyTable(int index, Time event_time,
                          std::function<void(Time, std::string, int)>
                          print_event_callback){
  if(clients_queue.size() > 0){
    std::pair<std::string, Client> new_client = clients_queue.front();
    clients_queue.pop_front();
    new_client.second.ChangeTable(index, event_time);
    playing_clients[new_client.first] = new_client.second;
    print_event_callback(event_time, new_client.first, index);
    tables[index].client_is_present = true;
  }
  else tables[index].client_is_present = false;
}

void Club::MoveClientBetweenTables(int index, std::string client, Time event_time,
                       int hourly_rate, std::function<void(Time, std::string, int)>
                                                        print_event_callback){
  Time time_diff = event_time - playing_clients[client].GetLastSitTime();
  playing_clients[client].ChangeTable(index, event_time);
  ChangeTableValues(playing_clients[client].GetOccupiedTable(), time_diff,
                    hourly_rate);
  TakeEmptyTable(index, event_time, print_event_callback);
}

void Club::RemoveClient(std::string client, Time event_time, int hourly_rate,
                        std::function<void(Time, std::string, int)>
                        print_event_callback){
  if(playing_clients.find(client) != playing_clients.end()){
    int index = playing_clients[client].GetOccupiedTable();
    Time diff = event_time - playing_clients[client].GetLastSitTime();
    playing_clients.erase(client);
    ChangeTableValues(index, diff, hourly_rate);
    TakeEmptyTable(index, event_time, print_event_callback);
  }
  else{
    for(auto iter = clients_queue.begin(); iter < clients_queue.end(); iter++){
      if(iter->first == client){
        clients_queue.erase(iter);
        break;
      }
    }
  }
}

void Club::AddClientToQueue(std::string client){
  clients_queue.push_back({client, Client()});
}

void Club::LandClientToTable(int index, std::string client, Time event_time){
  for(auto iter = clients_queue.begin(); iter < clients_queue.end(); iter++){
    if(iter->first == client){
      iter->second.ChangeTable(index, event_time);
      playing_clients[iter->first] = iter->second;
      clients_queue.erase(iter);
      tables[index].client_is_present = true;
      break;
    }
  }
}

void Club::MoveClient(int index, std::string client, Time event_time,
                      int hourly_rate, std::function<void(Time, std::string, int)>
                      print_event_callback){
  if(playing_clients.find(client) != playing_clients.end()){
    MoveClientBetweenTables(index, client, event_time, hourly_rate,
                            print_event_callback);
  }
  else LandClientToTable(index, client, event_time);
}
