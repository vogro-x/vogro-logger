#include <iostream>
#include "../logger.hpp"
#include "../policy.hpp"
#include "../severity.hpp"


class FileLogger{
    private:
        Logger<TerminalPolicy> file_logger=Logger<TerminalPolicy>::getLoggerInstance("vogro.log");;
    public:
    
    template<typename... Args>
    void LOG_INFO(const Args& ...args){
        file_logger.template PrintLog<severity_type::info>(args...);
    }

    template<typename... Args>
    void LOG_DEBUG(const Args& ...args){
        file_logger.template PrintLog<severity_type::debug>(args...);
    }

    template<typename... Args>
    void LOG_WARN(const Args& ...args){
        file_logger.template PrintLog<severity_type::warn>(args...);
    }

    template<typename... Args>
    void LOG_ERROR(const Args& ...args){
        file_logger.template PrintLog<severity_type::warn>(args...);
    }
};


class TerminalLogger{
    private:
        Logger<FilePolicy> file_logger=Logger<FilePolicy>::getLoggerInstance("vogro.log");;
    public:
    
    template<typename... Args>
    void LOG_INFO(const Args& ...args){
        file_logger.template PrintLog<severity_type::info>(args...);
    }

    template<typename... Args>
    void LOG_DEBUG(const Args& ...args){
        file_logger.template PrintLog<severity_type::debug>(args...);
    }

    template<typename... Args>
    void LOG_WARN(const Args& ...args){
        file_logger.template PrintLog<severity_type::warn>(args...);
    }

    template<typename... Args>
    void LOG_ERROR(const Args& ...args){
        file_logger.template PrintLog<severity_type::warn>(args...);
    }
};


int main (void){
    FileLogger f_log;
    f_log.LOG_INFO("aaa","jjjj",200);
    
    TerminalLogger t_log;
    t_log.LOG_WARN("hdfgfh",25,"kj");



    return 0;
}