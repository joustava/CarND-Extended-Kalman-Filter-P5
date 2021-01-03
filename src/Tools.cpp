#include "Tools.hpp"
#include <iostream>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
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

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  MatrixXd Hj(3,4);
  
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);

  // check division by zero
  if(px == 0 && py == 0) {
      std::cout << "Error" << std::endl;
      return Hj;
  }
  // compute the Jacobian matrix
  float total = pow(px, 2) + pow(py, 2);
  float sqr   = sqrt(total);
  
  Hj << px/sqr,     py/sqr  , 0, 0,
        -py/total, px/total, 0, 0,
        py * (vx * py - vy * px)/pow(total, 3.0/2.0), px * (vy * px - vx * py)/pow(total, 3.0/2.0), px/sqr, py/sqr;
  
  return Hj;
}
