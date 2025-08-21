#include "../../rsrc/plants/plant.hpp"
#include <raylib.h>

Plant::Plant(std::vector<Entity *>* world, float x, float y, float w, float h)
: Entity(world, x, y, w, h) {
    this->nutrition = 0.6;
}

void Plant::draw() {
    DrawRectangleLines(this->collider.x, this->collider.y, this->collider.width, this->collider.height, GREEN);
}

void Plant::update(float deltaTime) {

}

bool Plant::canBeEat(Entity *entity) const {
    return CheckCollisionCircleRec({ this->collider.x, this->collider.y }, this->eatArea, entity->collider);
}
