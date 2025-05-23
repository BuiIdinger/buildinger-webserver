#include "Log.h"
#include <iostream>
#include "Main.h"

void log::output(const std::string &message) {
  std::cerr << message << std::endl;
}

void log::critical(const std::string &message, const std::source_location &location) {
  output(message);
  shutdown(EXIT_FAILURE);
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