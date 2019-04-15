#include <iostream>

int main()
{
    unsigned i = 1;
    while ( i <= 100) {
        if (i%7 == 0) {
            std::cout << i << std::endl;
        }
        i++;
    }

}