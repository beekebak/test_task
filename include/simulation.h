#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <fstream>
#include "parser.h"
#include "simulation_metadata.h"
#include "club.h"

class Simulation{
 public:
  Simulation(std::string file_path);
  ~Simulation();
  void StartSimulation();
 private:
  Parser parser;
  std::string CheckInputValidity();
  void ProccessInput();
  void HandleClientArrived(SimulationMetadata& data, ParsedEvent& event_data,
                           Club& club);
  void HandleClientSit(SimulationMetadata& data, ParsedEvent& event_data,
                       Club& club);
  void HandleClientWait(SimulationMetadata& data, ParsedEvent& event_data,
                        Club& club);
  void HandleClientLeft(SimulationMetadata& data, ParsedEvent& event_data,
                        Club& club);
  void EndDay(SimulationMetadata& data, Club& club);
  SimulationMetadata GetData();
  std::ifstream input_file_stream;
};

#endif // SIMULATION_H
