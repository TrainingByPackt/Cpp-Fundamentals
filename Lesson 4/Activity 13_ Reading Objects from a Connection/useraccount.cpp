#include <useraccount.h>
#include <sstream>
#include <algorithm>

std::array<char, 100> UserAccount::serialize(const UserAccount& account) {
    // In a real program we would use a library which offers tools for serializing
    // types to binary.

    // In this case we are encoding the types into a string and converting that to the array
    constexpr size_t size = 100;
    std::array<char, size> blob;

    // Create a stream similar to the standard output, but in memory
    std::ostringstream oss;
    // Write the UserAccount fields there
    oss << account.userId;
    oss << ' ';
    oss << account.email;

    std::string serialized = oss.str();
    // Copy the data in the stream into the blob of bytes we want to return
    // We use std::min to be sure not to copy more items then the blob can contain.
    auto remaining = std::copy_n(serialized.cbegin(), std::min(serialized.length(), size), blob.begin());

    // Fill the part of the blob which was not already fille with the fields, so that we don't leave any
    // part of the blob uninitialized.
    std::fill(remaining, blob.end(), ' ');
    return blob;
}

UserAccount UserAccount::deserialize(const std::array<char, 100>& blob) {
    // Read the content of the blob into a string
    std::string content(blob.cbegin(), blob.cend());
    // Create a stream similar to stdin, but in memory, providing the content we stored in the string
    std::istringstream iss(content);

    // Read the user id
    int userId = 0;
    iss >> userId;

    // Read the email
    std::string email;
    iss >> email;

    // Create the new user account
    return UserAccount(userId, email);
}

std::ostream& operator<<(std::ostream& os, const UserAccount& account)
{
    os << "userId: " << account.userId << " email: " << account.email;
    return os;
}
