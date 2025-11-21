 //#include <memory>

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
     storage.addMeasurement(Measurement(tempSensor->name(),
     tempSensor->unit(),
                                        tVal, utilities::now()));

     double hVal = humidSensor->read();
     storage.addMeasurement(Measurement(humidSensor->name(),
     humidSensor->unit(),
                                        hVal, utilities::now()));
   }

   storage.printAll();
   storage.printStatisticsPerSensor();

  menu::print_menu(menu::MAIN_MENU);
  menu::select_menu_item();

  return 0;
}
