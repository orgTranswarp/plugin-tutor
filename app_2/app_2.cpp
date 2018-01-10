#include <iostream>
#include <dlfcn.h>
#include "../include/common.h"

std::string g_sth("something");

XX typedef void (*f_type)();
XX f_type g_f_plugin_before_say_sth, g_f_plugin_after_say_sth;

XX void load_plugin() {
XX   void *handle = dlopen("./libplugin_2." SO_SUFFIX, RTLD_LAZY);
XX   g_f_plugin_before_say_sth = (f_type) dlsym(handle, "before_say_sth");
XX   g_f_plugin_after_say_sth = (f_type) dlsym(handle, "after_say_sth");
XX }

void before_say_sth() {
XX g_f_plugin_before_say_sth();
}

void after_say_sth() {
XX g_f_plugin_after_say_sth();
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
XX load_plugin();

  before_say_sth();

  say_sth();

  after_say_sth();

  return 0;
}
