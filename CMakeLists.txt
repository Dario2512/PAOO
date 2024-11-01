cmake_minimum_required(VERSION 3.10)
project(AudiA3App)

# Setare standarc C++
set(CMAKE_CXX_STANDARD 11)

# Adaugarea source files
add_executable(AudiA3App main.cpp Car.cpp)
