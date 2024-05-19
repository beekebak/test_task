#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <fstream>
#include <memory>
#include "parser.h"
#include "simulation_metadata.h"
#include "club.h"

/**
 * @brief Simulates work of computer club.
 *
 * Main program class. Provides StartSimultaion function as interface
 * to start work.
 * Each of HandleClient* function handles one specific event.
 */

class Simulation{
 public:
  Simulation(std::string file_path);
  ~Simulation();
  void StartSimulation();
 private:
  std::ifstream input_file_stream_;
  /**
   * @brief Checks input before any event would be handled.
   */
  std::string CheckInputValidity();
  std::unique_ptr<Club> club_ptr_;
  std::unique_ptr<SimulationMetadata> data_ptr_;
  /**
   * @brief Processes input events.
   */
  void ProccessInput();
  void HandleClientArrived(ParsedEvent& event_data);
  void HandleClientSit(ParsedEvent& event_data);
  void HandleClientWait(ParsedEvent& event_data);
  void HandleClientLeft(ParsedEvent& event_data);
  /**
   * @brief Does remaining work after all events are handled.
   */
  void EndDay();
};

#endif // SIMULATION_H
