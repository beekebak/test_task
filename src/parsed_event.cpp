#include "parsed_event.h"


ParsedEvent::ParsedEvent(Time time, Event event, std::string client, int index):
                         time_(time), event_(event),
                         client_(client), table_index_(index){}
ParsedEvent::ParsedEvent(Time time, Event event, std::string client):
                         ParsedEvent(time, event, client, -1){}

bool ParsedEvent::operator==(const ParsedEvent& other) const{
  return (other.event_ == event_ && other.client_ == client_ &&
          other.table_index_ == table_index_ && other.time_ == time_);
}

bool ParsedEvent::operator!=(const ParsedEvent& other) const{
  return !(other == *(this));
}
