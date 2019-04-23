#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> accounts;
    for(std::size_t i = 0; i < accounts.size(); i++) {
        accounts[i] = i;
    }

    accounts.front() = 100;
    accounts.back() = 200;

    std::cout << "Elements:";
    for(int& account: accounts) {
        std::cout << " " << account;
    }
    std::cout << std::endl;
}
