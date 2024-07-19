#ifndef output_handler_H
#define output_handler_H

#include <iostream>
#include <vector>
#include <fstream>
#include "desk.h"
#include "error.h"
#include "event.h"

/**
 * @brief Program output interface.
 * Formats input to string and prints it to cout.
 */
namespace output_handler{
  void PrintEvent(Time event_time, Event event_code, std::string client_name,
                  int desk_index);
  void PrintError(Time event_time, Error error_code);
  /**
   * @brief Print statistics of desk use during day.
   */
  void PrintEndOfDayData(std::vector<Desk> desks);
  void PrintTime(Time event_time);
  /**
   * @brief Print single line which caused program stop.
   */
  void PrintInvalidLine(std::string& invalid_line);
};

#endif // output_handler_H
