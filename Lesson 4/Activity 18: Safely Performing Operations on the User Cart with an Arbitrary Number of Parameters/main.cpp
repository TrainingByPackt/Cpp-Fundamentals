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

void replaceItem(Cart& cart, Item toRemove, Item toAdd) {
    removeItem(cart, toRemove);
    addItems(cart, {toAdd});
}

// This is a function which is used to call other functions.
// Action is the function to execute.
// Parameters is the ist of parameters to pass to the function, in addition to
// the cart.
// Parameter is a variadic template parameter pack: it can contain a group of types
// instead of a single type like regular type parameters.
template<typename Action, typename... Parameters>
// Note the ... after the type: we need to expand the parameter pack to use it.
// The compiler will complain otherwise!
void execute_on_user_cart(UserIdentifier user, Action action, Parameters&&... parameters) {
    if(isLoggedIn(user)) {
        Cart cart = getUserCart(user);
        // We expect Action to be a function, so we call it with the cart and the parameter!
        // Here we expand the expression containing the parameter pack.
        action(cart, std::forward<Parameters>(parameters)...);
    } else {
        std::cout << "The user is not logged in" << std::endl;
    }
}

int main() {
    Item toothbrush{1023, "Toothbrush"};
    Item toothpaste{1024, "Toothpaste"};

    UserIdentifier loggedInUser{0};
    // The user is logged in, we will add the items
    std::cout << "Replacing items if the user is logged in" << std::endl;
    execute_on_user_cart(loggedInUser, replaceItem, toothbrush, toothpaste);

}
/*

Output:

Replacing items if the user is logged in
Item removed
Items added

/*

When we call 'execute_on_user_cart' it gets expanded by the compiler like this:

// Action is a function pointer which takes a Cart and 2 Item and return a void
// The ref-ness of arg0 and arg1 is deduced with the rules we saw earlier.
// In this case it's deduced to non-const ref
void execute_on_user_cart(UserIdentifier user, void(*replaceItem)(Cart&, Item, Item), Item& arg0, Item& arg1) {
    if(isLoggedIn(user)) {
        Cart cart = getUserCart(user);
        // Note: the expression has been copy-pasted for each argument
        replaceItem(cart, std::forward<Item&>(arg0), std::forward<Item&>(arg1));
    } else {
        std::cout << "The user is not logged in" << std::endl;
    }
}

*/
