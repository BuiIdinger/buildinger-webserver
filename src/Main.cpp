#include <iostream>

void shutdown(const int& code) noexcept {
  exit(code);
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}