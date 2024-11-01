#include "Car.h"

int main() {
    // Crearea unui obiect Car pt masina mea
    Car audiA3("Audi A3", 2010, 230000);
    audiA3.displayInfo();

    // supraincarcarea operatorului "="
    Car altAudi;
    altAudi = audiA3; // Apelul operatorului supraincarcat "="
    altAudi.displayInfo();

    return 0;
}
