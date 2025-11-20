#pragma once

#include <ctime>
#include <string>

namespace utilities {

time_t now();
std::string timestamp_to_string(std::time_t &timestamp);

} // namespace utilities
