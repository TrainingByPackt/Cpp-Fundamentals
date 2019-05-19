#include <iostream>

// first base class
class Vehicle {
    public:
    int getTankCapacity(){
        const int tankLiters = 10;
        std::cout << "The current tank capacity for your car is " << tankLiters << " Liters."<<std::endl;
        return tankLiters;
    }
};

// second base class
class CollectorItem {
    public:
      float getValue() {
          return 100;
      }
};

// Subclass derived from two base classes
class Ferrari250GT: protected Vehicle, public CollectorItem {
    public:
    Ferrari250GT() {
        std::cout << "Thank you for buying the Ferrari 250 GT with tank capacity " << getTankCapacity() << std::endl;
    }
};

int main()
{
    Ferrari250GT ferrari;
    std::cout << "The value of the Ferrari is " << ferrari.getValue() <<
    std::endl;

    /* Cannot call ferrari.getTankCapacity() because Ferrari250GT inherits from Vehicle with the protected specifier */
    return 0;
};
