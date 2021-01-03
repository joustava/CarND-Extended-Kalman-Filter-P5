#include "KalmanFilter.hpp"

using Eigen::MatrixXd;
using Eigen::VectorXd;

/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  Q_ = Q_in;
}

void KalmanFilter::Predict() {
  // 1. Predicted (a priori) state estimate 
  x_ = (F_ * x_);
  // 2. Predicted (a priori) estimate covariance 
  P_ = F_ * P_ * F_.transpose();
}

void KalmanFilter::Update(const VectorXd &z) {
  // 1. Innovation or measurement pre-fit residual.
  MatrixXd y = z - H_ * x_;
  // 2. Innovation (or pre-fit residual) covariance 
  
  MatrixXd Ht = H_.transpose();
  MatrixXd S = H_ * P_ * Ht + R_;
  // 3. Optimal Kalman gain
  MatrixXd K = P_ * Ht * S.inverse();
  // 4. Updated (a posteriori) state estimate 
  x_ = x_ + (K * y);
  // 5. Updated (a posteriori) estimate covariance
  long x_size = x_.size();
  MatrixXd I = MatrixXd::Identity(x_size, x_size);
  P_ = (I - (K * H_)) * P_;
}

void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
   * TODO: update the state by using Extended Kalman Filter equations
   */
}
