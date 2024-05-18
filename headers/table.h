#ifndef TABLE_H
#define TABLE_H

#include "time.h"

class Table{
 private:
  bool client_is_present = false;
  Time used_time = Time(0,0);
  int earned_money = 0;
};

#endif // TABLE_H
