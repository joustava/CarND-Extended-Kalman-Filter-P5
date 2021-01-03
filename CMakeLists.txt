# Works with 3.11 and tested through 3.19
cmake_minimum_required(VERSION 3.19)

# Project name and a few useful settings. Other commands can pick up the results
project(
  ExtendedKF
  VERSION 0.0.4
  DESCRIPTION "An example project with CMake"
  LANGUAGES CXX)


set(APP_NAME ${PROJECT_NAME}_APP)
set(LIB_NAME ${PROJECT_NAME}_LIB)
set(TEST_LIB_NAME ${LIB_NAME}_TESTS)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin) # set ./bin as output dir for binaries 
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

  configure_file (
    "${PROJECT_SOURCE_DIR}/include/version.h.in"
    "${PROJECT_BINARY_DIR}/include/version.h"
  )

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)


endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.9.1
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


# Eigen library supports cmake (cannot get FetchContent working at this time)
# Included via gti submodule.
add_subdirectory(extern/eigen)

# The library code is here
add_subdirectory(src)

# The application code is here
add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
