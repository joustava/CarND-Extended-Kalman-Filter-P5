# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(
  HEADER_LIST 
  "${CMAKE_SOURCE_DIR}/include/utils/cli.hpp"
  "${CMAKE_SOURCE_DIR}/include/utils/MeasurementPackage.hpp"
  "${CMAKE_SOURCE_DIR}/include/FusionEKF.hpp"
  "${CMAKE_SOURCE_DIR}/include/Tools.hpp"
  "${CMAKE_SOURCE_DIR}/include/KalmanFilter.hpp"
)


# Make an automatic library - will be static or dynamic based on user setting
add_library("${LIB_NAME}"
  utils/cli.cpp
  FusionEKF.cpp
  Tools.cpp
  KalmanFilter.cpp
  ${HEADER_LIST}
)

# We need this directory, and users of our library will need it too.
# bin dir included to pick up generated version.h
target_include_directories("${LIB_NAME}" PUBLIC ../include "${PROJECT_BINARY_DIR}/include")

# This depends on (header only) eigen
target_link_libraries("${LIB_NAME}" Eigen3::Eigen)

# All users of this library will need at least C++11
target_compile_features("${LIB_NAME}" PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
