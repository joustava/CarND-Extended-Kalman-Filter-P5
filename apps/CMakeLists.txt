add_executable("${APP_NAME}" app.cpp)
target_compile_features("${APP_NAME}" PRIVATE cxx_std_17)

target_link_libraries("${APP_NAME}" PRIVATE "${LIB_NAME}" fmt::fmt)
