#include <iostream>

struct UserProfile {};

struct UserId {};


class UserProfileStorage {
public:
    // This method is a pure virtual method, so the UserProfileStorage can not be instantiated
    virtual UserProfile getUserProfile(const UserId& id) const = 0;

    // We always need a virtual destructor for interfaces!
    // Hard to find errors happen otherwise
    virtual ~UserProfileStorage() = default;

protected:
    UserProfileStorage() = default;
    UserProfileStorage(const UserProfileStorage&) = default;
    UserProfileStorage& operator=(const UserProfileStorage&) = default;
};


// We derive from the interface and we implement all of the pure virtual
// methods, so this class can be instantiated
class UserProfileCache : public UserProfileStorage {

public:
    UserProfile getUserProfile(const UserId& id) const override {
        std::cout << "Retrieving profile from the cache" << std::endl;
        return UserProfile();
    }
};

class UserProfileDB : public UserProfileStorage {

public:
    UserProfile getUserProfile(const UserId& id) const override {
        std::cout << "Retrieving profile from the DB" << std::endl;
        return UserProfile();
    }
};
