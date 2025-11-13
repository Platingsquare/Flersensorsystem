#ifndef UTILITIES_H
#define UTILITIES_H

#include <ctime>

/*std::time_t currentTimestamp();*/
std::string utils::timestamp_to_string(std::time_t& timestamp) {
	std::tm tm = *std::gmtime(&timestamp); // UTC for "Z"

	std::stringstream ss;
	ss << std::put_time(&tm, "%F %T");
	return ss.str();
}
#endif // UTILITIES_H
