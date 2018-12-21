#include <currency.h>
#include <iostream>

// An account can contain many currencies, so we create a class template
template<typename Currency>
class Account {
public:
    // Inside the class we can use the Currency type
    Account(Currency amount) : balance(amount) {}

    // Since we want to accept any currency, we need a template
    // and to convert between the various currencies
    template<typename OtherCurrency>
    void addToBalance(OtherCurrency amount) {
        // The 'to()' function is defined in the 'currency.h' header
        // and converts between currencies
        balance.d_value += to<Currency>(amount).d_value;
    }

    // We don't want users to be able to access the balance and change it directly.
    // Because of this the balance is private, and we provide a method to access it.
    // Note: the method returns a copy, so the users can not modify the
    //       Account's balance by modifying the return value.
    Currency getBalance() const {
        return balance;
    }

private:
    Currency balance;
};

int main() {
    // Create an account
    Account<GBP> gbpAccount(GBP(1000));
    // Add different currencies
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;
    gbpAccount.addToBalance(EUR(100));
    std::cout << "+100 (EUR)" << std::endl;
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;
    // Or the same one
    gbpAccount.addToBalance(GBP(200));
    std::cout << "+200 (GBP)" << std::endl;
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;

    std::cout << "New balance" << std::endl;

    Account<EUR> eurAccount(EUR(2000));
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;
    eurAccount.addToBalance(GBP(400));
    std::cout << "+400 (GBP)" << std::endl;
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;
    eurAccount.addToBalance(USD(100));
    std::cout << "+100 (USD)" << std::endl;
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;
}
