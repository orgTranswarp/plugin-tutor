project(plugin_tutor)

add_executable(app_0 app_0/app_0.cpp include/common.h)

add_executable(app_1 app_1/app_1.cpp include/common.h)

add_executable(app_2 app_2/app_2.cpp include/common.h)
target_link_libraries(app_2 ${CMAKE_DL_LIBS})

add_library(plugin_2 SHARED plugin_2/plugin_2.cpp include/common.h)

add_executable(app_3 app_3/app_3.cpp include/common.h sdk_3/sdk_3.h)
target_link_libraries(app_3 ${CMAKE_DL_LIBS})

add_library(sdk_3 sdk_3/sdk_3.cpp sdk_3/sdk_3.h include/common.h)

add_library(plugin_3 SHARED plugin_3/plugin_3.cpp include/common.h)
target_link_libraries(plugin_3 sdk_3)

add_executable(app_4 app_4/app_4.cpp include/common.h sdk_4/sdk_4.h)
target_link_libraries(app_4 ${CMAKE_DL_LIBS})

add_library(sdk_4 sdk_4/sdk_4.cpp sdk_4/sdk_4.h include/common.h)

add_library(plugin_4 SHARED plugin_4/plugin_4.cpp include/common.h)
target_link_libraries(plugin_4 sdk_4)
