add_executable("${APP_NAME}" main.cpp)
target_compile_features("${APP_NAME}" PRIVATE cxx_std_17)

target_link_libraries(
  "${APP_NAME}"
  PRIVATE
  "${LIB_NAME}"
  z
  ssl
  uv
  uWS
  nlohmann_json::nlohmann_json
  Eigen3::Eigen
)
