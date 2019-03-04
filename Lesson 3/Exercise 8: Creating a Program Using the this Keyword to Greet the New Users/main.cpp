#include <iostream>

class PrintName {
    std::string name;
    
 public:
    void set_name(const std::string &name){
        this->name = name;
    }
    
    void print_name() {
        std::cout << this->name << "! Welcome to the C++ community :)" << std::endl;
    }

};

int main()
{
    PrintName object;
    object.set_name("Marco");
    object.print_name();
}
