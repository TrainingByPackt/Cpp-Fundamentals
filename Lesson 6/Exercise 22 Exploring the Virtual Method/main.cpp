#include <iostream>

class Vehicle {
public:
    virtual void turnOn(){
        std::cout<< "Vehicle: turn on" << std::endl;
    }
};

class Car : public Vehicle {
public:
    virtual void turnOn() {
        std::cout << "Car: turn on" << std::endl;
    }
};

void myTurnOn(Vehicle& vehicle) {
    std::cout << "Calling turnOn() on the vehicle reference" << std::endl;
    vehicle.turnOn();
}

int main() {
    Car car;
    myTurnOn(car);
}
