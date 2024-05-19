#ifndef ERROR_H
#define ERROR_H

enum class Error{
  kNoError,
  kClosed,
  kClientAlreadyInClub,
  kTableIsBusy,
  kClientUnknown,
  kClientCantWait
};

#endif // ERROR_H
