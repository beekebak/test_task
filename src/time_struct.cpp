#include "time_struct.h"

Time::Time(int hours, int minutes){
  time_value_ = hours*60+minutes;
}

Time::Time(int time){
  time_value_ = time;
}

Time::Time(std::string time){
  int hours = std::stoi(time.substr(0, 2));
  int minutes = std::stoi(time.substr(3, 5));
  time_value_ = hours*60+minutes;
}

Time Time::operator+(const Time& time){
  return Time{time_value_+time.time_value_};
}

Time Time::operator-(const Time& time){
  return Time{time_value_-time.time_value_};
}

bool Time::operator== (const Time& other) const{
  return other.time_value_ == time_value_;
}

bool Time::operator!= (const Time& other) const{
  return !(*(this) == other);
}

Time Time::operator+= (const Time& time){
  time_value_ += time.time_value_;
  return(*this);
}

Time Time::operator= (const Time& time){
  time_value_ = time.time_value_;
  return(*this);
}

bool Time::operator< (const Time& time) const{
  return time_value_ < time.time_value_;
}

std::string Time::ToString(){
  int hours = time_value_ / 60;
  int minutes = time_value_ % 60;
  std::string hours_representation = hours > 9 ? std::to_string(hours) :
                                         "0"+std::to_string(hours);
  std::string minutes_representation = minutes > 9 ? std::to_string(minutes) :
                                         "0"+std::to_string(minutes);
  return hours_representation + ":" + minutes_representation;
}

int Time::GetHoursCeil(){
  int res = time_value_/60;
  if(time_value_%60>0) res++;
  return res;
}
