#include <iostream>
#include <dlfcn.h>
#include "../include/common.h"

std::string g_sth("something");

___NOTE_BELOW___
typedef void (*f_type)();
f_type g_f_plugin_before_say_sth, g_f_plugin_after_say_sth;

___NOTE_BELOW___
void load_plugin() {
  void *handle = dlopen("./libplugin_2.so", RTLD_LAZY);
  g_f_plugin_before_say_sth = (f_type) dlsym(handle, "before_say_sth");
  g_f_plugin_after_say_sth = (f_type) dlsym(handle, "after_say_sth");
}

void before_say_sth() {
  ___NOTE_BELOW___
  g_f_plugin_before_say_sth();
}

void after_say_sth() {
  ___NOTE_BELOW___
  g_f_plugin_after_say_sth();
}

void say_sth() {
  std::cout << g_sth << std::endl;
}

int main() {
  ___NOTE_BELOW___
  load_plugin();

  before_say_sth();

  say_sth();

  after_say_sth();
  return 0;
}
