#include<iostream>

int main () {
  std::cout << 100 << std::endl;
  std::cout << 0100 << std::endl;     // surprise, octal
  std::cout << 0x100 << std::endl;    // hexadecimal
  std::cout << 0b100 << std::endl;    // binary, C++14
  std::cout << 100e4 << std::endl;    // scientific
  std::cout << 100e-4 << std::endl;   // scientific
  std::cout << 123'456'789'012 << std::endl;  // ' separator, C++14
}
