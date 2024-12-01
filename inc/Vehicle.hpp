#pragma once
#include <string>
#include <iostream>

class Vehicle {
public:
    virtual ~Vehicle() = default;

    // Metode pur virtuala
    virtual void display() const = 0;

    virtual std::string getModel() const = 0;
};
