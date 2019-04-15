#include <iostream>

class DataScienceDev {
    public:
        DataScienceDev(){
            std::cout << "Welcome to the Data Science Developer Community."
    << std::endl;
        }
};

class FutureCppDev {
    public:
        FutureCppDev(){
            std::cout << "Welcome to the C++ Developer Community." <<
    std::endl;
        }
};

class Student : public DataScienceDev, public FutureCppDev {
    public:
    Student(){
        std::cout << "Student is a Data Developer and C++ Developer."
    << std::endl;
    }
};

int main(){
    Student S1;
    return 0;
}
