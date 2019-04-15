#include <string>
#include <iostream>

struct EUBankAccount {
    std::string IBAN;
    int amount;
};


struct UKBankAccount {
    std::string sortNumber;
    std::string accountNumber;
    int amount;
};

// We want to work with different bank account types, so we need to use a template
template<typename BankAccount>
int getMaxAmount(const BankAccount& acc1, const BankAccount& acc2) {
    // All bank accounts have an 'amount' field, so we can access it safely
    if (acc1.amount > acc2.amount) {
        return acc1.amount;
    } else {
        return acc2.amount;
    }
}


int main() {
    EUBankAccount euAccount1{"IBAN1", 1000};
    EUBankAccount euAccount2{"IBAN2", 2000};
    std::cout << "The greater amount between Eu accounts is " << getMaxAmount(euAccount1, euAccount2) << std::endl;

    UKBankAccount ukAccount1{"SORT1", "ACCOUNT_NUM1", 2500};
    UKBankAccount ukAccount2{"SORT2", "ACCOUNT_NUM2", 1500};
    std::cout << "The greater amount between Uk accounts is " << getMaxAmount(ukAccount1, ukAccount2) << std::endl;
}

/*
    Output:

    The greater amount between Eu accounts is 2000
    The greater amount between Uk accounts is 2500

 */

/*
Expanded code for UKBankAccount:

int getMaxAmount(const UKBankAccount& acc1, const UKBankAccount& acc2) {
    if (acc1.amount > acc2.amount) {
        return acc1.amount;
    } else {
        return acc2.amount;
    }
}

*/
