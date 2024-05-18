#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <unordered_map>
#include <string>

class ErrorHandler{
 private:
  static std::unordered_map<int, std::string> errors;
 public:
  std::string GetError(int code){
    return errors[code];
  }
};
#endif // ERROR_HANDLER_H
