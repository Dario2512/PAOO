#include "Car.hpp"
#include "Motorcycle.hpp"

int main() {
    std::cout << "\n=== Test: Instantiere obiecte ===\n";
    Car audiA3("Audi A3", 2010, 230000);
    Motorcycle yamahaR1("Yamaha R1", 1000);

    std::cout << "\n=== Test: Copy Constructor ===\n";
    Car audiCopy = audiA3;
    Motorcycle yamahaCopy = yamahaR1;

    std::cout << "\n=== Test: Move Constructor ===\n";
    Car audiMoved = std::move(audiA3);
    Motorcycle yamahaMoved = std::move(yamahaR1);

    std::cout << "\n=== Test: Destructor ===\n";
    return 0;
}
