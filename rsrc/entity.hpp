#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"
#include <vector>

enum EntityName {
    UNDEFINED,
    BUNNY,
    BUSH
};

class Entity {
public:
    Rectangle collider;
    std::vector<Entity *>* world;

    Entity(std::vector<Entity *>* world, float x, float y, float w, float h);

    virtual void draw() = 0;
    virtual void update(float deltaTime) = 0;

    bool checkCollision();
};
#endif
