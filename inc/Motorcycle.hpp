#pragma once
#include "Vehicle.hpp"

class Motorcycle : public Vehicle {
private:
    std::string model;
    int year;
    double engineCapacity;

public:
    Motorcycle(const std::string& model, int year, double engineCapacity);

    std::string getModel() const override;

    void display() const override;
};
