#include <sstream>
#include <regex>
#include "parser.h"

bool parser::CheckNumLineCorrectness(std::string& line){
  std::regex pattern("[1-9][0-9]*");
  return regex_match(line, pattern);
}

bool parser::CheckSecondLineCorrectness(std::string& line){
  std::regex pattern("(([0-1][0-9])|(2[0-3])):[0-5][0-9]\
 (([0-1][0-9])|(2[0-3])):[0-5][0-9]");
  return regex_match(line, pattern);
}

bool parser::CheckEventCorrectness(std::string& line){
  std::regex pattern("((([0-1][0-9])|(2[0-3])):[0-5][0-9] [134] [a-z0-9_-]+)|((([0-1][0-9])|(2[0-3])):[0-5][0-9] 2 [a-z0-9_-]+ [1-9][0-9]*)");
  return regex_match(line, pattern);
}

SimulationMetadata parser::ParseHeader(std::vector<std::string>& header){
  int desk_count = std::stoi(header[0]);
  Time start_time = Time(header[1].substr(0,5));
  Time end_time = Time(header[1].substr(6,11));
  int hourly_rate = std::stoi(header[2]);
  return SimulationMetadata(desk_count, start_time, end_time, hourly_rate);
}

/**
 * @return Event data with desk number reduced by 1 to convert it to array index.
 *
 */
ParsedEvent parser::ParseEvent(std::string& line){
  std::istringstream stream(line);
  std::string buffer;
  stream >> buffer;
  Time event_time(buffer);
  stream >> buffer;
  int code = stoi(buffer);
  std::string client_name;
  stream >> client_name;
  if(code == 2){
    stream >> buffer;
    int desk_index = stoi(buffer);
    return ParsedEvent(event_time, Event(code), client_name, desk_index-1);
  }
  return ParsedEvent(event_time, Event(code), client_name);
}


