#include "data_validity_checker.h"

bool DataValidityChecker::CheckHeaderData(SimulationMetadata header){
  if(header.end_time_ < header.start_time_) return false;
  desk_count_ = header.desk_count_;
  return true;
}

bool DataValidityChecker::CheckEventData(ParsedEvent event){
  if(event.time_ < last_checked_time_) return false;
  last_checked_time_ = event.time_;
  if(event.desk_index_ >= desk_count_) return false;
  return true;
}
