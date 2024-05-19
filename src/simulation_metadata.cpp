#include "simulation_metadata.h"

SimulationMetadata::SimulationMetadata(int desk_count, Time start_time,
                                       Time end_time, int hourly_rate):
                    desk_count_(desk_count), start_time_(start_time),
                    end_time_(end_time), hourly_rate_(hourly_rate){}

bool SimulationMetadata::operator==(const SimulationMetadata& other) const{
  return(other.end_time_ == end_time_ && other.start_time_ == start_time_ &&
     other.hourly_rate_ == hourly_rate_ && other.desk_count_ == desk_count_);
}

bool SimulationMetadata::operator!=(const SimulationMetadata& other) const{
  return !(other == *(this));
}
