#ifndef ERROR_H
#define ERROR_H

#include <string>

/**
 * @brief Contains all error types which could occure during runtime.
 */

enum class Error{
  kClosed,
  kClientAlreadyInClub,
  kDeskIsBusy,
  kClientUnknown,
  kClientCantWait
};

namespace error{
  /**
   * @brief returns string representaion of error
   */
  std::string GetErrorMessage(Error error);
}

#endif // ERROR_H
