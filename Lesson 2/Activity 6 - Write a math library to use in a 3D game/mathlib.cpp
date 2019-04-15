#include <mathlib.h>

#include <cmath>

// The definitions need to be in the same namespace as the declarations
namespace johnny {
namespace mathlib {

// Global definition of PI
const float PI = 3.14f;

float distance(float a, float b) {
    return b - a;
}

int distance(int a, int b) {
    return b - a;
}

// The default argument can be specified only once, so here we don't repeat it
float distance(std::array<float, 3> a, std::array<float, 3> b) {
    // distance = square root of ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    // std::pow(x, 2) == x^2
    return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2) + std::pow(b[2] - a[2], 2));
}

float circumference(float radius) {
    // Use the global variable PI
    return 2 * PI * radius;
}

float total_walking_distance(const std::array<std::array<float, 3>, 10>& locations) {
    float distance_walked_so_far = 0;
    // We keep summing the distance between a locations and the previous one.
    // we start at 1 because the first location (at index 0) has no previous location to compute the distance from.
    for(int current_location = 1; current_location < 10; current_location++) {
        int previous_location = current_location - 1;
        // We use the overload for points
        float current_distance = distance(locations[previous_location], locations[current_location]);
        distance_walked_so_far += current_distance;
    }
    return distance_walked_so_far;
}

}
}
