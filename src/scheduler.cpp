#include "simulation.h"

int main(int argc, char** argv){
  Simulation Simulation(argv[1]);
  Simulation.StartSimulation();
  return 0;
}
