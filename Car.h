#pragma once
#include <iostream>
#include <string>

class Car {
private:
    std::string model;
    int year;
    double mileage;

public:
    // Constructorul cu initializare a membrilor
    Car(const std::string &model = "Audi A3", int year = 2020, double mileage = 0.0);

    // Constructor de copy
    Car(const Car &other);

    // Supraincarcarea operatorului "="
    Car& operator=(const Car &other);

    // Gettere si Settere (incapsulare)
    std::string getModel() const;
    int getYear() const;
    double getMileage() const;
    void setMileage(double newMileage);

    // Metoda pentru print informatiilor despre masina
    void displayInfo() const;
};
