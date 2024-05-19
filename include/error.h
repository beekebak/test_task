#ifndef ERROR_H
#define ERROR_H

enum class Error{
  kClosed,
  kClientAlreadyInClub,
  kTableIsBusy,
  kClientUnknown,
  kClientCantWait
};

#endif // ERROR_H
