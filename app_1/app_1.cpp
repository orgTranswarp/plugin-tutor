#include <iostream>
#include "../include/common.h"

std::string g_sth("something");

__NOTE_BELOW__
void before_say_sth() {
  std::cout << "I think," << std::endl;
}

__NOTE_BELOW__
void after_say_sth() {
  std::cout << "is wrong." << std::endl;
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
  __NOTE_BELOW__
  before_say_sth();

  say_sth();

  __NOTE_BELOW__
  after_say_sth();
  return 0;
}
