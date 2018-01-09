#include "sdk_4.h"

__API__ sth_service *g_sth_service;

__INTERNAL__ callback_f_type *__callbacks;

__INTERNAL__ extern "C" void __init(sth_service *sth_service, callback_f_type *callbacks) {
  g_sth_service = sth_service;
  __callbacks = callbacks;
  init();
}

__UTILITY__ void register_callback(event e, callback_f_type callback) {
  __callbacks[e] = callback;
}
