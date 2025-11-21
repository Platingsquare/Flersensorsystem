#include <memory>

#include "src/measurement.h"
#include "src/measurement_storage.h"
#include "src/menu.h"
#include "src/sensor.h"
#include "src/utilities.h"

int main() {
  auto tempSensor =
      std::make_unique<TemperatureSensor>("TempSensor 1", 15.0, 30.0);
  auto humidSensor =
      std::make_unique<HumiditySensor>("HumiditySensor 1", 20.0, 80.0);

  MeasurementStorage storage;

  const int iterations = 10;
  for (int i = 0; i < iterations; ++i) {
    double tVal = tempSensor->read();
    storage.addMeasurement(Measurement(tempSensor->name(), tempSensor->unit(),
                                       tVal, utilities::now()));

    double hVal = humidSensor->read();
    storage.addMeasurement(Measurement(humidSensor->name(), humidSensor->unit(),
                                       hVal, utilities::now()));
  }

  std::vector<std::unique_ptr<Sensor>> sensors;
  sensors.push_back(std::move(tempSensor));
  sensors.push_back(std::move(humidSensor));

  menu::run_menu(storage, sensors);

  return 0;
}
