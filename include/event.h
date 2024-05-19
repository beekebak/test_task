#ifndef EVENT_H
#define EVENT_H

#include <string>

enum class Event{
  kArrival=1,
  kSit=2,
  kWait=3,
  kLeft=4,
  kDayEnd=11,
  kTookFreeTable=12,
  kError=13
};

#endif // EVENT_H
