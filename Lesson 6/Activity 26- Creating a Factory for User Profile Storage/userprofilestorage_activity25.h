#ifndef USER_PROFILE_STORAGE_H
#define USER_PROFILE_STORAGE_H

// Copied from Activity 25

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
        return UserProfile();
    }
};

#endif
