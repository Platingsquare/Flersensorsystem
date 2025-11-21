#ifndef MEASUREMENT_STORAGE_H
#define MEASUREMENT_STORAGE_H

#include <fstream>
#include <sstream>
#include "measurement.h"
#include <vector>

class MeasurementStorage {
public:
    void addMeasurement(const Measurement& m);
    void printAll() const;
    void printStatisticsPerSensor() const;
    void saveToFile(const std::string& filename) const;    // Flytta in i klassen!
    void loadFromFile(const std::string& filename);        // Flytta in i klassen!

private:
    std::vector<Measurement> data_;
};

#endif // MEASUREMENT_STORAGE_H


