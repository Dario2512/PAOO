#pragma once
#include "Vehicle.hpp"
#include <vector>
#include <memory>
#include <mutex>

class CarFleet {
private:
    std::vector<std::shared_ptr<Vehicle>> fleet; // gestioneaza vehicule generice
    std::mutex mtx;

public:
    void addVehicle(const std::shared_ptr<Vehicle>& vehicle);

    void removeVehicleByModel(const std::string& model);

    std::shared_ptr<Vehicle> findVehicleByModel(const std::string& model);

    void displayFleet();
};
