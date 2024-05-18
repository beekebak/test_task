#ifndef TIME_H
#define TIME_H

struct Time{
  int time_value;
  Time(int hours, int minutes){
    time_value = hours*60+minutes;
  }
};

#endif // TIME_H
