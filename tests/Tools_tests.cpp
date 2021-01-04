#include <catch2/catch.hpp>

#include <vector>
#include <iostream>
#include <Tools.hpp>
#include <Eigen/Dense>

// using Catch::Matchers::EndsWith;

TEST_CASE("CalculateRMSE", "[Tools]") {
    Tools tools;
    
    std::vector<Eigen::VectorXd> estimations;
    std::vector<Eigen::VectorXd> ground_truth;

    Eigen::VectorXd e(4);
    e << 1, 1, 0.2, 0.1;
    estimations.push_back(e);
    e << 2, 2, 0.3, 0.2;
    estimations.push_back(e);
    e << 3, 3, 0.4, 0.3;
    estimations.push_back(e);

    Eigen::VectorXd g(4);
    g << 1.1, 1.1, 0.3, 0.2;
    ground_truth.push_back(g);
    g << 2.1, 2.1, 0.4, 0.3;
    ground_truth.push_back(g);
    g << 3.1, 3.1, 0.5, 0.4;
    ground_truth.push_back(g);
    
    Eigen::VectorXd rmse = tools.CalculateRMSE(estimations, ground_truth);
    Eigen::VectorXd expected(4);
    expected << 0.1, 0.1, 0.1, 0.1;

    REQUIRE_THAT( (rmse - expected).norm(),
        Catch::Matchers::WithinRel(0.0, 0.0001) || Catch::Matchers::WithinAbs(0.0, 0.000001)
    );
}


TEST_CASE("CalculateJacobian", "[Tools]") {
    Tools tools;    
    Eigen::VectorXd x_predicted(4);
    x_predicted << 1, 2, 0.2, 0.4;

    Eigen::MatrixXd Hj = tools.CalculateJacobian(x_predicted);
    Eigen::MatrixXd expected(3,4);
    expected << 0.447214, 0.894427, 0,        0,
                -0.4,     0.2,      0,        0,
                0,        0,        0.447214, 0.894427;
    
    REQUIRE_THAT( (Hj - expected).norm(),
        Catch::Matchers::WithinRel(0.0, 0.0001) || Catch::Matchers::WithinAbs(0.0, 0.000001) 
    );//0.0000006333
}
