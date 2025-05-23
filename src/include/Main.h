#pragma once

#define UNREACHABLE __builtin_unreachable()

/**
 * @brief Shutdowns sockets, and the server
 * @param code Status code to exit server with
 */
void shutdown(const int& code) noexcept;