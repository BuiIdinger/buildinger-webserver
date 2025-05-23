#include <iostream>
#include "Network.h"

void shutdown(const int& code) noexcept {
  network::socket::destroy();
  exit(code);
}

int main() {
  network::socket::setup();

  std::cout << "Hello, World!" << std::endl;
  return 0;
}