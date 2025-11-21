#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#include "measurement.h"
#include "statistics.h"

Statistics::Statistics(std::vector<Measurement> &measurements) {
  this->count = measurements.size();

  // We need the sum to get the average
  double sum = std::accumulate(
      measurements.begin(), measurements.end(), double{0},
      [](double total, const Measurement &m) { return total += m.value(); });
  this->avg = sum / measurements.size();

  // We have to use a custom lambda to extract min and max measurements
  this->min = std::min_element(measurements.begin(), measurements.end(),
                               [](const Measurement &a, const Measurement &b) {
                                 return a.value() < b.value();
                               })
                  ->value();
  this->max = std::max_element(measurements.begin(), measurements.end(),
                               [](const Measurement &a, const Measurement &b) {
                                 return a.value() > b.value();
                               })
                  ->value();

  double variance = 0.0;
  for (auto &v : measurements) {
    variance += (v.value() - avg) * (v.value() - avg);
  }

  this->std_div = std::sqrt(variance);

  this->unit = measurements.at(0).unit();
}

void Statistics::print() {
  std::cout << "Count:\t\t" << this->count << "\n"
            << "Min:\t\t" << this->min << "\t" << this->unit << "\n"
            << "Max:\t\t" << this->max << "\t" << this->unit << "\n"
            << "Avg:\t\t" << this->avg << "\t" << this->unit << "\n"
            << "Std. Div.:\t" << this->std_div << std::endl;
}
