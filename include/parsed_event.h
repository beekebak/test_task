#ifndef PARSED_EVENT_H
#define PARSED_EVENT_H

#include <string.h>
#include "event.h"
#include "time_struct.h"

/**
 * @brief Contains data from correct input event line.
 *
 * All members are const since data from event can't be changed.
 * Some events don't introduce any table index so it is setted to unreacheable
 * value in such cases.
 * In other cases constructor with all parameters should be used.
 * Operators used for tests.
 */

struct ParsedEvent{
  Time time_;
  Event event_;
  std::string client_;
  int desk_index_;
  ParsedEvent(Time time, Event event, std::string& client, int index);
  ParsedEvent(Time time, Event event, std::string& client);
  bool operator==(const ParsedEvent& other) const;
  bool operator!=(const ParsedEvent& other) const;
};

#endif // PARSED_EVENT_H
