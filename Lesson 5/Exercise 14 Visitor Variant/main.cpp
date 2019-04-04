#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for(auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << "The number is: " << *rit << std::endl;
    }
}