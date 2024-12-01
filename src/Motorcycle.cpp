#include "Motorcycle.hpp"

Motorcycle::Motorcycle(const std::string& model, int year, double engineCapacity)
    : model(model), year(year), engineCapacity(engineCapacity) {}

std::string Motorcycle::getModel() const {
    return model;
}

void Motorcycle::display() const {
    std::cout << "Motorcycle -> Model: " << model
              << ", Year: " << year
              << ", Engine Capacity: " << engineCapacity << " cm³\n";
}
