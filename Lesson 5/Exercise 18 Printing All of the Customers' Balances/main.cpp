#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
int main(){
std::vector<int> numbers = {10, 34, 64, 97, 56, 43, 50, 89, 32, 5};

for (auto pos = numbers.begin(); pos != numbers.end(); ++pos){
    std::cout << "Balance: " << *pos << std::endl;
}
}
