#include <iostream>

int main()
{
    unsigned count = 0;
    for(unsigned x = 1; x <= 30; x++){
        if (x%3 == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
}
