#pragma once

#include <string>
#include <vector>

namespace menu {

const int DEFAULT_MIN_ITEM = 0;

const std::vector<std::string> MAIN_MENU = {"Exit", "Collect", "Print", "Save",
                                            "Load"};

void print_menu(const std::vector<std::string> &menu,
                int start_from = DEFAULT_MIN_ITEM);

void print_sensor_list();

int select_menu_item(int min = DEFAULT_MIN_ITEM,
                     int max = MAIN_MENU.size() - 1);

} // namespace menu
