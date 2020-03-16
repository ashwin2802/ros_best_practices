#include "ros_package_template/Algorithm.hpp"

namespace ros_package_template {

Algorithm::Algorithm()
    : average_(0.0)
    , n_measurements_(0) {
}

Algorithm::~Algorithm() {
}

void Algorithm::addData(const double data) {
  average_ = (n_measurements_ * average_ + data) / (n_measurements_ + 1);
  n_measurements_++;
}

double Algorithm::getAverage() const {
  return average_;
}

} /* namespace */
