#include "raylib.h"
#include "rsrc/math.hpp"
#include "rsrc/entity.hpp"
#include "rsrc/plants/plant.hpp"
#include "rsrc/creatures/creature.hpp"
#include <ctime>

int main(void) {
    srand(time(0)); // create a seed to make random numbers
    InitWindow(800, 450, "Ecosym");
    std::vector<Entity *> world;
    Creature bunny(&world, random(0, GetScreenWidth() - 32), random(0, GetScreenHeight() - 32), 32, 32);
    Plant bush(&world, random(0, GetScreenWidth() - 32), random(0, GetScreenHeight() - 32), 32, 32);
    Plant bushb(&world, random(0, GetScreenWidth() - 32), random(0, GetScreenHeight() - 32), 32, 32);
    Plant bushc(&world, random(0, GetScreenWidth() - 32), random(0, GetScreenHeight() - 32), 32, 32);
    while (!WindowShouldClose()) {
        // draw
        BeginDrawing();
            ClearBackground(BLACK);
            for (Entity *entity : world)
                entity->draw();
        EndDrawing();
        // update
        float deltaTime = GetFrameTime();
        for (Entity *entity : world)
            entity->update(deltaTime);
    }

    CloseWindow();
}
