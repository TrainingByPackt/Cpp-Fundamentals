#include <iostream>

// Define and declares the function.
// The parameter is taken by value: a new copy will be created.
// Changes inside the function will not be reflected in the value
// used when calling the function
void byvalue_age_in_5_years(int age) {
    // Age here is a new copy. We increment it by 5 but then it's lifetime terminates.
	age += 5;
    std::cout << "Age in 5 years: " << age << std::endl;
}

int main() {
	int age = 95;
	byvalue_age_in_5_years(age);
    // ag3 is not modified because it was accepted by value
	std::cout << "Current age: " << age; // Prints 95
}
