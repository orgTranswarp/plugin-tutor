#include <iostream>
#include <dlfcn.h>
#include "../include/common.h"

std::string g_sth("something");

__NOTE__
typedef void (*f_type)();
f_type g_f_plugin_before_say_sth, g_f_plugin_after_say_sth;

__NOTE__
void load_plugin() {
  void *handle = dlopen("./libplugin_2." SO_SUFFIX, RTLD_LAZY);
  g_f_plugin_before_say_sth = (f_type) dlsym(handle, "before_say_sth");
  g_f_plugin_after_say_sth = (f_type) dlsym(handle, "after_say_sth");
}

void before_say_sth() {
  __NOTE__
  g_f_plugin_before_say_sth();
}

void after_say_sth() {
  __NOTE__
  g_f_plugin_after_say_sth();
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
  __NOTE__
  load_plugin();

  before_say_sth();

  say_sth();

  after_say_sth();
  return 0;
}
