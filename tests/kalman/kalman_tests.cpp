#include <catch2/catch.hpp>
#include <vector>
#include <iostream>
#include <kalman/filter.hpp>

using std::cout;
using std::endl;
using std::vector;
using Eigen::VectorXd;
using Eigen::MatrixXd; 

TEST_CASE("Kalman Filter init for a simple 1D motion", "[kalman/filter]") {
    VectorXd x = VectorXd(2);
    x << 0, 0;

    MatrixXd P = MatrixXd(2, 2);
    P << 1000, 0, 0, 1000;

    Kalman k = Kalman();
    k.init(x, P);

    VectorXd xn = VectorXd(2);
    xn << 3.99967, 1;

    REQUIRE( k.get_x() == x );
    REQUIRE( k.get_P() == P );
}

TEST_CASE("Kalman Filter 1D cycle", "[kalman/filter]") {
    vector<VectorXd> measurements;
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
    P << 1000, 0, 0, 1000;

    Kalman k = Kalman();
    k.init(x, P);
    
    // filter cycle.
    for (auto measurement: measurements) {
        k.update(measurement);
        k.predict();
    }

    VectorXd x_expected = VectorXd(2);
    x_expected << 3.99967, 1;

    MatrixXd P_expected = MatrixXd(2, 2);
    P_expected << 2.33189, 0.999168, 0.999168, 0.499501;

    // CHECK( k.get_x() == x_expected );
    // CHECK( k.get_P() == P_expected );
    REQUIRE( (k.get_x() - x_expected).norm() < 0.00001 );
    REQUIRE( (k.get_P() - P_expected).norm() < 0.00001 );
    
}