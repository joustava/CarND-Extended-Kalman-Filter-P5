# Testing library
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.3)
FetchContent_MakeAvailable(Catch2)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(${TEST_LIB_NAME}
  support.cpp
  FusionEKF_tests.cpp
  Tools_tests.cpp
  KalmanFilter_tests.cpp
  kalman/kalman_tests.cpp
  # utils/cli_tests.cpp

)

# I'm using C++17 in the test
target_compile_features(${TEST_LIB_NAME} PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(${TEST_LIB_NAME} PRIVATE "${LIB_NAME}" Catch2::Catch2)
