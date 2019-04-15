#include <mathlib.h>

#include <array>
#include <iostream>

const float ENEMY_VIEW_RADIUS_METERS = 5;

int main() {
    std::array<float, 3> enemy1_location = {2, 2 ,0};
    std::array<float, 3> enemy2_location = {2, 4 ,0};

    float enemy_distance = johnny::mathlib::distance(enemy1_location, enemy2_location);
    float distance_from_center = johnny::mathlib::distance(enemy1_location);

    using johnny::mathlib::circumference;
    float view_circumference_for_enemy = circumference(ENEMY_VIEW_RADIUS_METERS);

    float total_distance = johnny::mathlib::total_walking_distance({
        enemy1_location,
        {2, 3, 0}, // y += 1
        {2, 3, 3}, // z += 3
        {5, 3, 3}, // x += 3
        {8, 3, 3}, // x += 3
        {8, 3, 2}, // z -= 1
        {2, 3, 2}, // x -= 6
        {2, 3, 1}, // z -= 1
        {2, 3, 0}, // z -= 1
        enemy2_location
    });

    std::cout << "The two enemies are " << enemy_distance << "m apart and can see for a circumference of "
              << view_circumference_for_enemy << "m. To go to from one to the other they need to walk "
              << total_distance << "m.";
}
