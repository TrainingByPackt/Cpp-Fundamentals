#include <iostream>

// The parameter is taken by reference.
// Changes inside the function will be reflected in the value of the caller
void byvalue_age_in_5_years(int& age) {
	age += 5;
}

int main() {
	int a = 95;
	byvalue_age_in_5_years(a);
	// a has been incremented by the function, because it operated on a reference
	// to the local variable
	std::cout << "Value: " << a; // Prints 100
}
