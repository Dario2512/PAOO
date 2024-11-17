#pragma once
#include "Vehicle.hpp"
#include <iostream>
#include <string>

class Motorcycle : public Vehicle {
private:
    char* engineType; // Alocare dinamica pentru tipul de motor
    int cc;

public:
    // Constructor
    Motorcycle(const std::string& model = "Motorcycle-Model", int cc = 600, const std::string& engine = "Inline");

    // Copy Constructor
    Motorcycle(const Motorcycle& other);

    // Move Constructor
    Motorcycle(Motorcycle&& other) noexcept;

    // Operator de asignare
    Motorcycle& operator=(const Motorcycle& other);

    // Move Assignment Operator
    Motorcycle& operator=(Motorcycle&& other) noexcept;

    // Destructor
    ~Motorcycle();

    // Metoda de afiare
    void displayInfo() const override;
};
