# Works with 3.11 and tested through 3.19
cmake_minimum_required(VERSION 3.19)

# Project name and a few useful settings. Other commands can pick up the results
project(
  KalmanExtended
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

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# # FetchContent_MakeAvailable was not added until CMake 3.14; use our shim
# if(${CMAKE_VERSION} VERSION_LESS 3.14)
#   include(cmake/add_FetchContent_MakeAvailable.cmake)
# endif()


# Eigen library
# FetchContent_Declare(
#   Eigen3
#   GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
#   GIT_TAG 3.3)
# FetchContent_MakeAvailable(Eigen3)
# This is header only, so could be replaced with git submodules or FetchContent
# but is included via a submodule at time of writing.
# find_package(Eigen3 3.3 REQUIRED)
# Adds Eigen3::Eigen
# find_package(uWS 18.17.0 REQUIRED)
# Adds uWS

# Formatting library
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)
# Adds fmt::fmt

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
