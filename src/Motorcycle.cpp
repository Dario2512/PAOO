#include "Motorcycle.hpp"
#include <cstring>

Motorcycle::Motorcycle(const std::string& model, int cc, const std::string& engine)
    : Vehicle(model), cc(cc) {
    engineType = new char[engine.length() + 1];
    std::strcpy(engineType, engine.c_str());
    std::cout << "Constructorul Motorcycle a fost apelat pentru " << model << "\n";
}

// Copy Constructor
Motorcycle::Motorcycle(const Motorcycle& other) : Vehicle(other), cc(other.cc) {
    engineType = new char[std::strlen(other.engineType) + 1];
    std::strcpy(engineType, other.engineType);
    std::cout << "Copy Constructorul Motorcycle apelat\n";
}

// Move Constructor
Motorcycle::Motorcycle(Motorcycle&& other) noexcept : Vehicle(std::move(other)), cc(other.cc) {
    engineType = other.engineType;
    other.engineType = nullptr; 
    std::cout << "Move Constructorul Motorcycle apelat\n";
}

// Operator de asignare
Motorcycle& Motorcycle::operator=(const Motorcycle& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        delete[] engineType;

        engineType = new char[std::strlen(other.engineType) + 1];
        std::strcpy(engineType, other.engineType);
        cc = other.cc;
    }
    std::cout << "Assign Operator Motorcycle apelat\n";
    return *this;
}

// Move Assignment Operator
Motorcycle& Motorcycle::operator=(Motorcycle&& other) noexcept {
    if (this != &other) {
        Vehicle::operator=(std::move(other));

        delete[] engineType;
        engineType = other.engineType;
        cc = other.cc;
        other.engineType = nullptr;
    }
    std::cout << "Move Assign Operator Motorcycle apelat\n";
    return *this;
}


// Destructor
Motorcycle::~Motorcycle() {
    std::cout << "Destructorul Motorcycle a fost apelat pentru " << (model ? model : "nullptr") << "\n";
    if (engineType) delete[] engineType;
}

// Metoda de afisare
void Motorcycle::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Engine: " << (engineType ? engineType : "nullptr") << ", CC: " << cc << "\n";
}

