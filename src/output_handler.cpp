#include "output_handler.h"

void output_handler::PrintEvent(Time event_time, Event event_code,
                          std::string client_name, int desk_index){
  if(event_code == Event::kSit || event_code == Event::kTookFreeDesk){
    std::cout << event_time.ToString() << " " << static_cast<int>(event_code)
              << " " << client_name << " " << desk_index+1 << std::endl;
  }
  else{
    std::cout << event_time.ToString() << " " << static_cast<int>(event_code)
              << " " << client_name << std::endl;
  }
}

void output_handler::PrintError(Time event_time, Error error_code){
  std::cout << event_time.ToString() + " 13 " <<
      error::GetErrorMessage(error_code) << std::endl;
}

void output_handler::PrintTime(Time event_time){
  std::cout << event_time.ToString() << std::endl;
}

void output_handler::PrintEndOfDayData(std::vector<Desk> desks){
  for(int i = 0; i < desks.size(); i++){
    std::cout << i+1 << " " << desks[i].earned_money << " " <<
        desks[i].used_time.ToString() << std::endl;
  }
}

void output_handler::PrintInvalidLine(std::string line){
  std::cout << line << std::endl;
}
