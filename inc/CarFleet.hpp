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
    CarFleet() = default;

    // Destructor
    ~CarFleet() = default;

    // Interzicem copierea 
    CarFleet(const CarFleet&) = delete;          // Constructor de copiere
    CarFleet& operator=(const CarFleet&) = delete; // Operatorul de atribuire
    
    CarFleet(CarFleet&& other) noexcept {
        std::lock_guard<std::mutex> lock(other.mtx);
        fleet = std::move(other.fleet);         // Mutam flota
    }

    CarFleet& operator=(CarFleet&& other) noexcept {
        if (this != &other) {
            std::lock_guard<std::mutex> lock_this(mtx);
            std::lock_guard<std::mutex> lock_other(other.mtx);
            fleet = std::move(other.fleet);     // Mutam flota
        }
        return *this;
    }

    void addVehicle(const std::shared_ptr<Vehicle>& vehicle);

    void removeVehicleByModel(const std::string& model);

    std::shared_ptr<Vehicle> findVehicleByModel(const std::string& model);

    void displayFleet();
};
