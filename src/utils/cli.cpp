#include <iostream>
#include <utils/cli.hpp>
#include "version.h"

using Eigen::MatrixXd;

bool usage(int argc, char* argv[]) {
  if (argc < 2) {
    
    std::cout \
      << argv[0] \
      << " Version " \
      << ExtendedKF_VERSION_MAJOR \
      << "." \
      << ExtendedKF_VERSION_MINOR \
      << "." \
      << ExtendedKF_VERSION_PATCH \
      << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return false;
  }
  return true;
}