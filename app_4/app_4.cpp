#include <iostream>
#include <dlfcn.h>
#include "../include/common.h"
#include "../sdk_4/sdk_4.h"

std::string g_sth("something");

void say_sth() {
  std::cout << g_sth << std::endl;
}

__API__ class sth_service_impl : public sth_service {
public:
  __API__ const std::string& get_sth() {
    return g_sth;
  }

  __API__ void set_sth(const std::string& sth) {
    g_sth = sth;
  }
} g_sth_service_impl;

callback_f_type g_callbacks[EVENT_SIZE];

int trigger_event(event e, void *payload) {
  return g_callbacks[e](payload);
}

void load_plugin() {
  void *handle = dlopen("./libplugin_4." SO_SUFFIX, RTLD_LAZY);
  __init_f_type init_f = (__init_f_type) (dlsym(handle, "__init"));
  init_f(&g_sth_service_impl, g_callbacks);
}

int main() {
  load_plugin();

  trigger_event(EVENT_BEFORE_SAY_STH, NULL);

  say_sth();

  trigger_event(EVENT_AFTER_SAY_STH, NULL);

  return 0;
}
