#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "../entity.hpp"

class Creature : public Entity {
public:
    Vector2 velocity;
    float thinkTimer = 0;

    Creature(std::vector<Entity *>* world, float x, float y, float w, float h);

    virtual void draw();
    virtual void update(float deltaTime);

    Vector2 seekFood();
    void eat(Entity *entity);
    bool canBeEat(Entity *entity) const { return false; };
    float getNutrition() const;
private:
    int speed = 100,
        vision = 128,
        hungryFactor = 20;

    float thinkSpeed = 2.0f,
        hungry = 0.0f;
};

#endif
