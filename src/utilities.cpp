#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "utilities.h"

std::time_t utilities::now() {
  auto now = std::chrono::system_clock::now();
  auto result = std::chrono::system_clock::to_time_t(now);
  return result;
}

std::string utilities::timestamp_to_string(std::time_t &timestamp) {
  std::tm tm = *std::gmtime(&timestamp); // UTC for "Z"

  std::stringstream ss;
  ss << std::put_time(&tm, "%F %T");
  return ss.str();
}
