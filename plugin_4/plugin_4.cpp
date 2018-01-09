#include <iostream>
#include "../include/common.h"
#include "../sdk_4/sdk_4.h"

__CALLBACK__ int before_say_sth(void *payload) {
  const std::string &sth = g_sth_service->get_sth();
  if (sth == "something") {
    g_sth_service->set_sth("nothing");
  }

  std::cout << "I think," << std::endl;

  return 0;
}

__CALLBACK__ int after_say_sth(void *payload) {
  std::cout << "is wrong." << std::endl;

  return 0;
}

__PROTOCOL__ void init() {
  register_callback(BEFORE_SAY_STH_EVENT, before_say_sth);
  register_callback(AFTER_SAY_STH_EVENT, after_say_sth);
}
