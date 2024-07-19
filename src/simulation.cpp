#include <iostream>
#include "simulation.h"
#include "data_validity_checker.h"
#include "output_handler.h"

Simulation::Simulation(std::string file_path){
  input_file_stream_ = std::ifstream(file_path, std::ios::in);
  if(input_file_stream_.bad()) throw std::string("Couldn't open file");
}

Simulation::~Simulation(){
  input_file_stream_.close();
}

/**
 * For each line both format of input and data invariants should be checked.
 * Format is checked by parser functions.
 * Data validity is chekced by DataValidityChecker.
 * First 3 lines form a header which has check logic compared to events.
 *
 * @return String that violated format or invariants if present empty string
 * otherwise.
 */

std::string Simulation::CheckInputValidity(){
  DataValidityChecker data_checker;
  std::string line;
  std::vector<std::string> header;
  std::getline(input_file_stream_, line);
  header.push_back(line);
  if(!parser::CheckNumLineCorrectness(line)) return line;
  std::getline(input_file_stream_, line);
  header.push_back(line);
  if(!parser::CheckSecondLineCorrectness(line)) return line;
  std::getline(input_file_stream_, line);
  header.push_back(line);
  if(!parser::CheckNumLineCorrectness(line)) return line;
  if(!data_checker.CheckHeaderData(parser::ParseHeader(header))) return line;
  data_ptr_ = std::make_unique<SimulationMetadata>
      (SimulationMetadata(parser::ParseHeader(header)));
  club_ptr_ = std::make_unique<Club>(Club(data_ptr_->desk_count_));
  while(1){
    std::getline(input_file_stream_, line);
    if(line == "") break;
    if(!parser::CheckEventCorrectness(line)) return line;
    if(!data_checker.CheckEventData(parser::ParseEvent(line))) return line;
  }
  input_file_stream_.clear();
  input_file_stream_.seekg(0, std::ios::beg);
  return "";
}

void Simulation::HandleClientArrived(ParsedEvent& event_data){
  if(event_data.time_ < data_ptr_->start_time_ || data_ptr_->end_time_ < event_data.time_){
    output_handler::PrintError(event_data.time_, Error::kClosed);
    return;
  }
  if(club_ptr_->CheckIfClientInClub(event_data.client_)){
    output_handler::PrintError(event_data.time_, Error::kClientAlreadyInClub);
    return;
  }
  club_ptr_->AddClientToQueue(event_data.client_);
}

void Simulation::HandleClientSit(ParsedEvent& event_data){
  if(!club_ptr_->CheckIfDeskIsFree(event_data.desk_index_)){
    output_handler::PrintError(event_data.time_, Error::kDeskIsBusy);
    return;
  }
  if(!club_ptr_->CheckIfClientInClub(event_data.client_)){
    output_handler::PrintError(event_data.time_, Error::kClientUnknown);
    return;
  }
  club_ptr_->MoveClient(event_data.desk_index_, event_data.client_, event_data.time_,
                  data_ptr_->hourly_rate_, std::function(output_handler::PrintEvent));
}

void Simulation::HandleClientWait(ParsedEvent& event_data){
  if(club_ptr_->CheckIfThereAreFreePlaces()){
    output_handler::PrintError(event_data.time_, Error::kClientCantWait);
    return;
  }
  if(club_ptr_->CheckIfQueueIsTooBig()){
    club_ptr_->RemoveClient(event_data.client_, event_data.time_, data_ptr_->hourly_rate_,
                      output_handler::PrintEvent);
  }
}

void Simulation::HandleClientLeft(ParsedEvent& event_data){
  if(!club_ptr_->CheckIfClientInClub(event_data.client_)){
    output_handler::PrintError(event_data.time_, Error::kClientUnknown);
    return;
  }
  club_ptr_->RemoveClient(event_data.client_, event_data.time_, data_ptr_->hourly_rate_,
                    output_handler::PrintEvent);
}

/**
 * @brief Finishing function.
 *
 * Prints remaining by the close time clients names, time, tables statistics.
 */

void Simulation::EndDay(){
  std::set<std::string> left = club_ptr_->GetRemainingClientNames();
  for(auto client:left){
    output_handler::PrintEvent(data_ptr_->end_time_, Event::kDayEndOrLeft, client, -1);
  }
  output_handler::PrintTime(data_ptr_->end_time_);
  output_handler::PrintEndOfDayData(club_ptr_->GetDesks());
}

/**
 * @brief Reads line and delegates event to handler function.
 *
 * Calls finishing functions for both simulation and club.
 */

void Simulation::ProccessInput(){
  output_handler::PrintTime(data_ptr_->start_time_);
  std::string line;
  for(int i = 0; i < 3; i++) std::getline(input_file_stream_, line); //skip header
  while(1){
    std::getline(input_file_stream_, line);
    if(line == "") break;
    ParsedEvent event = parser::ParseEvent(line);
    output_handler::PrintEvent(event.time_, event.event_, event.client_,
                              event.desk_index_);
    switch(event.event_){
     case Event::kArrival:
      HandleClientArrived(event);
      break;
     case Event::kSit:
      HandleClientSit(event);
      break;
     case Event::kWait:
      HandleClientWait(event);
      break;
     case Event::kLeft:
      HandleClientLeft(event);
      break;
     default:
      return;
    }
  }
  club_ptr_->EndDay(data_ptr_->end_time_, data_ptr_->hourly_rate_);
  EndDay();
}

void Simulation::StartSimulation(){
  if(!input_file_stream_.is_open()){
    std::cerr << "Cannot open the file" << std::endl;
    return;
  }
  std::string check_line = CheckInputValidity();
  if(check_line != "") {
    output_handler::PrintInvalidLine(check_line);
    return;
  }
  ProccessInput();
}
