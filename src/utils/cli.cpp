#include <utils/cli.hpp>
#include "version.h"

#include <iostream>
using Eigen::MatrixXd;

bool usage(int argc, char* argv[]) {
  if (argc < 2) {
    
    std::cout \
      << argv[0] \
      << " Version " \
      << KalmanExtended_VERSION_MAJOR \
      << "." \
      << KalmanExtended_VERSION_MINOR \
      << "." \
      << KalmanExtended_VERSION_PATCH \
      << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return false;
  }
  return true;
}

void example(int number) {
  MatrixXd m(2,2);
  m(0,0) = number;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}