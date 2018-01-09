#include <iostream>
#include "../include/common.h"

std::string g_sth("something");

___NOTE_BELOW___
void before_say_sth() {
  std::cout << "I think," << std::endl;
}

___NOTE_BELOW___
void after_say_sth() {
  std::cout << "is wrong." << std::endl;
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
  ___NOTE_BELOW___
  before_say_sth();

  say_sth();

  ___NOTE_BELOW___
  after_say_sth();
  return 0;
}
