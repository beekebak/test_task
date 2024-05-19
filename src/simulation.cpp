#include "simulation.h"
#include <iostream>
#include "data_validity_checker.h"
#include "output_handler.h"

Simulation::Simulation(std::string file_path){
  input_file_stream = std::ifstream(file_path, std::ios::in);
}

Simulation::~Simulation(){
  input_file_stream.close();
}

bool Simulation::CheckInputValidity(){
  DataValidityChecker data_checker;
  std::string line;
  std::vector<std::string> header;
  std::getline(input_file_stream, line);
  header.push_back(line);
  if(!parser.CheckNumLineCorrectness(line)) return false;
  std::getline(input_file_stream, line);
  header.push_back(line);
  if(!parser.CheckSecondLineCorrectness(line)) return false;
  std::getline(input_file_stream, line);
  header.push_back(line);
  if(!parser.CheckNumLineCorrectness(line)) return false;
  if(!data_checker.CheckHeaderData(parser.ParseHeader(header))) return false;
  while(line != ""){
    std::getline(input_file_stream, line);
    if(!parser.CheckEventCorrectness(line)) return false;
    if(!data_checker.CheckEventData(parser.ParseEvent(line))) return false;
  }
  input_file_stream.clear();
  input_file_stream.seekg(0, std::ios::beg);
  return true;
}

SimulationMetadata Simulation::GetData(){
  std::string line;
  std::vector<std::string> header;
  for(int i = 0; i < 3; i++){
    std::getline(input_file_stream, line);
    header.push_back(line);
  }
  return parser.ParseHeader(header);
}

void Simulation::HandleClientArrived(SimulationMetadata& data,
                                     ParsedEvent& event_data, Club& club){
  if(event_data.time_ < data.start_time_ || data.end_time_ < event_data.time_){
    OutputHandler::PrintError(event_data.time_, Error::kClosed);
    return;
  }
  if(club.CheckIfClientInClub(event_data.client_)){
    OutputHandler::PrintError(event_data.time_, Error::kClientAlreadyInClub);
    return;
  }
  club.AddClientToQueue(event_data.client_);
}

void Simulation::HandleClientSit(SimulationMetadata& data,
                                 ParsedEvent& event_data, Club& club){
  if(!club.CheckIfTableIsFree(event_data.table_index_)){
    OutputHandler::PrintError(event_data.time_, Error::kTableIsBusy);
    return;
  }
  if(!club.CheckIfClientInClub(event_data.client_)){
    OutputHandler::PrintError(event_data.time_, Error::kClientUnknown);
    return;
  }
  club.MoveClient(event_data.table_index_, event_data.client_, event_data.time_,
                  data.hourly_rate_, OutputHandler::PrintEvent);
}

void Simulation::HandleClientWait(SimulationMetadata& data,
                                  ParsedEvent& event_data, Club& club){
  if(club.CheckIfThereAreFreePlaces()){
    OutputHandler::PrintError(event_data.time_, Error::kClientCantWait);
    return;
  }
  if(club.CheckIfQueueTooBig()){
    club.RemoveClient(event_data.client_, event_data.time_, data.hourly_rate_,
                      OutputHandler::PrintEvent);
  }
}

void Simulation::HandleClientLeft(SimulationMetadata& data,
                                  ParsedEvent& event_data, Club& club){
  if(!club.CheckIfClientInClub(event_data.client_)){
    OutputHandler::PrintError(event_data.time_, Error::kClientUnknown);
    return;
  }
  club.RemoveClient(event_data.client_, event_data.time_, data.hourly_rate_,
                    OutputHandler::PrintEvent);
}

void Simulation::EndDay(SimulationMetadata& data, Club& club){
  OutputHandler::PrintTime(data.end_time_);
  OutputHandler::PrintEndOfDayData(club.GetTables());
}

void Simulation::ProccessInput(){
  SimulationMetadata data = GetData();
  OutputHandler::PrintTime(data.start_time_);
  std::string line;
  Club club(data.table_count_);
  std::getline(input_file_stream, line);
  while(line != ""){
    ParsedEvent event = parser.ParseEvent(line);
    switch(event.event_){
     case Event::kArrival:
      HandleClientArrived(data, event, club);
      break;
     case Event::kSit:
      HandleClientArrived(data, event, club);
      break;
     case Event::kWait:
      HandleClientArrived(data, event, club);
      break;
     case Event::kLeft:
      HandleClientArrived(data, event, club);
      break;
     default:
      return;
    }
  }
  EndDay(data, club);
}

void Simulation::StartSimulation(){
  if(!input_file_stream.is_open()){
    std::cerr << "Cannot open the file" << std::endl;
    return;
  }
  if(!CheckInputValidity()) return;
  ProccessInput();
}
