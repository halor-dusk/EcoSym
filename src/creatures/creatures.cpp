#include "../../rsrc/creatures/creature.hpp"
#include "../../rsrc/math.hpp"
// #include <cstdio>

void Creature::draw() {
    // colliders
    DrawRectangleLines(this->collider.x, this->collider.y, this->collider.width, this->collider.height, WHITE);
    DrawCircleLines(this->collider.x + this->collider.width/2.0, this->collider.y + this->collider.height/2.0, this->vision, WHITE);
}

void Creature::update(float deltaTime) {
    // move
    Rectangle nextStep = this->collider;
    nextStep.x += this->velocity.x*deltaTime;
    nextStep.y += this->velocity.y*deltaTime;

    if (nextStep.x > 0 && nextStep.x + nextStep.width <= GetScreenWidth() && !this->checkCollision())
        this->collider.x = nextStep.x;
    if (nextStep.y > 0 && nextStep.y + nextStep.height <= GetScreenHeight() && !this->checkCollision())
        this->collider.y = nextStep.y;

    this->thinkTimer += deltaTime;
    if (this->thinkTimer >= this->thinkSpeed) {
        Vector2 direction = { random(-1.0, 1.0), random(-1.0, 1.0) };

        this->velocity.x = this->speed*direction.x;
        this->velocity.y = this->speed*direction.y;
        this->thinkTimer = 0;
    }
}
