#include <iostream>
#include "../sdk_3/sdk_3.h"
#include "../include/common.h"

extern "C" void before_say_sth() {
  __NOTE__
  const std::string &sth = get_sth();
  if (sth == "something") {
    set_sth("nothing");
  }

  std::cout << "I think," << std::endl;
}

extern "C" void after_say_sth() {
  std::cout << "is wrong." << std::endl;
}
