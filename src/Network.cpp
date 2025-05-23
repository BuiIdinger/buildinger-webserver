#include "Network.h"
#include <sys/socket.h>
#include "Log.h"
#include "Main.h"
#include <fcntl.h>
#include <unistd.h>

void network::socket::setup() noexcept {
  create();
  configure();
  bind();
  listen();
}

bool network::socket::setNonBlocking(const int& fd) noexcept {
  // Get current flags set on this socket
  const int flags = fcntl(fd, F_GETFL, 0);
  if (flags == -1) {
    log::error(std::strerror(errno));
    return false;
  }

  // Add previous flags along with non-block flag
  if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
    log::error(std::strerror(errno));
    return false;
  }

  return true;
}

void network::socket::create() noexcept {
  httpFd = ::socket(AF_INET, SOCK_STREAM, 0);
  if (httpFd == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }

  httpsFd = ::socket(AF_INET, SOCK_STREAM, 0);
  if (httpsFd == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }
}

void network::socket::configure() noexcept {
  // Allow reusing of the same address
  if (setsockopt(httpFd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }

  if (setsockopt(httpsFd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }

  // Set both sockets to non-blocking mode
  if (!setNonBlocking(httpFd)) {
    log::critical("Failed to set HTTP socket to non-blocking mode");
    UNREACHABLE;
  }

  if (!setNonBlocking(httpsFd)) {
    log::critical("Failed to set HTTPS socket to non-blocking mode");
    UNREACHABLE;
  }

  // Configure sockets
  httpFdAddress.sin_family = AF_INET;
  httpFdAddress.sin_addr.s_addr = INADDR_ANY;
  httpFdAddress.sin_port = htons(httpPort);

  httpsFdAddress.sin_family = AF_INET;
  httpsFdAddress.sin_addr.s_addr = INADDR_ANY;
  httpsFdAddress.sin_port = htons(httpsPort);
}

void network::socket::listen() noexcept {
  if (::listen(httpFd, backlog) == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }

  if (::listen(httpsFd, backlog) == -1) {
    log::critical(std::strerror(errno));
    UNREACHABLE;
  }
}

void network::socket::bind() noexcept {
  if (bind(httpFd, reinterpret_cast<sockaddr*>(&httpFdAddress), sizeof(httpFdAddress)) == -1) {
    log::critical(std::strerror(errno));
  }

  if (bind(httpsFd, reinterpret_cast<sockaddr*>(&httpsFdAddress), sizeof(httpsFdAddress)) == -1) {
    log::critical(std::strerror(errno));
  }
}

void network::socket::destroy() noexcept {
  close(httpFd);
  close(httpsFd);

  httpFd = -1;
  httpsFd = -1;
}
