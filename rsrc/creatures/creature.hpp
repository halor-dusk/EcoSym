#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "../entity.hpp"

class Creature : public Entity {
public:
    using Entity::Entity;

    Vector2 velocity;
    float thinkTimer = 0;

    virtual void draw();
    virtual void update(float deltaTime);
private:
    int speed = 100,
        vision = 128;

    float thinkSpeed = 2.5;
};

#endif
