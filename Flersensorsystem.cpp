#include <memory>
#include "sensor.h"
#include "measurement.h"
#include "measurement_storage.h"
#include "utilities.h"

int main() {
    auto tempSensor = std::make_unique<TemperatureSensor>("TempSensor 1", 15.0, 30.0);
    auto humidSensor = std::make_unique<HumiditySensor>("HumiditySensor 1", 20.0, 80.0);

    MeasurementStorage storage;

    const int iterations = 10;
    for (int i = 0; i < iterations; ++i) {
        double tVal = tempSensor->read();
        storage.addMeasurement(Measurement(tempSensor->name(), tempSensor->unit(), tVal, currentTimestamp()));

        double hVal = humidSensor->read();
        storage.addMeasurement(Measurement(humidSensor->name(), humidSensor->unit(), hVal, currentTimestamp()));
    }

    storage.printAll();
    storage.printStatisticsPerSensor();

    return 0;
}
