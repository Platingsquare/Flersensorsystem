#pragma once

#include "measurement_storage.h"
#include "sensor.h"

#include <memory>
#include <string>
#include <vector>

namespace menu {

const int DEFAULT_MIN_ITEM = 0;

const std::vector<std::string> MAIN_MENU = {"Exit", "Collect", "Print", "Save",
                                            "Load"};

void print_menu(const std::vector<std::string> &menu,
                int start_from = DEFAULT_MIN_ITEM);

int select_menu_item(int min = DEFAULT_MIN_ITEM,
                     int max = MAIN_MENU.size() - 1);

void show_menu();

void run_menu(MeasurementStorage &storage,
              std::vector<std::unique_ptr<Sensor>> &sensors);

} // namespace menu
