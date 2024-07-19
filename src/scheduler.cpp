#include <iostream>
#include "simulation.h"

int main(int argc, char** argv){
  if(argc < 2){
      std::cerr << "No file path provided" << std::endl;
      return 1;
  }
  try{
    Simulation Simulation(argv[1]);
    Simulation.StartSimulation();
  } catch(const std::string& error_message){
    std::cerr << error_message << std::endl;
    return 1;
  }

  return 0;
}
