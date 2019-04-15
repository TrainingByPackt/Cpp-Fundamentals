#include <array>
#include <string>
#include <iostream>

class UserAccount {
public:
    UserAccount(int id, std::string email): userId(id), email(email) {}

    // Serialize an user account to bytes
    static std::array<char, 100> serialize(const UserAccount& account);

    // Construct an user account from bytes
    static UserAccount deserialize(const std::array<char, 100>& blob);

    // Print the UserAccount instance
    friend std::ostream& operator<<(std::ostream& os, const UserAccount& account);

private:
    int userId;
    std::string email;
};
