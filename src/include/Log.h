#pragma once

#include <string>
#include <source_location>

namespace log {
  /**
   * @brief Outputs a message directory into the log file
   * @param message Message to output into the log file
   */
  void output(const std::string& message);

  /**
   * @brief Logs a critical message and shutdown the server
   * @param message Message to output
   */
  void critical(const std::string& message, const std::source_location& location = std::source_location::current());

  /**
   * @brief Logs an error message
   * @param message Message to output
   */
  void error(const std::string& message, const std::source_location& location = std::source_location::current());

  /**
  * @brief Logs a warning message
  * @param message Message to output
  */
  void warning(const std::string& message, const std::source_location& location = std::source_location::current());

  /**
    * @brief Logs an information message
    * @param message Message to output
    */
  void info(const std::string& message, const std::source_location& location = std::source_location::current());
}