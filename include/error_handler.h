#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "error.h"
#include <string>

class ErrorHandler{
 public:
  std::string GetErrorMessage(Error error);
};

#endif // ERROR_HANDLER_H
