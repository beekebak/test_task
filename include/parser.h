#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <utility>
#include "simulation_metadata.h"
#include "parsed_event.h"

/**
 * @brief Checks input data format and converts it to program data objects.
 */

namespace parser{
  /**
   * @param Should be either 1 or 3 line of input file.
   */
  bool CheckNumLineCorrectness(std::string line);
  /**
   * @param Should be 2 line of input file
   */
  bool CheckSecondLineCorrectness(std::string line);
  bool CheckEventCorrectness(std::string line);
  /**
   * @param Since there are 3 lines of metadata before events takes
   * vector of size 3 with those lines
   */
  SimulationMetadata ParseHeader(std::vector<std::string> header);
  ParsedEvent ParseEvent(std::string line);
};

#endif // PARSER_H
