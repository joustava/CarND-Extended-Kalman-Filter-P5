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
  kalman/kalman_tests.cpp
  utils/cli_tests.cpp
  utils/bus_tests.cpp
  )
# add_executable(${TEST_LIB_NAME}_utils
#   support.cpp
#   utils/cli_tests.cpp
#   # kalman/kalman_tests.cpp
# )

# I'm using C++17 in the test
target_compile_features(${TEST_LIB_NAME} PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(${TEST_LIB_NAME} PRIVATE "${LIB_NAME}" Catch2::Catch2)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
# this doesnt seem to work correctly with multiple tests?
# add_test(NAME ${TEST_LIB_NAME} COMMAND ${TEST_LIB_NAME}) # Command can be a target