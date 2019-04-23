#include <iostream>
#include <string>
#include <variant>

struct AtGate {
    int gate;
};

struct Taxi {
    int lane;
    int numPassengers;
};

struct Flying {
    float speed;
};

class Airplane {
    std::variant<AtGate, Taxi, Flying> state;
public:
    Airplane(int gate) : state(AtGate{gate}) {
        std::cout << "At gate " << gate << std::endl;
    }

    void startTaxi(int lane, int numPassengers) {
        if (!std::holds_alternative<AtGate>(state)) {
            std::cout << "Not at gate: the plane cannot start taxi to lane " << lane << std::endl;
            return;
        }
        std::cout << "Taxing to lane " << lane << std::endl;
        state = Taxi{lane, numPassengers};
    }

    void takeOff( float speed) {
        if (!std::holds_alternative<Taxi>(state)) {
            std::cout << "Not at lane: the plane cannot take off with speed " << speed << std::endl;
            return;
        }
        std::cout << "Taking off at speed " << speed << std::endl;
        state = Flying{speed};
    }

    void currentStatus() {
        AirplaneStateVisitor visitor;
        std::visit(visitor, state);
    }

    class AirplaneStateVisitor {
    public:
        void operator()(const AtGate& atGate) {
            std::cout <<"AtGate: "<< atGate.gate << std::endl;
        }

        void operator()(const Taxi& taxi) {
            std::cout <<"Taxi: lane "<< taxi.lane << " with " << taxi.
            numPassengers << " passengers" << std::endl;
        }

        void operator()(const Flying& flying) {
            std::cout <<"Flying: speed "<< flying.speed << std::endl;
        }
    };
};


int main()
{
    Airplane airplane(52);
    airplane.currentStatus();
    airplane.startTaxi(12, 250);
    airplane.currentStatus();
    airplane.startTaxi(13, 250);
    airplane.currentStatus();
    airplane.takeOff(800);
    airplane.currentStatus();
    airplane.takeOff(900);
}
