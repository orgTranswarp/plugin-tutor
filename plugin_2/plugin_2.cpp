#include <iostream>

extern "C" void before_say_sth() {
  std::cout << "I think," << std::endl;
}

extern "C" void after_say_sth() {
  std::cout << "is wrong." << std::endl;
}
