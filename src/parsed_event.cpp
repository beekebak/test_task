#include "parsed_event.h"


ParsedEvent::ParsedEvent(Time time, Event event, Client client, int index):
                         time_(time), event_(event),
                         client_(client), table_index_(index){}
ParsedEvent::ParsedEvent(Time time, Event event, Client client):
                         ParsedEvent(time, event, client, -1){}
