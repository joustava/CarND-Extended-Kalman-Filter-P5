#include <fstream>
//#include <istream>
// #include <iostream>
// #include <sstream>


class Sampler {
  private:
  bool is_ready;
  std::ifstream in_file;

  public:
  Sampler(std::string in_file_name = "./tests/utils/fixture.txt");
  bool is_available();
  bool read(std::string &package);
};



// collecting measurments and truth fo one sample.
// MeasurementPackage meas_package;
// meas_package.sensor_type_ = MeasurementPackage::LASER;
// meas_package.raw_measurements_ = VectorXd(2);
// meas_package.raw_measurements_ << px, py;
// meas_package.timestamp_ = timestamp;

// vector<VectorXd> ground_truth;
// VectorXd gt_values(4);
// gt_values(0) = x_gt;
// gt_values(1) = y_gt; 
// gt_values(2) = vx_gt;
// gt_values(3) = vy_gt;
// ground_truth.push_back(gt_values);