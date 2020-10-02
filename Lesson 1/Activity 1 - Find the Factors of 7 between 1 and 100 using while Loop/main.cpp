#include <iostream>

int main()
{
//     unsigned i = 1;
//     while ( i <= 100) {
//         if (i%7 == 0) {
//             std::cout << i << std::endl;
//         }
//         i++;
//     }
    for(int i=0; i<100; i+=7){ //this will reduce the time complexity of the program.
        std::cout<< i << std::endl;
    }
   

}
