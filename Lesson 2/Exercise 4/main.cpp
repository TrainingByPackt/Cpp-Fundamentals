#include <iostream>

// Define and declares the function.
// The parameter is taken by value: a new copy will be created.
// Changes inside the function will not be reflected in the value
// used when calling the function
void byvalue_age_in_5_years(int age) {
    // Age here is a new copy. We increment it by 5 but then it's lifetime terminates.
	age += 5;
}

int main() {
	int a = 95;
	byvalue_age_in_5_years(a);
    // a is not modified because it was accepted by value
	std::cout << "Value: " << a; // Prints 95
}
