#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "table.h"
#include "error.h"
#include "event.h"

class OutputHandler{
 public:
  void PrintEvent(Time event_time, Event event_code, std::string client_name,
                  int table_index);
  void PrintError(Time event_time, Error error_code);
  void PrintEndOfDayData(std::vector<Table> tables);
  void PrintTime(Time event_time);
};

#endif // OUTPUT_HANDLER_H
