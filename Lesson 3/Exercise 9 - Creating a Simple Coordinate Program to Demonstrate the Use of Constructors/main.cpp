#include <iostream>

class Coordinates {
    public:
    Coordinates(){
        std::cout << "Constructor called!" << std::endl;
    }
    
    ~Coordinates(){
        std::cout << "Destructor called!" << std::endl;
    }

};

int main()
{
    Coordinates c;
}
