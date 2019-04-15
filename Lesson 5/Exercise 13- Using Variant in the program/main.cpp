#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<std::string, int> variant = 42;
        std::cout << get <1>(variant) << std::endl;
        std::cout << get <int>(variant) << std::endl;
}