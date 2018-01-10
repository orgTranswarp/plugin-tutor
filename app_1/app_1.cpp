#include <iostream>
#include "../include/common.h"

std::string g_sth("something");

XX void before_say_sth() {
XX   std::cout << "I think," << std::endl;
XX }

XX void after_say_sth() {
XX   std::cout << "is wrong." << std::endl;
XX }

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
XX before_say_sth();

  say_sth();

XX after_say_sth();

  return 0;
}
