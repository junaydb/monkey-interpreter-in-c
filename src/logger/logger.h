#ifndef LOGGER_H
#define LOGGER_H

enum LogType { ERROR, SUCCESS, WARNING };

void logger(const char *message_title, const char *message,
            enum LogType log_type);

#endif
