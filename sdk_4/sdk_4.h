#ifndef PLUGIN_TUTOR_SDK_3_H
#define PLUGIN_TUTOR_SDK_3_H

#include <string>
#include "../include/common.h"

__API__ class sth_service {
public:
  __API__ virtual const std::string& get_sth() = 0;
  __API__ virtual void set_sth(const std::string&) = 0;
};

__PROTOCOL__ enum event{
  BEFORE_SAY_STH_EVENT = 0,
  AFTER_SAY_STH_EVENT,
  LAST_EVENT,
};

typedef int (*callback_f_type)(void *);

__UTILITY__ void register_callback(event, callback_f_type);

__API__ extern sth_service *g_sth_service;

typedef void (*__init_f_type)(sth_service *, callback_f_type *callbacks);
__INTERNAL__ extern "C" void __init(sth_service *, callback_f_type *callbacks);


__PROTOCOL__ void init();

#endif //PLUGIN_TUTOR_SDK_3_H
