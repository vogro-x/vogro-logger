#include <iostream>
#include "../logger.hpp"
#include "../policy.hpp"
#include "../severity.hpp"


int main (void){
    
    auto file_logger=Logger<FilePolicy>::getLoggerInstance("vogro.log");
    for(auto i = 0; i<10; i++){
        file_logger.PrintLog<severity_type::info>("hello, vogro-logger");
        file_logger.PrintLog<severity_type::debug>("hello, vogro-logger");
        file_logger.PrintLog<severity_type::warn>("hello, vogro-logger");
        file_logger.PrintLog<severity_type::error>("hello, vogro-logger");

    }

    auto terminal_logger=Logger<TerminalPolicy>::getLoggerInstance("placehold");
    for(auto i=0; i<10; i++){
        terminal_logger.PrintLog<severity_type::info>("hello, vogro-logger","OK",200);
        terminal_logger.PrintLog<severity_type::debug>("hello, vogro-logger","OK",200);
        terminal_logger.PrintLog<severity_type::warn>("hello, vogro-logger","OK",200);
        terminal_logger.PrintLog<severity_type::error>("hello, vogro-logger","OK",200);
    }

    return 0;
}