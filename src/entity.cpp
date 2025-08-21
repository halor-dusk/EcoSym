#include "../rsrc/entity.hpp"

Entity::Entity(std::vector<Entity *>* world, float x, float y, float w, float h)
 : world(world) {
    this->collider = { x, y, w, h };
    this->center = { x + w/2, y + h/2 };
    world->push_back(this);
}

bool Entity::checkCollision(Rectangle nextStep) {
    Rectangle check = (nextStep.x != NAN && nextStep.y != NAN) ? nextStep : this->collider;
    for (const Entity* entity : *this->world) {
        if (entity == this)
            continue; // self ignore

        if (CheckCollisionRecs(check, entity->collider))
            return true;
    }

    return false;
}
