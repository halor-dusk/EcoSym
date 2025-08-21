#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"
#include <cmath>
#include <vector>

enum EntityName {
    UNDEFINED,
    BUNNY,
    BUSH
};

class Entity {
public:
    Rectangle collider;
    Vector2 center;

    std::vector<Entity *>* world;

    Entity() {}
    Entity(std::vector<Entity *>* world, float x, float y, float w, float h);

    virtual void draw() = 0;
    virtual void update(float deltaTime) = 0;

    bool checkCollision(Rectangle nextStep = { NAN, NAN });
    virtual bool canBeEat(Entity *entity) const = 0;
    float getNutrition() const { return nutrition; };
protected:
    float nutrition;
};
#endif
