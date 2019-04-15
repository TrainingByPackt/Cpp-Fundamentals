#include <iostream>

// global variables accessible by the whole file.
// Since we don't want to modify them, we mark them with const.
const int POSITION = 10;
const int ALREADY_COMPUTED = 3;

// Define and declare the function
void print_tenth_fibonacci() {
    // Local variables.
    // They don't have to be defined at the top of the function!
	int n_1 = 1;
	int n_2 = 0;
	int current = n_1 + n_2;
    // We can access the global variables from inside the function
	for(int i = ALREADY_COMPUTED; i <= POSITION; ++i) {
		current = n_1 + n_2;
		n_2 = n_1;
		n_1 = current;
	}
 	std::cout << current << std::endl;
}

int main() {
	print_tenth_fibonacci();
}
