#ifndef TIME_H
#define TIME_H

#include <string>

struct Time{
  int time_value_;
  Time(int hours, int minutes);
  Time(int time);
  Time(std::string time);
  Time operator+ (const Time& time);
  Time operator+= (const Time& time);
  Time operator= (const Time& time);
  bool operator< (const Time& time) const;
  Time operator- (const Time& time);
  bool operator== (const Time& other) const;
  bool operator!= (const Time& other) const;
  std::string ToString();
  int GetHoursCeil();
};

#endif // TIME_H
