#include "sensor.h"
#include <random>

Sensor::Sensor(SensorConfig &config)
    : name_(config.name), unit_(config.unit), min_(config.min),
      max_(config.max), t_low_(config.t_low), t_high_(config.t_high),
      rng_(std::random_device{}()), dist_(min_, max_) {}

Sensor::Sensor(const std::string &name, const std::string &unit, double min,
               double max)
    : name_(name), unit_(unit), min_(min), max_(max),
      rng_(std::random_device{}()), dist_(min_, max_) {}

double Sensor::read() { return dist_(rng_); }

std::string Sensor::name() const { return name_; }

std::string Sensor::unit() const { return unit_; }

TemperatureSensor::TemperatureSensor(const std::string &name, double min,
                                     double max)
    : Sensor(name, "C", min, max) {}

HumiditySensor::HumiditySensor(const std::string &name, double min, double max)
    : Sensor(name, "%", min, max) {}
