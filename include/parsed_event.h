#ifndef PARSED_EVENT_H
#define PARSED_EVENT_H

#include <string.h>
#include "event.h"
#include "time_struct.h"

struct ParsedEvent{
  const Time time_;
  const Event event_;
  const std::string client_;
  const int table_index_;
  ParsedEvent(Time time, Event event, std::string client, int index);
  ParsedEvent(Time time, Event event, std::string client);
  bool operator==(const ParsedEvent& other) const;
  bool operator!=(const ParsedEvent& other) const;
};

#endif // PARSED_EVENT_H
