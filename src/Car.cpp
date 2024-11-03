#include "Car.hpp"

// Constructor cu lista de init
Car::Car(const std::string &model, int year, double mileage)
    : model(model), year(year), mileage(mileage) {
    std::cout << "Constructorul Car a fost apelat pentru " << model << "\n";
}

// Constructor de copy
Car::Car(const Car &other)
    : model(other.model), year(other.year), mileage(other.mileage) {
    std::cout << "Constructorul de copiere a fost apelat pentru " << model << "\n";
}

// Destructor
Car::~Car() {
    std::cout << "Destructorul Car a fost apelat pentru: " << model << "\n";
}

// Supraincarcarea operatorului "="
Car& Car::operator=(const Car &other) {
    std::cout << "Operatorul de asignare a fost apelat\n";
    if (this != &other) { // Prevenire auto assign
        model = other.model;
        year = other.year;
        mileage = other.mileage;
    }
    return *this;
}

// Gettere
std::string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
double Car::getMileage() const { return mileage; }

// Setter
void Car::setMileage(double newMileage) { mileage = newMileage; }

// Metoda pentru afișarea info despre masina
void Car::displayInfo() const {
    std::cout << "Model: " << model << ", Year: " << year << ", Mileage: " << mileage << " km\n";
}
