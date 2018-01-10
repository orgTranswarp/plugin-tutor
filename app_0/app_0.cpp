#include <iostream>

std::string sth("something");

void say_sth() {
  std::cout << sth << std::endl;
}

int main() {
  say_sth();

  return 0;
}