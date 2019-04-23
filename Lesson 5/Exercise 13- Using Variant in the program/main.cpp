#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<std::string, int> variant = 42;
    std::cout << std::get<1>(variant) << std::endl;
    std::cout << std::get<int>(variant) << std::endl;
}
