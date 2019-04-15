#ifndef JOHNNY_MATHLIB_H
#define JOHNNY_MATHLIB_H

#include <array>

// Organize the functions inside two namespaces.
// All of johnny code will be under the johnny namespace, and all the mathlib code
// will be into the mathlib namespace
namespace johnny {
namespace mathlib {

// Overload distance so it is easy to use
float distance(float a, float b);
int distance(int a, int b);
// The point are taken by value because they are small.
// We define a default value for argument 'b' to be the origin.
float distance(std::array<float, 3> a, std::array<float, 3> b = {0, 0, 0});

float circumference(float radius);

// The array of locations is big, so we use a reference. Since we do not modify it,
// we also use const.
float total_walking_distance(const std::array<std::array<float, 3>, 10>& locations);

}
}

#endif
