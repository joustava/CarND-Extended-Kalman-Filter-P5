#include "evaluation.hpp"
#include <iostream>

Eigen::VectorXd rmse(
  const std::vector<Eigen::VectorXd> &estimations, 
  const std::vector<Eigen::VectorXd> &ground_truth) {

  Eigen::VectorXd rmse(4);
  rmse << 0,0,0,0;

  if (estimations.empty()) {
      std::cout << "the estimation vector size should not be zero" << std::endl;
      return rmse;
  }
  if (estimations.size() != ground_truth.size()) {
      std::cout << "the estimation vector size should equal ground truth vector size" << std::endl;
      return rmse;
  }

  for (int i=0; i < estimations.size(); ++i) {      
    Eigen::VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }

  rmse = rmse/estimations.size();
  rmse = sqrt(rmse.array());
  return rmse;
}