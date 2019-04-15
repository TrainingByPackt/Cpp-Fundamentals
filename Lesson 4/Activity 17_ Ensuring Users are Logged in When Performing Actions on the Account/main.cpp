#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct UserIdentifier {
    int userId = 0;
};

struct Item {
    int id = 0;
    std::string name;
};

// This allows the items to be compared, which is needed since we search
// inside the vector
bool operator==(const Item& lhs, const Item& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

struct Cart {
    // A vector is a sequence of items
    std::vector<Item> items;
};

bool isLoggedIn(const UserIdentifier& user) {
    // A real function could check the user session.
    // For simplicity we decide to use the user id.
    // Users with an even id are logged in, the ones with
    // an odd user id are logged out.
    return user.userId % 2 == 0;
}

Cart getUserCart(const UserIdentifier& user) {
    // A real function could look in the database what the user
    // added to the cart and return that.
    // For simplicity we return a cart which is always empty.
    return Cart();
}

void removeItem(Cart& cart, Item cartItem) {
    auto location = std::find(cart.items.begin(), cart.items.end(), cartItem);
    if (location != cart.items.end()) {
        cart.items.erase(location);
    }
    std::cout << "Item removed" << std::endl;
}

void addItems(Cart& cart, std::vector<Item> items) {
    cart.items.insert(cart.items.end(), items.begin(), items.end());
    std::cout << "Items added" << std::endl;
}

// This is a function which is used to call other functions.
// Action is the function to execute.
// Parameter is the parameter to pass to the function, in addition to
// the cart
template<typename Action, typename Parameter>
void execute_on_user_cart(UserIdentifier user, Action action, Parameter&& parameter) {
    if(isLoggedIn(user)) {
        Cart cart = getUserCart(user);
        // We expect Action to be a function, so we call it with the cart and the parameter!
        action(cart, std::forward<Parameter>(parameter));
    } else {
        std::cout << "The user is not logged in" << std::endl;
    }
}

int main() {
    struct Item toothbrush{1023, "Toothbrush"};
    struct Item toothpaste{1024, "Toothpaste"};

    UserIdentifier loggedInUser{0};
    // The user is logged in, we will add the items
    std::cout << "Adding items if the user is logged in" << std::endl;
    execute_on_user_cart(loggedInUser, addItems, std::vector<Item>({toothbrush, toothpaste}));

    UserIdentifier loggedOutUser{1};
    // The user is not logged in, we will not remove the item
    std::cout << "Removing item if the user is logged out" << std::endl;
    execute_on_user_cart(loggedOutUser, removeItem, toothbrush);
}

/*
    Output:

    Adding items if the user is logged in
    Items added
    Removing item if the user is logged out
    The user is not logged in
 */