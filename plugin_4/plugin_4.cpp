#include <iostream>
#include "../include/common.h"
#include "../sdk_4/sdk_4.h"

__CALLBACK__ int on_event_before_say_sth(void *payload) {
  const std::string &sth = g_sth_service->get_sth();
  if (sth == "something") {
    g_sth_service->set_sth("nothing");
  }

  std::cout << "I think," << std::endl;

  return 0;
}

__CALLBACK__ int on_event_after_say_sth(void *payload) {
  std::cout << "is wrong." << std::endl;

  return 0;
}

__PROTOCOL__ void init() {
  register_callback(EVENT_BEFORE_SAY_STH, on_event_before_say_sth);
  register_callback(EVENT_AFTER_SAY_STH, on_event_after_say_sth);
}
