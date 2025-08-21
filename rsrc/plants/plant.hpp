#ifndef PLANTS_HPP
#define PLANTS_HPP

#include "../entity.hpp"

class Plant : public Entity {
public:
    Plant(std::vector<Entity *>* world, float x, float y, float w, float h);

    virtual void draw();
    virtual void update(float deltaTime);

    virtual bool canBeEat(Entity * entity) const;
    float getNutriton() const;
private:
    int eatArea = 48;
};

#endif
