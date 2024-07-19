#ifndef SIMULATIONMETADATA_H
#define SIMULATIONMETADATA_H

#include "time_struct.h"

/**
 * @brief Contains data from correct file header.
 *
 * All members are const since data from header can't be changed.
 * Operators used for tests.
 */

struct SimulationMetadata{
 public:
  int desk_count_;
  Time start_time_;
  Time end_time_;
  int hourly_rate_;
  SimulationMetadata(int desk_count, Time start_time, Time end_time,
                     int hourly_rate);
  SimulationMetadata(SimulationMetadata&& other) = default;
  SimulationMetadata(SimulationMetadata& other) = default;
  bool operator== (const SimulationMetadata& other) const;
  bool operator!= (const SimulationMetadata& other) const;
};

#endif // SIMULATIONMETADATA_H
