#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
#include <ctime>

class Measurement {
public:
    Measurement(const std::string& name, const std::string& unit,
        double value, std::time_t timestamp);

    std::string name() const;
    std::string unit() const;
    double value() const;
    std::time_t timestamp() const;
    void print() const;

private:
    std::string name_, unit_;
    double value_;
    std::time_t timestamp_;
};

std::time_t currentTimestamp();

#endif // MEASUREMENT_H


