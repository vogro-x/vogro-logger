# [vogro-logger](https://github.com/vogro-xx/vogro-logger)
the logger module of vogro.

## run test
``` bash
$ cd vogro-logger/test && make logger
```

## usage
``` c++
#include "../include/vogro_logger.hpp"

int main(void) {

  Logger<FilePolicy> &file_logger =
      Logger<FilePolicy>::getLoggerInstance("vogro.log");
  for (auto i = 0; i < 10; i++) {
    file_logger.LOG_INFO("hello", "vogro-logger");
    file_logger.LOG_DEBUG("hello", "vogro-logger");
    file_logger.LOG_WARN("hello", "vogro-logger");
    file_logger.LOG_ERROR("hello", "vogro-logger");
  }

  Logger<TerminalPolicy> &terminal_logger =
      Logger<TerminalPolicy>::getLoggerInstance("placehold");
  for (auto i = 0; i < 10; i++) {
    terminal_logger.LOG_INFO("hello", "vogro-logger", 200);
    terminal_logger.LOG_DEBUG("hello", "vogro-logger", 200);
    terminal_logger.LOG_WARN("hello", "vogro-logger", 200);
    terminal_logger.LOG_ERROR("hello", "vogro-logger", 200);
  }

  return 0;
}

```