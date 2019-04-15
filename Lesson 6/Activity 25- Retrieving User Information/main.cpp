#include <iostream>


struct UserProfile {};
struct UserId {};

class UserProfileStorage {
    public:
      virtual UserProfile getUserProfile(const UserId& id) const = 0;
    
      virtual ~UserProfileStorage() = default;
    
    protected:
      UserProfileStorage() = default;
      UserProfileStorage(const UserProfileStorage&) = default;
      UserProfileStorage& operator=(const UserProfileStorage&) = default;
};

class UserProfileCache : public UserProfileStorage {
    public:
      UserProfile getUserProfile(const UserId& id) const override {
      std::cout << "Getting the user profile from the cache" << std::endl;
      return UserProfile(); }
};
void exampleOfUsage(const UserProfileStorage& storage) {
    UserId user;
    std::cout << "About to retrieve the user profile from the storage"
<<std::endl;
    UserProfile UserProfile = storage.getUserProfile(user);
}

int main()
{
    UserProfileCache cache;
    exampleOfUsage (cache);
}