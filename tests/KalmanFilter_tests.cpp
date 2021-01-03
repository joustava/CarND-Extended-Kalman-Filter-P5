#include <catch2/catch.hpp>

#include <vector>
#include <iostream>
#include <KalmanFilter.hpp>

using Eigen::VectorXd;
using Eigen::MatrixXd; 

TEST_CASE("KalmanFilter 1D cycle", "[KalmanFilter]") {
    std::vector<VectorXd> measurements;
    // create a list of measurements
    VectorXd single_meas(1);
    single_meas << 1;
    measurements.push_back(single_meas);
    single_meas << 2;
    measurements.push_back(single_meas);
    single_meas << 3;
    measurements.push_back(single_meas);

    VectorXd x = VectorXd(2);
    x << 0, 0;

    MatrixXd P = MatrixXd(2, 2);
    P << 1000, 0, 
         0, 1000;

    MatrixXd F = MatrixXd(2, 2);
    F << 1, 1,
         0, 1;

    MatrixXd H = MatrixXd(1, 2);
    H << 1, 0;

    MatrixXd R = MatrixXd(1, 1);
    R << 1;

    MatrixXd Q = MatrixXd(2, 2);
    Q << 0, 0, 
         0, 0;

    KalmanFilter kf = KalmanFilter();
    kf.Init(x, P, F, H, R, Q);
    
    // filter cycle.
    for (auto &measurement: measurements) {
        kf.Update(measurement);
        kf.Predict();
    }

    VectorXd x_expected = VectorXd(2);
    x_expected << 3.99967, 1.0;

    MatrixXd P_expected = MatrixXd(2, 2);
    P_expected << 2.33189, 0.999168, 0.999168, 0.499501;
    REQUIRE_THAT( (kf.x_ - x_expected).norm(),
        Catch::Matchers::WithinRel(0.0, 0.001) || Catch::Matchers::WithinAbs(0.0, 0.00001) 
    );
    
    REQUIRE_THAT( (kf.P_ - P_expected).norm(),
        Catch::Matchers::WithinRel(0.0, 0.001) || Catch::Matchers::WithinAbs(0.0, 0.00001) 
    );
}