#ifndef MEASUREMENT_STORAGE_H
#define MEASUREMENT_STORAGE_H

#include "measurement.h"
#include <vector>

class MeasurementStorage {
public:
    void addMeasurement(const Measurement& m);
    void printAll() const;
    void printStatisticsPerSensor() const;

private:
    std::vector<Measurement> data_;
};

#endif // MEASUREMENT_STORAGE_H
