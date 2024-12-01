#include "Car.hpp"
#include "Motorcycle.hpp"
#include "CarFleet.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

void addSharedCars(CarFleet& fleet) {
    // Adaugare masini folosind shared_ptr
    for (int i = 1; i <= 3; ++i) {
        auto car = std::make_shared<Car>("Shared Car " + std::to_string(i), 2010 + i, 20000 * i);
        fleet.addVehicle(car);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // sim process de 1sec
    }
}

void addUniqueMotorcycles(CarFleet& fleet) {
    // Adaugare motociclete folosind unique_ptr
    for (int i = 1; i <= 3; ++i) {
        auto motorcycle = std::make_unique<Motorcycle>("Unique Motorcycle " + std::to_string(i), 2015 + i, 5000 * i);
        fleet.addVehicle(std::move(motorcycle)); // transfer de ownership
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulare proces 1 sec
    }
}

void displayFleetContinuously(CarFleet& fleet) {
    // Afiseaza flota curenta de mai multe ori
    for (int i = 0; i < 5; ++i) {
        fleet.displayFleet();
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // ssimulare citire flota
    }
}

void countSharedPointers(CarFleet& fleet) {
    // Iteram prin flota si numaram referintele shared_ptr
    std::cout << "\n--- Counting shared_ptr references ---\n";
    fleet.displayFleet();
    std::cout << "Notă: Numarul de referinte active la shared_ptr este gestionat automat\n";
}

int main() {
    CarFleet fleet;

    // testare adaugare vehicule cu shared_ptr
    auto car1 = std::make_shared<Car>("Dacia Logan", 2010, 150000);
    auto car2 = std::make_shared<Car>("Ford Fiesta", 2015, 80000);
    fleet.addVehicle(car1);
    fleet.addVehicle(car2);

    // testare adaugare vehicule cu unique_ptr
    auto motorcycle1 = std::make_unique<Motorcycle>("Harley Davidson", 2020, 10000);
    fleet.addVehicle(std::move(motorcycle1));

    // testare cautare vehicul
    fleet.findVehicleByModel("Ford Fiesta");
    fleet.findVehicleByModel("Tesla Model 3"); // Inexistent
    fleet.findVehicleByModel("Harley Davidson");

    // testare stergere vehicul
    fleet.removeVehicleByModel("Dacia Logan");
    fleet.displayFleet();

    // pornire thread pentru multithreading
    std::thread writerThread1(addSharedCars, std::ref(fleet));   // Adaugare shared_ptr
    std::thread writerThread2(addUniqueMotorcycles, std::ref(fleet)); // Adaugare unique_ptr
    std::thread readerThread(displayFleetContinuously, std::ref(fleet)); // Citire flota

    writerThread1.join();
    writerThread2.join();
    readerThread.join();

    // Testare numar referinte shared_ptr
    countSharedPointers(fleet);

    return 0;
}
