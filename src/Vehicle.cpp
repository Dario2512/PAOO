#include "Vehicle.hpp"
#include <cstring> 

Vehicle::Vehicle(const std::string& model) {
    this->model = new char[model.length() + 1];
    std::strcpy(this->model, model.c_str());
    std::cout << "Constructorul Vehicle a fost apelat pentru " << this->model << "\n";
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle& other) {
    model = new char[std::strlen(other.model) + 1];
    std::strcpy(model, other.model);
    std::cout << "Copy Constructor Vehicle apelat\n";
}

// Move Constructor
Vehicle::Vehicle(Vehicle&& other) noexcept {
    model = other.model;
    other.model = nullptr;
    std::cout << "Move Constructor Vehicle apelat\n";
}

// Operator de asignare
Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        delete[] model;
        model = new char[std::strlen(other.model) + 1];
        std::strcpy(model, other.model);
    }
    std::cout << "Assign Operator Vehicle apelat\n";
    return *this;
}

// Move Assignment Operator
Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
    if (this != &other) {
        delete[] model;
        model = other.model;
        other.model = nullptr;
    }
    std::cout << "Move Assign Operator Vehicle apelat\n";
    return *this;
}

// Destructor
Vehicle::~Vehicle() {
    std::cout << "Destructorul Vehicle a fost apelat pentru " << (model ? model : "nullptr") << "\n";
    delete[] model;
}

// Afisare 
void Vehicle::displayInfo() const {
    std::cout << "Vehicle: " << model << "\n";
}
