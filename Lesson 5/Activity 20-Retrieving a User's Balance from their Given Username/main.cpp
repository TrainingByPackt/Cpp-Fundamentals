#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    std::map<std::string, int> balances;
    balances.insert(std::make_pair("Alice",50));
    balances.insert(std::make_pair("Bob", 50));
    balances.insert(std::make_pair("Charlie", 50));

    auto donaldAccountPos = balances.find("Donald");
    bool hasAccount = (donaldAccountPos != balances.end());
    std::cout << "Donald has an account: " << std::boolalpha << hasAccount << std::endl;

    auto alicePosition = balances.find("Alice");
    std::cout << "Alice balance is: " << alicePosition->second << std::endl;
}
