#include <iostream>
using namespace std;

int main()
{
    int foo[3][3];
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < x-1; y++){
            foo[x][y] = x + y;
        }
    }

    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            cout << "foo[" << x << "][" << y << "]: " << x + y <<endl;
        }
    }

}
