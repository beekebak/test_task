#ifndef SIMULATIONMETADATA_H
#define SIMULATIONMETADATA_H

#include "time_struct.h"

struct SimulationMetadata{
 public:
  const int table_count_;
  const Time start_time_;
  const Time end_time_;
  const int hourly_rate_;
  SimulationMetadata(int table_count, Time start_time, Time end_time,
                     int hourly_rate);
};

#endif // SIMULATIONMETADATA_H
