#pragma once

#include <random>
#include <string>

struct SensorConfig {
  std::string name;
  std::string unit;
  double min, max;
  double t_low, t_high;
};

class Sensor {
public:
  Sensor() = delete;
  Sensor(SensorConfig &config);
  Sensor(const std::string &name, const std::string &unit, double min,
         double max);
  virtual ~Sensor() = default;
  virtual double read();
  std::string name() const;
  std::string unit() const;

protected:
  std::string name_, unit_;
  double min_, max_;
  double t_low_, t_high_;
  std::mt19937 rng_;
  std::uniform_real_distribution<double> dist_;
};

class TemperatureSensor : public Sensor {
public:
  TemperatureSensor(const std::string &name, double min, double max);
};

class HumiditySensor : public Sensor {
public:
  HumiditySensor(const std::string &name, double min, double max);
};
