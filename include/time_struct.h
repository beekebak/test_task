#ifndef TIME_H
#define TIME_H

#include <string>

struct Time{
  int time_value;
  Time(int hours, int minutes);
  Time(int time);
  Time(std::string time);
  Time operator+ (const Time& time);
  Time operator- (const Time& time);
};

#endif // TIME_H
