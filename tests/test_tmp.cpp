#include <iostream>
#include <yls/tmp.hpp>

int main() {
  if (::yls::TMP::parse() != 0) {
    std::cerr << "parse() failed\n";
    return 1;
  }
  if (::yls::TMP::stringify() != 0) {
    std::cerr << "stringify() failed\n";
    return 1;
  }

  std::cout << "All tests passed.\n";
  return 0;
}