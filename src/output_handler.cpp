#include "output_handler.h"
#include "error_handler.h"

void OutputHandler::PrintEvent(Time event_time, Event event_code,
                          std::string client_name, int table_index){
  if(event_code == Event::kSit && event_code == Event::kTookFreeTable){
    std::cout << event_time.ToString() << " " << static_cast<int>(event_code)
              << " " << client_name << " " << table_index << std::endl;
  }
  else{
    std::cout << event_time.ToString() << " " << static_cast<int>(event_code)
              << " " << client_name << std::endl;
  }
}

void OutputHandler::PrintError(Time event_time, Error error_code){
  std::cout << event_time.ToString() + " 13 " <<
      ErrorHandler::GetErrorMessage(error_code) << std::endl;
}

void OutputHandler::PrintTime(Time event_time){
  std::cout << event_time.ToString() << std::endl;
}

void OutputHandler::PrintEndOfDayData(std::vector<Table> tables){
  for(int i = 0; i < tables.size(); i++){
    std::cout << i+1 << " " << tables[i].earned_money << " " <<
        tables[i].used_time.ToString() << std::endl;
  }
}
