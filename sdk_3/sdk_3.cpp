#include "sdk_3.h"

get_sth_f_type get_sth;
set_sth_f_type set_sth;

extern "C" void __init(get_sth_f_type get_sth_f, set_sth_f_type set_sth_f) {
  get_sth = get_sth_f;
  set_sth = set_sth_f;
}
