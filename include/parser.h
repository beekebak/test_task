#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <utility>
#include "simulation_metadata.h"
#include "parsed_event.h"

class Parser{
 public:
  bool CheckNumLineCorrectness(std::string line);
  bool CheckSecondLineCorrectness(std::string line);
  bool CheckEventCorrectness(std::string line);
  SimulationMetadata ParseHeader(std::vector<std::string> header);
  ParsedEvent ParseEvent(std::string line);
};

#endif // PARSER_H
