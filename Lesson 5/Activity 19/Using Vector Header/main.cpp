#include <iostream>
#include <vector>

using namespace std;

int main()
{
    array<int,10> balances;
    for (int i=0; i < balances.size(); ++i){
        balances[i] = 0;
        balances.front() += 100;
     balances.back() += 100;
    }
    
    std::cout << balances.front() << std::endl;
    std::cout << balances.back() << std::endl;
}
