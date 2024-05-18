#ifndef PARSED_EVENT_H
#define PARSED_EVENT_H

#include "event.h"
#include "client.h"

struct ParsedEvent{
  const Time time_;
  const Event event_;
  const Client client_;
  const int table_index_;
  ParsedEvent(Time time, Event event, Client client, int index);
  ParsedEvent(Time time, Event event, Client client);
};

#endif // PARSED_EVENT_H
