#include "time_struct.h"

Time::Time(int hours, int minutes){
  time_value = hours*60+minutes;
}

Time::Time(int time){
  time_value = time;
}

Time::Time(std::string time){
  int hours = std::stoi(time.substr(0, 2));
  int minutes = std::stoi(time.substr(3, 5));
  time_value = hours*60+minutes;
}

Time Time::operator+(const Time& time){
  return Time{time_value+time.time_value};
}

Time Time::operator-(const Time& time){
  return Time{time_value-time.time_value};
}

bool Time::operator== (const Time& other) const{
  return other.time_value == time_value;
}

bool Time::operator!= (const Time& other) const{
  return !(*(this) == other);
}

std::string Time::ToString(){
  int hours = time_value / 60;
  int minutes = time_value % 60;
  std::string hours_representation = hours > 9 ? std::to_string(hours) :
                                         "0"+std::to_string(hours);
  std::string minutes_representation = minutes > 9 ? std::to_string(minutes) :
                                         "0"+std::to_string(minutes);
  return hours_representation + ":" + minutes_representation;
}
