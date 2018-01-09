project(plugin_tutor)

add_executable(app_0 app_0/app_0.cpp include/common.h)
add_executable(app_1 app_1/app_1.cpp include/common.h)
add_executable(app_2 app_2/app_2.cpp include/common.h)
target_link_libraries(app_2 ${CMAKE_DL_LIBS})
add_library(plugin_2 SHARED plugin_2/plugin_2.cpp include/common.h)
