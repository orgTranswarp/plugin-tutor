#ifndef PLUGIN_TUTOR_SDK_3_H
#define PLUGIN_TUTOR_SDK_3_H

#include <string>

typedef const std::string& (*get_sth_f_type)();
extern get_sth_f_type get_sth;

typedef void (*set_sth_f_type)(const std::string&);
extern set_sth_f_type set_sth;


typedef void (*__init_f_type)(get_sth_f_type, set_sth_f_type);
extern "C" void __init(get_sth_f_type, set_sth_f_type);

#endif //PLUGIN_TUTOR_SDK_3_H
