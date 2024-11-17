#pragma once
#include <iostream>
#include <cstring> 

class Vehicle {
protected:
    char* model;

public:
    Vehicle(const std::string& model = "Generic-Vehicle");
    
    // Copy Constructor
    Vehicle(const Vehicle& other);

    // Move Constructor
    Vehicle(Vehicle&& other) noexcept;

    // Operator de asignare
    Vehicle& operator=(const Vehicle& other);

    // Move Assignment Operator
    Vehicle& operator=(Vehicle&& other) noexcept;

    // Destructor virtual
    virtual ~Vehicle();

    // Functie virtuala pentru afisre
    virtual void displayInfo() const;
};
