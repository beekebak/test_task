#ifndef EVENT_H
#define EVENT_H

#include <string>

/**
 * @brief Contains all event types both input and output.
 */

enum class Event{
  kArrival=1,
  kSit=2,
  kWait=3,
  kLeft=4,
  kDayEndOrLeft=11,
  kTookFreeDesk=12,
  kError=13
};

#endif // EVENT_H
