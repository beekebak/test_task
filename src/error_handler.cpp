#include "error_handler.h"

std::string ErrorHandler::GetErrorMessage(Error error){
  switch (error){
   case Error::kNoError:
    break;
   case Error::kClosed:
    return "NotOpenYet";
   case Error::kClientAlreadyInClub:
    return "YouShallNotPass";
    break;
   case Error::kTableIsBusy:
    return "PlaceIsBusy";
    break;
   case Error::kClientUnknown:
    return "ClientUnknown";
    break;
   case Error::kClientCantWait:
    return "ICanWaitNoLonger";
    break;
  }
  return "";
}
