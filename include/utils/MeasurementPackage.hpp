#ifndef _MEASUREMENT_PACKAGE_H_
#define _MEASUREMENT_PACKAGE_H_

#include "Eigen/Dense"

class MeasurementPackage {
 public:
  enum SensorType{
    LASER,
    RADAR
  } sensor_type_;

  long long timestamp_;

  Eigen::VectorXd raw_measurements_;
};

#endif // _MEASUREMENT_PACKAGE_H_