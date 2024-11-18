#include "Car.hpp"
#include "Motorcycle.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== Test: Instantiere obiecte ===\n";
    Car audiA3("Audi A3", 2010, 230000, "Diesel");
    Motorcycle yamahaR1("Yamaha R1", 1000, "V4");

    audiA3.displayInfo();
    yamahaR1.displayInfo();

    std::cout << "\n=== Test: Copy Constructor ===\n";
    Car audiCopy = audiA3; 
    Motorcycle yamahaCopy = yamahaR1; 

    audiCopy.displayInfo();
    yamahaCopy.displayInfo();

    std::cout << "\n=== Test: Move Constructor ===\n";
    Car audiMoved = std::move(audiA3); 
    Motorcycle yamahaMoved = std::move(yamahaR1); 

    audiMoved.displayInfo();
    yamahaMoved.displayInfo();

    // Obiectele originale sunt acum goale adica mutate
    std::cout << "\n=== Test: Obiectele originale dupa mutare ===\n";
    audiA3.displayInfo(); // Ar trebui sa afiseze model nullptr
    yamahaR1.displayInfo(); // Ar trebui sa afiseze model nullptr

    std::cout << "\n=== Test: Operator de asignare (Copy Assignment) ===\n";
    Car fordFocus("Ford Focus", 2015, 150000, "Petrol");
    fordFocus = audiCopy; 
    fordFocus.displayInfo();

    Motorcycle kawasakiNinja("Kawasaki Ninja", 600, "Inline");
    kawasakiNinja = yamahaCopy; 
    kawasakiNinja.displayInfo();

    std::cout << "\n=== Test: Operator de asignare (Move Assignment) ===\n";
    fordFocus = std::move(audiMoved); 
    kawasakiNinja = std::move(yamahaMoved); 

    fordFocus.displayInfo();
    kawasakiNinja.displayInfo();

    // Verificam din nou obiectele mutate
    std::cout << "\n=== Test: Obiectele mutate dupa asignare ===\n";
    audiMoved.displayInfo(); // Ar trebui sa afiseze model nullptr
    yamahaMoved.displayInfo(); // Ar trebui sa afiseze model nullptr

    std::cout << "\n=== Test: Destructor ===\n";
    return 0;
}
