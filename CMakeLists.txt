cmake_minimum_required(VERSION 3.20)

project(sensor-management LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sensor-management main.cpp
	src/menu.h
	src/menu.cpp
	src/measurement_storage.h
	src/measurement_storage.cpp
	src/sensor.h
	src/sensor.cpp
	src/measurement.h
	src/measurement.cpp
	src/utilities.h
	src/utilities.cpp
)
