#include <vector>
#include <Eigen/Dense>

Eigen::VectorXd rmse(const std::vector<Eigen::VectorXd> &estimations,
    const std::vector<Eigen::VectorXd> &ground_truth);