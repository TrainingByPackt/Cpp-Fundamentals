#include <stack>
#include <string>
#include <iostream>

struct RegistrationForm {
    std::string userName;
};

void processRegistration(RegistrationForm form) {
    std::cout << "Processing form for user: " << form.userName << std::endl;
}

void storeRegistrationForm(std::stack<RegistrationForm>& stack, RegistrationForm form) {
    // Add the form to the top of the stack
    stack.push(form);
    std::cout << "Pushed form for user " << form.userName << std::endl;
}

void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack) {
    // Process the top of the stack and then remove it
    while ( !stack.empty()) {
        processRegistration(stack.top());
        stack.pop();
    }
}

int main(){
    std::stack<RegistrationForm> registrationForms;

    storeRegistrationForm(registrationForms, RegistrationForm{"Alice"});
    storeRegistrationForm(registrationForms, RegistrationForm{"Bob"});
    storeRegistrationForm(registrationForms, RegistrationForm{"Charlie"});

    endOfDayRegistrationProcessing(registrationForms);
}
