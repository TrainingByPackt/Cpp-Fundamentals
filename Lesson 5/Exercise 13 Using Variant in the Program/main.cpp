#include <iostream>
#include <string>
#include <variant>

using namespace std;

struct Visitor {
	void operator()(const std::string& value){
		std::cout << "a string: " << value << std::endl;
	}
	void operator()(const int& value){
		std::cout << "an int: " << value << std::endl;
	}
};
int main()
{
	std::variant<std::string, int> variant = 42;
	Visitor visitor;
	
	std::cout << "The variant contains ";
	std::visit(visitor, variant);
	
	variant = std::string("Hello world");
	std::cout << "The variant contains ";
	
	std::visit(visitor, variant);
}