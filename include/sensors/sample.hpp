#include <Eigen/Dense>

class Sample {
  public:

  enum SensorType {
    LASER, RADAR
  } sensor_type_;

  Eigen::VectorXd raw_measurements_;
  
  int64_t timestamp_;
};