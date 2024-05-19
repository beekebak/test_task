#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "error.h"
#include <iostream>

class ErrorHandler{
 public:
  std::string static GetErrorMessage(Error error);
};

#endif // ERROR_HANDLER_H
