#pragma once
#include "Vehicle.hpp"
#include <iostream>
#include <string>

class Car : public Vehicle {
private:
    char* fuelType; // Alocare dinamica pentru tipul de combustibil
    int year;
    double mileage;

public:
    // Constructor
    Car(const std::string& model = "Brand-Model", int year = 2024, double mileage = 0.0, const std::string& fuel = "Gasoline");

    // Copy Constructor
    Car(const Car& other);

    // Move Constructor
    Car(Car&& other) noexcept;

    // Operator de asignare
    Car& operator=(const Car& other);

    // Move Assignment Operator
    Car& operator=(Car&& other) noexcept;

    // Destructor
    ~Car();

    // Metoda de afisare
    void displayInfo() const override;
};
