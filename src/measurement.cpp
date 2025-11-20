#include "measurement.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Measurement::Measurement(const std::string& name, const std::string& unit,
    double value, std::time_t timestamp)
    : name_(name), unit_(unit), value_(value), timestamp_(timestamp) {
}

std::string Measurement::name() const {
    return name_;
}

std::string Measurement::unit() const {
    return unit_;
}

double Measurement::value() const {
    return value_;
}

std::time_t Measurement::timestamp() const {
    return timestamp_;
}

void Measurement::print() const {
    std::tm timeinfo{};
#if defined(_WIN32) || defined(_MSC_VER)
    // Use secure Windows variant
    localtime_s(&timeinfo, &timestamp_);
#else
    // Use POSIX variant
    localtime_r(&timestamp_, &timeinfo);
#endif
    std::cout << name_ << " (" << unit_ << "): " << value_
        << " at " << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S") << '\n';
}

// currentTimestamp() is implemented in utilities.cpp
