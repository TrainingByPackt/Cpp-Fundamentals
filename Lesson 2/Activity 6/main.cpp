// std::array<Type, Number of Elements> is defined in the array header
#include <array>
#include <iostream>

// The size of the arguments is small: take by value
int sum(int a, int b)
{
	return a + b;
}

// We need to modify the result, so we need to use non-const references for the arrays
int& getMaxOf(std::array<int, 10>& array1, std::array<int, 10>& array2, int index) {
	if (array1[index] >= array2[index]) {
		return array1[index];
	} else {
		return array2[index];
	}
}

int main() {
    // We pass by value, so we can use temporary values safely
    std::cout << "sum(2, 3) = " << sum(2, 3) << std::endl;

    std::array<int, 10> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> reversed = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "sorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << std::endl;

    // We want to modify the element, so we need to make sure we take the result as reference.
    // If we were to return the result as a value, when we modify it it will not propagate
    // to the original element
    int& element = getMaxOf(sorted, reversed, 0);
    std::cout << "Max: " << element << std::endl;
    element = 0;
    std::cout << "sorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << std::endl;
    std::cout << "The original value has been updated though the reference!" << std::endl;

    // Note: we are taking by value. This creates a new local copy, and changes to it will not modify
    // the original value
    int value = getMaxOf(sorted, reversed, 0);
    value = 10;
    std::cout << "sorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << std::endl;
    std::cout << "The original value has *not* been updated though the value!" << std::endl;
}
