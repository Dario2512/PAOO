#include "Car.hpp"

int main() {
    // Crearea unui obiect Car pt masina mea :)
    Car audiA3("Audi A3", 2010, 230000);
    audiA3.displayInfo();
    Car bmw320d("BMW 320d", 2008, 200000);
    bmw320d.displayInfo();

    // supraincarcarea operatorului "="
    Car altA3;
    altA3.displayInfo();
    altA3 = audiA3; // Apelul operatorului supraincarcat "="
    altA3.displayInfo();

    return 0;
}
