#ifndef PLANTS_HPP
#define PLANTS_HPP

#include "../entity.hpp"

class Plant : public Entity {
public:
    using Entity::Entity;

    virtual void draw();
    virtual void update(float deltaTime);
};

#endif
