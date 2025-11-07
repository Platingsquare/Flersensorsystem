#include "utilities.h"
#include <ctime>

std::time_t currentTimestamp() {
    return std::time(nullptr);
}
