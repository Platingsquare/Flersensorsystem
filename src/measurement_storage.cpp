#include "measurement_storage.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

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
        double variance = 0.0;
        for (double v : pair.second) {
            variance += (v - mean) * (v - mean);
        }
        double stddev = sqrt(variance / pair.second.size());
        std::cout << pair.first << " stats -- Min: " << min
            << ", Max: " << max
            << ", Mean: " << std::setprecision(3) << mean
            << ", Stddev: " << std::setprecision(3) << stddev << '\n';
    }
}

void MeasurementStorage::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& m : data_) {
        file << m.name() << "," << m.unit() << "," << m.value() << "," << m.timestamp() << "\n";
    }
}

void MeasurementStorage::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, unit, valueStr, timestampStr;
        if (std::getline(ss, name, ',') &&
            std::getline(ss, unit, ',') &&
            std::getline(ss, valueStr, ',') &&
            std::getline(ss, timestampStr)) {
            try {
                double value = std::stod(valueStr);
                // timestamp was saved as integer time_t; convert back
                std::time_t t = static_cast<std::time_t>(std::stoll(timestampStr));
                data_.emplace_back(name, unit, value, t);
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse line: " << line << " (" << e.what() << ")\n";
            }
        }
    }
}
