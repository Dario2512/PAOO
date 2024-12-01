#pragma once
#include "Vehicle.hpp"

class Car : public Vehicle {
private:
    std::string model;
    int year;
    double mileage;

public:
    Car(const std::string& model, int year, double mileage);

    std::string getModel() const override;

    void display() const override;
};
