#include <stack>

std::stack<RegistrationForm> registrationForms;
stack.push(form);
std::cout << “Pushed form for user “ << form.userName << std::endl;
while(not stack.empty()) {
    processRegistration(stack.top());
    stack.pop();
}

int main(){
    std::stack<RegistrationForm> registrationForms;
    storeRegistrationForm(registrationForms, RegistrationForm{“Alice”});
    storeRegistrationForm(registrationForms, RegistrationForm{“Bob”});
    storeRegistrationForm(registrationForms,
RegistrationForm{“Charlie”});
    endOfDayRegistrationProcessing(registrationForms);
}
