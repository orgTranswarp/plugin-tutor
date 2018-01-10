#include <iostream>
#include <dlfcn.h>
#include "../include/common.h"
#include "../sdk_3/sdk_3.h"

std::string g_sth("something");

typedef void (*f_type)();
f_type g_f_plugin_before_say_sth, g_f_plugin_after_say_sth;

__NOTE__
const std::string& _get_sth() {
  return g_sth;
}

__NOTE__
void _set_sth(const std::string& sth) {
  g_sth = sth;
}

void load_plugin() {
  void *handle = dlopen("./libplugin_3." SO_SUFFIX, RTLD_LAZY);
  g_f_plugin_before_say_sth = (f_type) dlsym(handle, "before_say_sth");
  g_f_plugin_after_say_sth = (f_type) dlsym(handle, "after_say_sth");

  __NOTE__
  __init_f_type init_f = (__init_f_type) dlsym(handle, "__init");
  init_f(_get_sth, _set_sth);
}

void before_say_sth() {
  g_f_plugin_before_say_sth();
}

void after_say_sth() {
  g_f_plugin_after_say_sth();
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
  load_plugin();

  before_say_sth();

  say_sth();

  after_say_sth();

  return 0;
}
