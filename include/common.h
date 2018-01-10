#ifndef PLUGIN_TUTOR_COMMON_H
#define PLUGIN_TUTOR_COMMON_H

#if defined(__APPLE__)
#define SO_SUFFIX "dylib"
#elif defined(__linux__)
#define SO_SUFFIX "so"
#endif

#define __NOTE__

#define __INTERNAL__
#define __API__
#define __CALLBACK__
#define __PROTOCOL__
#define __UTILITY__

#endif //PLUGIN_TUTOR_COMMON_H
