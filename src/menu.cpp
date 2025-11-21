#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <string>

#include "measurement_storage.h"
#include "sensor.h"
#include "menu.h"


// Lägg till filnamn för sparning/läsning
const std::string filename = "data.csv";

void showMenu() {
    std::cout << "\n--- MENY ---\n";
    std::cout << "1. Läs nya mätvärden från alla sensorer\n";
    std::cout << "2. Visa statistik per sensor\n";
    std::cout << "3. Visa alla mätvärden\n";
    std::cout << "4. Spara alla mätvärden till fil\n";
    std::cout << "5. Läs in mätvärden från fil\n";
    std::cout << "6. Avsluta\n";
    std::cout << "Val: ";
}

void run_menu(MeasurementStorage& storage, std::vector<Sensor*>& sensors) {
    int choice = 0;
    do {
        showMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            for (auto* sensor : sensors) {
                double value = sensor->read();
                std::time_t now = std::time(nullptr);
                Measurement m(sensor->name(), sensor->unit(), value, now);
                storage.addMeasurement(m);
                std::cout << "Läste värde från " << sensor->name() << ": " << value << " " << sensor->unit() << "\n";
            }
            break;
        case 2:
            storage.printStatisticsPerSensor();       // Nu med stddev!
            break;
        case 3:
            storage.printAll();
            break;
        case 4:
            storage.saveToFile(filename);
            std::cout << "Mätvärden sparade till fil.\n";
            break;
        case 5:
            storage.loadFromFile(filename);
            std::cout << "Mätvärden inlästa från fil.\n";
            break;
        case 6:
            std::cout << "Avslutar...\n";
            break;
        default:
            std::cout << "Ogiltigt val.\n";
            break;
        }
    } while (choice != 6);
}

/*/
void menu::print_menu(const std::vector<std::string> &menu, int start_from) {
  int index = start_from;
  for (const auto &item : menu) {
    std::cout << " " << index++ << ". " << item << std::endl;
  }
}


int menu::select_menu_item(int min, int max) {
  std::cout << "Select Item: ";
  int answer = 0;

  do {
    if (!(std::cin >> answer)) {
      // Handle non-integer input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Try again: ";
      continue;
    }

    std::cout << "You answered: " << answer << std::endl;

    if (answer < min || answer > max) {
      std::cerr << "Invalid choice.\nTry again: ";
    }

  } while (answer < min || answer > max);

  return answer;
}*/


