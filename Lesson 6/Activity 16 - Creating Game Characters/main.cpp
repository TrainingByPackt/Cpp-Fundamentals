#include <string>
#include <iostream>

struct Position {
    // Fields to describe the position go here
    std::string positionIdentifier;
};

class Character {
public:
    void moveTo(Position newPosition) {
        position = newPosition;
        std::cout << "Moved to position " << newPosition.positionIdentifier << std::endl;
    }
private:
    Position position;
};


class Spell {
public:
    Spell(std::string name) : d_name(name) {}

    std::string name() const {
        return d_name;
    }
private:
    std::string d_name;
};


// Hero inherits publicly from Character: it has
// all the public member of the Character class.
class Hero : public Character {
public:
    void cast(Spell spell) {
        // Cast the spell
        std::cout << "Casting spell " << spell.name() << std::endl;
    }
};


// Enemy inherits publicly from Character, like Hero
class Enemy : public Character {
public:
    void swingSword() {
        // Swing the sword
        std::cout << "Swining sword" << std::endl;
    }
};


int main()
{
    Position position{"Enemy castle"};
    Hero hero;
    Enemy enemy;

    // We call moveTo on Hero, which calls the method inherited
    // from the Character class
    hero.moveTo(position);
    enemy.moveTo(position);

    // We can still use the Hero and Enemy methods
    hero.cast(Spell("fireball"));
    enemy.swingSword();
}
