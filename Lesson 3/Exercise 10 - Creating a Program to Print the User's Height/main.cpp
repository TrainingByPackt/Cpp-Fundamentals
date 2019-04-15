#include <iostream>

class Height {
    double inches;

    public:
    
        Height(double value): inches(value) { }
    
        friend void print_feet(Height);
};

void print_feet(Height h){
    std::cout << "Your height in inches is: " << h.inches<< std::endl;
    std::cout << "Your height in feet is: " << h.inches * 0.083 << std::endl;
}


int main()
{
    Height h(83);
    print_feet(h);
}
