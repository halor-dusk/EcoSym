#include "../rsrc/math.hpp"
#include <cmath>

Vector2 normalize(Vector2 v) {
    float magnitude = sqrt(v.x*v.x + v.y*v.y);
    // I would create a vector 2d structure to just use the tenary operator cuz the
    // RayLib vector2 does not have a constructpr but i dont want to...
    if (magnitude < 0.001)
        return { 0, 0 };

    return { v.x/magnitude, v.y/magnitude };
}

float magnitude(Vector2 v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

float random(float min, float max) {
    return min + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(max - min)));
}
