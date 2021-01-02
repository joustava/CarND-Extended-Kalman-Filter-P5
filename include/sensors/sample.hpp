#include <Eigen/Dense>


/// \brief Object that keeps one sensor measurement
///
/// The raw_measuremens vector contains data respective to the sensor type 
///
/// RADAR: (rho, phi, rhodot)
/// sensor_type, rho_measured, phi_measured, rhodot_measured, timestamp, x_groundtruth, y_groundtruth, vx_groundtruth, vy_groundtruth, yaw_groundtruth, yawrate_groundtruth
/// LIDAR: (x, y)
/// sensor_type, x_measured, y_measured, timestamp, x_groundtruth, y_groundtruth, vx_groundtruth, vy_groundtruth, yaw_groundtruth, yawrate_groundtruth
class Sample {
  public:
  enum SensorType {
    LASER, RADAR
  } sensor_type_;

  Eigen::VectorXd raw_measurements_;
  
  int64_t timestamp_;

};