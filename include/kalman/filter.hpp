#pragma once
#include <vector>
#include "Eigen/Dense"

using std::vector;
using Eigen::VectorXd;
using Eigen::MatrixXd; 

/**
 * @brief Kalman Filter implementation 
 * 
 */
class Kalman {
  private:
  VectorXd x;	// object state
  MatrixXd P;	// object covariance matrix
  VectorXd u;	// external motion
  MatrixXd F; // the state-transition model
  MatrixXd H;	// the observation/measurement model
  MatrixXd Ht;// the observation/measurement model transpose
  MatrixXd R;	// the covariance of the observation/measurment noise
  MatrixXd I; // Identity matrix
  MatrixXd Q;	// the covariance of the process noise

  MatrixXd S;
  MatrixXd y;
  MatrixXd K;

  public:
  void init(VectorXd &x, MatrixXd &P);
  void filter(vector<VectorXd> &measurements);
  VectorXd get_x();
  MatrixXd get_P();

};