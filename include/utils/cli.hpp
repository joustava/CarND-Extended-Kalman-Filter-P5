#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

#include "Eigen/Dense"

/// \brief Accumulate a vector to produce the mean and the first moment of the distribution.
///
/// This computes the mean and the first moment of a vector of double values.
///
bool usage(int argc, char* argv[]);
void example(int number);