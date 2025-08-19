#include "../rsrc/entity.hpp"

Entity::Entity(std::vector<Entity *>* world, float x, float y, float w, float h)
 : world(world) {
    this->collider = { x, y, w, h };
    world->push_back(this);
}

bool Entity::checkCollision() {
    for (const Entity* entity : *this->world) {
        if (entity == this)
            continue; // self ignore

        if (CheckCollisionRecs(this->collider, entity->collider))
            return true;
    }

    return false;
}
