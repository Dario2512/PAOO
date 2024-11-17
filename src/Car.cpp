#include "Car.hpp"
#include <cstring>

Car::Car(const std::string& model, int year, double mileage, const std::string& fuel)
    : Vehicle(model), year(year), mileage(mileage) {
    fuelType = new char[fuel.length() + 1];
    std::strcpy(fuelType, fuel.c_str());
    std::cout << "Constructorul Car a fost apelat pentru " << model << "\n";
}

// Copy Constructor
Car::Car(const Car& other) : Vehicle(other), year(other.year), mileage(other.mileage) {
    fuelType = new char[std::strlen(other.fuelType) + 1];
    std::strcpy(fuelType, other.fuelType);
    std::cout << "Copy Constructorul Car a fost apelat\n";
}

// Move Constructor
Car::Car(Car&& other) noexcept : Vehicle(std::move(other)), year(other.year), mileage(other.mileage) {
    fuelType = other.fuelType;
    other.fuelType = nullptr;
    std::cout << "Move Constructorul Car a fost apelat\n";
}

// Operator de asignare
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other); // Copierea parti de baza
        delete[] fuelType;

        fuelType = new char[std::strlen(other.fuelType) + 1];
        std::strcpy(fuelType, other.fuelType);
        year = other.year;
        mileage = other.mileage;
    }
    std::cout << "Assign Operator Car apelat\n";
    return *this;
}

// Move Assignment Operator
Car& Car::operator=(Car&& other) noexcept {
    if (this != &other) {
        Vehicle::operator=(std::move(other)); // Mutarea partii de baza
        delete[] fuelType;

        fuelType = other.fuelType;
        other.fuelType = nullptr;
        year = other.year;
        mileage = other.mileage;
    }
    std::cout << "Move Assign Operator Car apelat\n";
    return *this;
}

// Destructor
Car::~Car() {
    std::cout << "Destructorul Car a fost apelat pentru " << model << "\n";
    delete[] fuelType;
}

// Metoda de afisare
void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Year: " << year << ", Mileage: " << mileage << ", Fuel: " << fuelType << "\n";
}
