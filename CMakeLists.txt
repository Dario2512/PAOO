cmake_minimum_required(VERSION 3.10)
project(VehicleApp)

# Setare standarc C++
set(CMAKE_CXX_STANDARD 17)

#adaug folderului inc pentru cautarea de headere
include_directories(inc)

# adaugarea source files
add_executable(VehicleApp
    src/Car.cpp
    src/CarFleet.cpp
    src/Motorcycle.cpp
    src/Vehicle.cpp
    src/main.cpp    
)

set(CMAKE_VERBOSE_MAKEFILE ON)
