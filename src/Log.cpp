#include "Log.h"
#include <iostream>

void log::output(const std::string &message) {
  std::cerr << message << std::endl;
}

void log::error(const std::string& message, const std::source_location& location) {
  output(message);
}

void log::warning(const std::string& message, const std::source_location& location) {
  output(message);
}

void log::info(const std::string& message, const std::source_location& location) {
  output(message);
}