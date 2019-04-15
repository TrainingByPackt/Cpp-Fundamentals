#include <iostream>
#include <memory>
#include <userprofile_activity18.h>

class UserProfileStorageFactory {
public:
    // Note: we are creating the derived class in the body of the function
    std::unique_ptr<UserProfileStorage> create() const {
        return std::make_unique<UserProfileCache>();
    }
};


void getUserProfile(const UserProfileStorageFactory& storageFactory) {
    // The current function "owns" the memory for the UserProfileStorage
    // though the unique_ptr, but it doesn't know which instance of the
    // storage it is using. It could even change during run time.
    std::unique_ptr<UserProfileStorage> storage = storageFactory.create();
    UserId user;
    std::cout << "Retrieving user profile from the factory generated storage" << std::endl;
    storage->getUserProfile(user);
    // The storage is automatically destroyed
}


int main()
{
    UserProfileStorageFactory factory;
    getUserProfile(factory);
}
