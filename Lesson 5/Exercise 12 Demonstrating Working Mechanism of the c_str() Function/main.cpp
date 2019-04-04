#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Construct a C-string being explicit about the null terminator
	const char charString[8] = {'C', '+', '+', ' ', '1', '0', '1', '\0'};
	
	// Construct a C-string from a literal string. The compiler
	// automatically adds the \0 at the end
	const char * literalString = "C++ Fundamentals";
	
	// Strings can be constructed from literal strings.
	std::string strString = literalString;
	
	const char *charString2 = strString.c_str();
	
	std::cout << charString << std::endl;
	std::cout << charString2 << std::endl;
}
