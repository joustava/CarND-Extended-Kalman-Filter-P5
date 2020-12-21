#include <kalman/filter.hpp>


void Kalman::init(VectorXd &xi, MatrixXd &Pi) {
  x = xi;
  P = Pi;
  
  u = VectorXd(2);
  u << 0, 0;

  F = MatrixXd(2, 2);
  F << 1, 1, 0, 1;

  H = MatrixXd(1, 2);
  H << 1, 0;

  Ht = H.transpose();

  R = MatrixXd(1, 1);
  R << 1;

  I = MatrixXd::Identity(2, 2);

  Q = MatrixXd(2, 2);
  Q << 0, 0, 0, 0;
}

VectorXd Kalman::get_x() {
  return x;
}

MatrixXd Kalman::get_P() {
  return P;
}

void Kalman::filter(vector<VectorXd> &measurements) {
  for (unsigned int n = 0; n < measurements.size(); ++n) {

    VectorXd z = measurements[n];
    
    // UPDATE
    // 1. Innovation or measurement pre-fit residual.
    y = z - H * x;
    // 2. Innovation (or pre-fit residual) covariance 
    S = H * P * Ht + R;
    // 3. Optimal Kalman gain
    K = P * Ht * S.inverse();
    // 4. Updated (a posteriori) state estimate 
    x = x + (K * y);
    // 5. Updated (a posteriori) estimate covariance 
    P = (I - (K * H)) * P;
    
    // PREDICT
    // 1. Predicted (a priori) state estimate 
    x = (F * x) + u;
    // 2. Predicted (a priori) estimate covariance 
    P = F * P * F.transpose();
  }
}