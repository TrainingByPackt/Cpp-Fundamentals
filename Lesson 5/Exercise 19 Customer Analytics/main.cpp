#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

struct UserAccount {
    int balance;
    int daysSinceRegistered;
};

void computeAnalytics(std::map<std::string, UserAccount>& accounts) {
    // Balance of accounts newer than 15 days, in descending order
    std::vector<UserAccount> newAccounts;
    std::transform(accounts.begin(), accounts.end(), std::back_inserter(newAccounts),
        [](const std::pair<std::string, UserAccount>& user) {
            return user.second;
        });


    auto newEnd = std::remove_if(newAccounts.begin(), newAccounts.end(),
        [](const UserAccount& account) {
            return account.daysSinceRegistered > 15;
        });
    newAccounts.erase(newEnd, newAccounts.end());

    std::sort(newAccounts.begin(), newAccounts.end(),
        [](const UserAccount& lhs, const UserAccount& rhs) {
            return lhs.balance > rhs.balance;
        });

    for(const UserAccount& account : newAccounts) {
        std::cout << account.balance << std::endl;
    }
}

int main()
{
    std::map<std::string, UserAccount> users = {
        {"Alice", UserAccount{500, 15}},
        {"Bob", UserAccount{1000, 50}},
        {"Charlie", UserAccount{600, 17}},
        {"Donald", UserAccount{1500, 4}}
    };
    computeAnalytics(users);
}
