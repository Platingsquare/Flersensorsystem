#include "utilities.h"
#include <ctime>
#include <chrono>
/*std::time_t currentTimestamp() {
    return std::time(nullptr);
}*/

std::time_t utils::now() {
  auto now = std::chrono::system_clock::now();
  auto result = std::chrono::system_clock::to_time_t(now);
  return result;
}