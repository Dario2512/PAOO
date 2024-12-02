#include "Car.hpp"
#include "Motorcycle.hpp"
#include "CarFleet.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

int main() {
    CarFleet fleet;

    // Adaugam vehicule folosind shared_ptr
    auto car1 = std::make_shared<Car>("Dacia Logan", 2010, 150000);
    auto car2 = std::make_shared<Car>("Ford Fiesta", 2015, 80000);
    fleet.addVehicle(car1);
    fleet.addVehicle(car2);

    // Adaugam vehicule folosind unique_ptr
    auto motorcycle1 = std::make_unique<Motorcycle>("Harley Davidson", 2020, 1000);
    fleet.addVehicle(std::move(motorcycle1));

    // Pornim thread pentru a testa accesul concurent
    std::thread writerThread1([](CarFleet& fleet) {
        auto car = std::make_shared<Car>("Shared Car 1", 2011, 20000);
        fleet.addVehicle(car);
    }, std::ref(fleet));

    std::thread writerThread2([](CarFleet& fleet) {
        auto motorcycle = std::make_unique<Motorcycle>("Unique Motorcycle 1", 2016, 500);
        fleet.addVehicle(std::move(motorcycle));
    }, std::ref(fleet));

    std::thread readerThread([](CarFleet& fleet) {
        std::cout << "Displaying fleet:\n";
        fleet.displayFleet(); 
    }, std::ref(fleet));

    writerThread1.join();
    writerThread2.join();
    readerThread.join();

    return 0;
}
