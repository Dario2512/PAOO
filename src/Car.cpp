#include "Car.hpp"

Car::Car(const std::string& model, int year, double mileage)
    : model(model), year(year), mileage(mileage) {}

std::string Car::getModel() const {
    return model;
}

void Car::display() const {
    std::cout << "Car -> Model: " << model
              << ", Year: " << year
              << ", Mileage: " << mileage << " km\n";
}
