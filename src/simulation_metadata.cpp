#include "simulation_metadata.h"

SimulationMetadata::SimulationMetadata(int table_count, Time start_time,
                                       Time end_time, int hourly_rate):
                    table_count_(table_count), start_time_(start_time),
                    end_time_(end_time), hourly_rate_(hourly_rate){}
