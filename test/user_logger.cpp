#include <iostream>
#include "../logger.hpp"
#include "../policy.hpp"
#include "../severity.hpp"


class UseLogger{
    private:
        Logger<TerminalPolicy> file_logger=Logger<TerminalPolicy>::getLoggerInstance("vogro.log");;
    public:
    
    void LOG_INFO(){
        file_logger.template PrintLog<severity_type::info>("hh",2);
    }
};

int main (void){
    UseLogger log;
    log.LOG_INFO();



    return 0;
}