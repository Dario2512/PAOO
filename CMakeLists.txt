cmake_minimum_required(VERSION 3.10)
project(AudiA3App)

# Setare standarc C++
set(CMAKE_CXX_STANDARD 11)

#adaug folderului inc pentru cautarea de headere
include_directories(inc)

# adaugarea source files
add_executable(AudiA3App
    src/main.cpp
    src/Car.cpp
)
