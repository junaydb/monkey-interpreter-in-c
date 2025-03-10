#include "logger.h"
#include <stdio.h>

void logger(const char *message, enum LogType log_type) {
  const char *color_code;

  switch (log_type) {
  case ERROR:
    color_code = "\033[0;31m"; // Red
    break;
  case SUCCESS:
    color_code = "\033[0;32m"; // Green
    break;
  case WARNING:
    color_code = "\033[0;33m"; // Yellow
    break;
  default:
    color_code = "\033[0m"; // Reset to default color
  }

  printf("%s%s\033[0m\n", color_code, message);
}
