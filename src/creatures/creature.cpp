#include "../../rsrc/creatures/creature.hpp"
#include "../../rsrc/math.hpp"
#include <cstdio>
#include <raylib.h>

Creature::Creature(std::vector<Entity *>* world, float x, float y, float w, float h)
: Entity(world, x, y, w, h){
    this->nutrition = 0;
}

void Creature::draw() {
    // colliders
    DrawRectangleLines(this->collider.x, this->collider.y, this->collider.width, this->collider.height, WHITE);
    DrawCircleLines(this->center.x, this->center.y, this->vision, WHITE);
}

void Creature::update(float deltaTime) {
    this->thinkTimer += deltaTime;

    if (this->thinkTimer >= this->thinkSpeed) {
        Vector2 direction = normalize({ random(-1.0, 1.0), random(-1.0, 1.0) });

        printf("***Creature***\n");

        if (this->hungry > 0.75) {
            Vector2 foodPos = this->seekFood();

            if (!std::isnan(foodPos.x) && !std::isnan(foodPos.y)) { // found food
                Vector2 foodDist = foodPos - this->center;
                direction = normalize(foodDist);
            }

            printf("Closest food: %.0f x, %.0f y\n", foodPos.x, foodPos.y);
        }

        // Debug
        printf("Direction: %.2f x, %.2f y\n", direction.x, direction.y);
        printf("Hungry: %.2f \n", this->hungry);

        this->velocity = direction*this->speed;
        this->thinkTimer = 0;
    }

    // move
    Vector2 deltaVelocity = this->velocity*deltaTime;
    // simulate next step
    Rectangle nextStep = this->collider;
    nextStep.x += deltaVelocity.x;
    if (nextStep.x < 0 || nextStep.x + nextStep.width >= GetScreenWidth() || this->checkCollision(nextStep)) {
        this->velocity.x = 0;
        deltaVelocity.x = 0;
        // avoid problems with simulation
        nextStep.x = this->collider.x;
    }

    nextStep.y += deltaVelocity.y;
    if (nextStep.y < 0 || nextStep.y + nextStep.height >= GetScreenHeight() || this->checkCollision(nextStep)) {
        this->velocity.y = 0;
        deltaVelocity.y = 0;
    }

    // update collider and center
    this->collider.x += deltaVelocity.x;
    this->collider.y += deltaVelocity.y;
    this->center += deltaVelocity;

    if (hungry < 1) {
        float hungryStep = deltaTime/this->hungryFactor;
        this->hungry += hungryStep < 1.0f ? hungryStep : 1.0f;
    }
}

Vector2 Creature::seekFood() {
    Vector2 closestFoodPos = { NAN, NAN };
    float closestFoodDist = NAN;

    for (Entity *entity : *this->world) {
        if (entity == this)
            continue; // self ignore

        this->eat(entity);

        if (CheckCollisionCircleRec(this->center, this->vision, entity->collider)) {
            if (std::isnan(closestFoodPos.x)) { // food not found yet
                closestFoodPos = entity->center;
                closestFoodDist = magnitude(entity->center - this->center); // get the magnitude of end - start (food and creature)
                continue;
            }

            float entityDist = magnitude(entity->center - this->center);
            if (closestFoodDist > entityDist) {
                closestFoodPos = entity->center;
                closestFoodDist = entityDist;
            }
        }
    }

    return closestFoodPos;
}

void Creature::eat(Entity *entity) {
    if (entity->canBeEat(this)) {
        this->hungry -= entity->getNutrition();
        if (this->hungry < 0.0f)
            this->hungry = 0.0f;
    }
}
