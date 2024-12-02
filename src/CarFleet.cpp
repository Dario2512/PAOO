#include "CarFleet.hpp"
#include <algorithm>
#include <memory>

void CarFleet::addVehicle(const std::shared_ptr<Vehicle>& vehicle) {
    std::lock_guard<std::mutex> lock(mtx);
    fleet.push_back(vehicle);
    std::cout << "Vehicle added to fleet: ";
    vehicle->display();
    std::cout << "Number of shared_ptr references: " << vehicle.use_count() << "\n";
}

void CarFleet::removeVehicleByModel(const std::string& model) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::remove_if(fleet.begin(), fleet.end(),
        [&model](const std::shared_ptr<Vehicle>& vehicle) {
            return vehicle->getModel() == model;
        });
    if (it != fleet.end()) {
        fleet.erase(it, fleet.end());
        std::cout << "Vehicle with model '" << model << "' removed from fleet.\n";
    } else {
        std::cout << "Model '" << model << "' not found in fleet.\n";
    }
}

std::shared_ptr<Vehicle> CarFleet::findVehicleByModel(const std::string& model) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::find_if(fleet.begin(), fleet.end(),
        [&model](const std::shared_ptr<Vehicle>& vehicle) {
            return vehicle->getModel() == model;
        });

    if (it != fleet.end()) {
        std::cout << "Vehicle with model '" << model << "' found:\n";
        (*it)->display();
        std::cout << "Number of shared_ptr references: " << (*it).use_count() << "\n";
        return *it;
    }

    std::cout << "Model '" << model << "' not found in fleet.\n";
    return nullptr;
}

void CarFleet::displayFleet() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "\nCurrent fleet:\n";
    for (const auto& vehicle : fleet) {
        vehicle->display();
        std::cout << "Number of shared_ptr references: " << vehicle.use_count() << "\n";
    }
}
