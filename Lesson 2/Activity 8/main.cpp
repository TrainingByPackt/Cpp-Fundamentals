#include <iostream>

int square(int x) {
	return x * x;
}

float square(float x) {
	return x * x;
}

int main() {
    // The overload which takes float is called
	std::cout << square(1.5f) << std::endl;
    // The overload which takes int is called
	std::cout << square(1) << std::endl;
}
