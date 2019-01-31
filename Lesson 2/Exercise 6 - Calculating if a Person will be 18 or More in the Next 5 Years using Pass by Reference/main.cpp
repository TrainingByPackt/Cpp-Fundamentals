#include <iostream>

void byreference_age_in_5_years(int& age) {
    age += 5;
}


int main() {
    int age = 13;
    byreference_age_in_5_years(age);
    if (age >= 18) {
        std::cout << "Congratulations! " << std::endl;
    }
}
