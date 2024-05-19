#include "error.h"

std::string error::GetErrorMessage(Error error){
  switch (error){
    case Error::kClosed:
      return "NotOpenYet";
    case Error::kClientAlreadyInClub:
      return "YouShallNotPass";
      break;
    case Error::kDeskIsBusy:
      return "PlaceIsBusy";
      break;
    case Error::kClientUnknown:
      return "ClientUnknown";
      break;
    case Error::kClientCantWait:
      return "ICanWaitNoLonger!";
      break;
  }
  return "";
}
