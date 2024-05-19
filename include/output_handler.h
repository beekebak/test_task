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
  void static PrintEvent(Time event_time, Event event_code, std::string client_name,
                  int table_index);
  void static PrintError(Time event_time, Error error_code);
  void static PrintEndOfDayData(std::vector<Table> tables);
  void static PrintTime(Time event_time);
  void static PrintInvalidLine(std::string invalid_line);
};

#endif // OUTPUT_HANDLER_H
