#include <iostream>

class AddX {
  public:
    AddX(int x) : x(x) {}
    int operator() (int y) { return x + y; }
 
  private:
    int x;
};

int main() {
    AddX add10(10);
    std::cout << add10(1) << std::endl;
}
