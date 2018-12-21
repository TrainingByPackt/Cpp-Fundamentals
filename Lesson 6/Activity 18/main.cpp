#include <iostream>
#include <userprofile.h>

void fetchUserProfile(const UserProfileStorage& storage) {
    UserId user;
    // We don't know the run-time type of storage, but the right
    // method is going to be called because it's virtual
    UserProfile userProfile = storage.getUserProfile(user);
}

UserProfileStorage& selectStorage(UserProfileCache& cache, UserProfileDB& db) {
    // Try changing this value!
    bool isCacheReady = true;
    if (isCacheReady) {
        // We can bind a reference of UserProfileCache to UserProfileStorage
        // because the first derives publicly from the latter
        return cache;
    } else {
        return db;
    }
}


int main()
{
    UserProfileCache cache;
    UserProfileDB db;
    // The storage to use is picked at run time
    UserProfileStorage& storage = selectStorage(cache, db);
    fetchUserProfile(storage);
}
