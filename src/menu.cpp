#include <iostream>
#include <vector>

#include "menu.h"

void menu::print_menu(const std::vector<std::string> &menu, int start_from) {
  int index = start_from;
  for (auto &item : menu) {
    std::cout << " " << index++ << ". " << item << std::endl;
  }
}

int menu::select_menu_item(int min, int max) {
  std::cout << "Select Item: ";
  int answer = 0;

  do {

    std::cin >> answer;

    std::cout << "You answered: " << answer << std::endl;

    if (answer < min || answer > max) {
      std::cerr << "Invalid choice.\nTry again: ";
    }

  } while (answer < min || answer > max);

  return answer;
}
