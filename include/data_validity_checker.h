#ifndef DATA_VALIDITY_CHECKER_H
#define DATA_VALIDITY_CHECKER_H

#include "time_struct.h"
#include "simulation_metadata.h"
#include "parsed_event.h"

class DataValidityChecker{
 public:
  bool CheckHeaderData(SimulationMetadata header);
  bool CheckEventData(ParsedEvent event);
 private:
  Time last_checked_time_ = Time(0);
  int table_count_;
};

#endif // DATA_VALIDITY_CHECKER_H
