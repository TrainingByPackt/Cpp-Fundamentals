#include <iostream>

// The parameter is taken by reference.
// Changes inside the function will be reflected in the value of the caller
bool byreference_can_vote(int& age) {
    if (age >= 18) {
        std::cout << "Congratulations! You are eligible to vote for your nation." << std::endl;
        return true;
    } else {
        int reqAge = 18;
        int yearsToGo = reqAge-age;
        std::cout << "No worries, just "<< yearsToGo << " more years to go." << std::endl;
        age = reqAge;
        return false;
    }
}

int main() {
    int age = 0;
    std::cout << "Please enter your age:";
    std::cin >> age;
    if (!byreference_can_vote(age)) {
        // a has been incremented by the function, because it operated on a reference
        // to the local variable
        std::cout << "The age at which you can vote: " << age << std::endl;
    }
}
