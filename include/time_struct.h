#ifndef TIME_H
#define TIME_H

#include <string>

/**
 * @brief Wrapped integer to represent moment of day.
 */
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
  /**
   * @return string representation in format XX:XX
   */
  std::string ToString();
  /**
   * @return Rounded up past hours count.
   */
  int GetHoursCeil();
};

#endif // TIME_H
