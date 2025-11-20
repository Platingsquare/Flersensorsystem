#include "measurement_storage.h"
#include <iostream>
#include <map>

void MeasurementStorage::addMeasurement(const Measurement& m) {
    data_.push_back(m);
}

void MeasurementStorage::printAll() const {
    for (const auto& m : data_) {
        m.print();
    }
}

void MeasurementStorage::printStatisticsPerSensor() const {
    std::map<std::string, std::vector<double>> values;
    for (const auto& m : data_) {
        values[m.name()].push_back(m.value());
    }
    for (const auto& pair : values) {
        double sum = 0.0, min = pair.second[0], max = pair.second[0];
        for (double v : pair.second) {
            sum += v;
            if (v < min) min = v;
            if (v > max) max = v;
        }
        double mean = sum / pair.second.size();
        std::cout << pair.first << " stats -- Min: " << min << ", Max: " << max
            << ", Mean: " << mean << '\n';
    }
}