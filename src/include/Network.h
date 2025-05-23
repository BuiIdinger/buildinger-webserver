#pragma once

#include <netinet/in.h>

namespace network {
  namespace socket {
    /**
     * Sockets for HTTP and HTTPs
     */
    inline int httpFd = -1;
    inline int httpsFd = -1;

    /**
     * Addresses for both sockets
     */
    inline sockaddr_in httpFdAddress;
    inline sockaddr_in httpsFdAddress;

    /**
     * The amount of events that can be in
     * the OS's queue
     */
    constexpr int backlog = 1024;

    /**
     * Ports of HTTP and HTTPs
     */
    constexpr int httpPort = 80;
    constexpr int httpsPort = 443;

    /**
     * Allow reusing of the same address when binding them
     */
    constexpr int reuse = 1;

    /**
     * Setups the HTTP and HTTPS sockets ready for the main loop
     */
    void setup() noexcept;

    /**
     * Creates the HTTP and HTTPS sockets
     * @note Will shut down the server if operation fails
     */
    void create() noexcept;

    /**
     * Configures the HTTP and HTTPS sockets, sets reuse option, sets both
     * sockets to non-blocking, and setups socket addresses
     * @note Will shut down the server if operation fails
     */
    void configure() noexcept;

    /**
     * Binds both the HTTP and HTTPS sockets
     * @note Will shut down the server if operation fails
     */
    void bind() noexcept;

    /**
     * Listens both the HTTP and HTTPS sockets
     * @note Will shut down the server if operation fails
     */
    void listen() noexcept;

    /**
     * @brief Sets a socket to non-blocking mode
     * @param fd Socket to set to non-blocking mode
     */
    bool setNonBlocking(const int& fd) noexcept;

    /**
     * Destroy both sockets by closing them, and setting them their value to -1
     */
    void destroy() noexcept;
  }
}