#include "../rsrc/math.hpp"

Vector2 normalize(Vector2 position) {
    float magnitude = sqrt(position.x*position.x + position.y*position.y);
    // I would create a vector 2d structure to just use the tenary operator cuz the
    // RayLib vector2 does not have a constructpr but i dont want to...
    if (magnitude == 0) {
        return { 0, 0 };
    }

    return { position.x/magnitude, position.y/magnitude };
}

float random(float min, float max) {
    return min + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(max - min)));
}
