#include <catch2/catch.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <FusionEKF.hpp>
#include <Tools.hpp>
#include <utils/MeasurementPackage.hpp>

using Eigen::VectorXd;
using Eigen::MatrixXd; 

TEST_CASE("FusionEKF Accuracy Criteria", "[FusionEKF integration]") {
//    [.11, .11, 0.52, 0.52].
    std::fstream data;
    Tools tools;
    FusionEKF fusionEKF;
    std::vector<VectorXd> estimations;
    std::vector<VectorXd> ground_truth;
    data.open("tests/obj_pose-laser-radar-synthetic-input.txt", std::ios::in);
    
    REQUIRE(data.is_open());

    std::string entry;
    while(getline(data, entry)) { 
        std::istringstream iss(entry);
        MeasurementPackage package = MeasurementParser::parse(iss);

        fusionEKF.ProcessMeasurement(package);
        VectorXd estimate(4);

        double p_x = fusionEKF.ekf_.x_(0);
        double p_y = fusionEKF.ekf_.x_(1);
        double v1  = fusionEKF.ekf_.x_(2);
        double v2 = fusionEKF.ekf_.x_(3);

        estimate(0) = p_x;
        estimate(1) = p_y;
        estimate(2) = v1;
        estimate(3) = v2;
    
        estimations.push_back(estimate);
        ground_truth.push_back(package.ground_truth_);
    }
    data.close(); //close the file object.


    VectorXd RMSE = tools.CalculateRMSE(estimations, ground_truth);
    INFO(RMSE);
    
    REQUIRE(RMSE(0) < 0.11);
    REQUIRE(RMSE(1) < 0.11);
    REQUIRE(RMSE(2) < 0.52);
    REQUIRE(RMSE(3) < 0.52);


}
