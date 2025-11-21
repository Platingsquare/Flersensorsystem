#pragma once

#include "measurement.h"
#include "sensor.h"
#include <string>

struct Statistics {
  int count;
  double avg;
  double min;
  double max;
  double std_div;
  std::string unit;

  Statistics(std::vector<Measurement> &);
  void print();
};
