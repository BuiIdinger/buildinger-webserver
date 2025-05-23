#pragma once

#include <string>
#include <source_location>

namespace log {
  void output(const std::string& message);

  void error(const std::string& message, const std::source_location& location = std::source_location::current());
  void warning(const std::string& message, const std::source_location& location = std::source_location::current());
  void info(const std::string& message, const std::source_location& location = std::source_location::current());
}