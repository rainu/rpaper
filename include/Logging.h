#ifndef _LOGGING_H_
#define _LOGGING_H_

#include "Config.h"

class Log {
 public:
  template<typename T>
  static void debug(T message);

  template<typename T>
  static void info(T message);

  template<typename T>
  static void warn(T message);

  template<typename T>
  static void error(T message);
};

template<typename T>
void Log::debug(T message) {
#if LOG_LEVEL <= LOG_LEVEL_DBUG
  Serial.print("[DEBUG] ");
  Serial.println(message);
#endif
}

template<typename T>
void Log::info(T message) {
#if LOG_LEVEL <= LOG_LEVEL_INFO
  Serial.print("[INFO] ");
  Serial.println(message);
#endif
}

template<typename T>
void Log::warn(T message) {
#if LOG_LEVEL <= LOG_LEVEL_WARN
  Serial.print("[WARN] ");
  Serial.println(message);
#endif
}

template<typename T>
void Log::error(T message) {
#if LOG_LEVEL <= LOG_LEVEL_ERROR
  Serial.print("[ERROR] ");
  Serial.println(message);
#endif
}

#endif /* _LOGGING_H_ */
